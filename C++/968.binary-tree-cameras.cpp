/*
 * @lc app=leetcode id=968 lang=cpp
 *
 * [968] Binary Tree Cameras
 *
 * https://leetcode.com/problems/binary-tree-cameras/description/
 *
 * algorithms
 * Hard (42.00%)
 * Likes:    3607
 * Dislikes: 43
 * Total Accepted:    86.1K
 * Total Submissions: 193.1K
 * Testcase Example:  '[0,0,null,0,0]'
 *
 * You are given the root of a binary tree. We install cameras on the tree
 * nodes where each camera at a node can monitor its parent, itself, and its
 * immediate children.
 * 
 * Return the minimum number of cameras needed to monitor all nodes of the
 * tree.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [0,0,null,0,0]
 * Output: 1
 * Explanation: One camera is enough to monitor all nodes if placed as shown.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [0,0,null,0,null,0,null,null,0]
 * Output: 2
 * Explanation: At least two cameras are needed to monitor all nodes of the
 * tree. The above image shows one of the valid configurations of camera
 * placement.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [1, 1000].
 * Node.val == 0
 * 
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int minCameraCover(TreeNode* root) {
        if (!root->left && !root->right) return 1;
        
        int ans = 0;
        int val = DFS(root, ans);
        if (val == 0) return ans + 1;
        else return ans;
    }
    
    int DFS(TreeNode* root, int& ans) {
        if (!root) return 2;
        
        int left = DFS(root->left, ans);
        int right = DFS(root->right, ans);
        
        if (left==0 || right==0) {
            ans += 1;
            return 1;
        }
        if (left==1 || right==1) return 2;
        return 0;     
};
// @lc code=end

