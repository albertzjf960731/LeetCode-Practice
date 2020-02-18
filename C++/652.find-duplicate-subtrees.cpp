/*
 * @lc app=leetcode id=652 lang=cpp
 *
 * [652] Find Duplicate Subtrees
 *
 * https://leetcode.com/problems/find-duplicate-subtrees/description/
 *
 * algorithms
 * Medium (48.63%)
 * Likes:    1030
 * Dislikes: 187
 * Total Accepted:    52K
 * Total Submissions: 107K
 * Testcase Example:  '[1,2,3,4,null,2,4,null,null,4]'
 *
 * Given a binary tree, return all duplicate subtrees. For each kind of
 * duplicate subtrees, you only need to return the root node of any one of
 * them.
 * 
 * Two trees are duplicate if they have the same structure with same node
 * values.
 * 
 * Example 1: 
 * 
 * 
 * ⁠       1
 * ⁠      / \
 * ⁠     2   3
 * ⁠    /   / \
 * ⁠   4   2   4
 * ⁠      /
 * ⁠     4
 * 
 * 
 * The following are two duplicate subtrees:
 * 
 * 
 * ⁠     2
 * ⁠    /
 * ⁠   4
 * 
 * 
 * and
 * 
 * 
 * ⁠   4
 * 
 * Therefore, you need to return above trees' root in the form of a list.
 */
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// @lc code=start
class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, vector<TreeNode*>> hash_map;
        vector<TreeNode*> res;
        serialize(root, hash_map);
        
        for (auto it=hash_map.begin(); it!=hash_map.end(); it++)
            if (it->second.size()>1) 
                res.push_back(it->second[0]);
        return res;
    }
private:
    string serialize(TreeNode* node, unordered_map<string, vector<TreeNode*>>& hash_map) {
        if (!node) return "";
        string s = "(" + serialize(node->left,hash_map) + to_string(node->val) + serialize(node->right, hash_map) + ")";
        hash_map[s].push_back(node);
        return s;
    }
};
// @lc code=end

