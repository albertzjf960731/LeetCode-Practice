/*
 * @lc app=leetcode id=226 lang=cpp
 *
 * [226] Invert Binary Tree
 *
 * https://leetcode.com/problems/invert-binary-tree/description/
 *
 * algorithms
 * Easy (61.46%)
 * Likes:    2496
 * Dislikes: 39
 * Total Accepted:    413.1K
 * Total Submissions: 671.7K
 * Testcase Example:  '[4,2,7,1,3,6,9]'
 *
 * Invert a binary tree.
 * 
 * Example:
 * 
 * Input:
 * 
 * 
 * ⁠    4
 * ⁠  /   \
 * ⁠ 2     7
 * ⁠/ \   / \
 * 1   3 6   9
 * 
 * Output:
 * 
 * 
 * ⁠    4
 * ⁠  /   \
 * ⁠ 7     2
 * ⁠/ \   / \
 * 9   6 3   1
 * 
 * Trivia:
 * This problem was inspired by this original tweet by Max Howell:
 * 
 * Google: 90% of our engineers use the software you wrote (Homebrew), but you
 * can’t invert a binary tree on a whiteboard so f*** off.
 * 
 */

/**
 * Definition for a binary tree node.
 */
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
    TreeNode* invertTree(TreeNode* root) {
        if (root==NULL) return root;
        
        TreeNode* left = root->left;
        TreeNode* right = root->right;

        root->left = invertTree(right);
        root->right = invertTree(left);
        return root;

        vector<TreeNode*> stack;
        stack.push_back(root);
        while (!stack.empty()) {
            TreeNode *cur = stack.back();
            stack.pop_back();
            
            if (cur) {
                stack.push_back(cur->left);
                stack.push_back(cur->right);
                swap(cur->left, cur->right);
            }
        }
        return root;
    }
};
// @lc code=end

