/*
 * @lc app=leetcode id=113 lang=cpp
 *
 * [113] Path Sum II
 *
 * https://leetcode.com/problems/path-sum-ii/description/
 *
 * algorithms
 * Medium (43.30%)
 * Likes:    1225
 * Dislikes: 42
 * Total Accepted:    277.8K
 * Total Submissions: 639.5K
 * Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,5,1]\n22'
 *
 * Given a binary tree and a sum, find all root-to-leaf paths where each path's
 * sum equals the given sum.
 * 
 * Note: A leaf is a node with no children.
 * 
 * Example:
 * 
 * Given the below binary tree and sum = 22,
 * 
 * 
 * ⁠     5
 * ⁠    / \
 * ⁠   4   8
 * ⁠  /   / \
 * ⁠ 11  13  4
 * ⁠/  \    / \
 * 7    2  5   1
 * 
 * 
 * Return:
 * 
 * 
 * [
 * ⁠  [5,4,11,2],
 * ⁠  [5,8,4,5]
 * ]
 * 
 * 
 */

#include<vector>
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> path;
        DFS(root, sum, path, res);
        return res;
    }
    void DFS(TreeNode* node, int target, vector<int>& path, vector<vector<int>>& res) {
        if (node==NULL) return;

        path.push_back(node->val);
        if (node->left==NULL && node->right==NULL) {
            if (node->val==target)
                res.push_back(path);
        }
        else {
            // path.push_back(node->val);
            DFS(node->left, target-node->val, path, res);
            DFS(node->right, target-node->val, path, res);
        }
        path.pop_back();
    }
};
// @lc code=end

