/*
 * @lc app=leetcode id=257 lang=cpp
 *
 * [257] Binary Tree Paths
 *
 * https://leetcode.com/problems/binary-tree-paths/description/
 *
 * algorithms
 * Easy (48.85%)
 * Likes:    1278
 * Dislikes: 85
 * Total Accepted:    275.9K
 * Total Submissions: 564.3K
 * Testcase Example:  '[1,2,3,null,5]'
 *
 * Given a binary tree, return all root-to-leaf paths.
 * 
 * Note: A leaf is a node with no children.
 * 
 * Example:
 * 
 * 
 * Input:
 * 
 * ⁠  1
 * ⁠/   \
 * 2     3
 * ⁠\
 * ⁠ 5
 * 
 * Output: ["1->2->5", "1->3"]
 * 
 * Explanation: All root-to-leaf paths are: 1->2->5, 1->3
 * 
 */

/**
 * Definition for a binary tree node.
 */
#include<string>
#include<vector>
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (root==NULL) return res;
        
        string path{to_string(root->val)};
        DFS(root, path, res);
        return res;
    }
    
    void DFS(TreeNode* node, string path, vector<string>& res) {
        if (node->left==NULL && node->right==NULL) {
            res.push_back(path);
            return;
        }
        if (node->left)
            DFS(node->left, path+"->"+to_string(node->left->val), res);
        if (node->right)
            DFS(node->right, path+"->"+to_string(node->right->val), res);
    }
};
// @lc code=end

