/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
 *
 * https://leetcode.com/problems/balanced-binary-tree/description/
 *
 * algorithms
 * Easy (42.17%)
 * Likes:    1630
 * Dislikes: 143
 * Total Accepted:    381.4K
 * Total Submissions: 903.2K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, determine if it is height-balanced.
 * 
 * For this problem, a height-balanced binary tree is defined as:
 * 
 * 
 * a binary tree in which the left and right subtrees of every node differ in
 * height by no more than 1.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * Given the following tree [3,9,20,null,null,15,7]:
 * 
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * Return true.
 * 
 * Example 2:
 * 
 * Given the following tree [1,2,2,3,3,null,null,4,4]:
 * 
 * 
 * ⁠      1
 * ⁠     / \
 * ⁠    2   2
 * ⁠   / \
 * ⁠  3   3
 * ⁠ / \
 * ⁠4   4
 * 
 * 
 * Return false.
 * 
 */

/**
 * Definition for a binary tree node.
 */
#include<iostream>
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
    bool isBalanced(TreeNode* root) {
        int depth = 0;
        return checkBalance(root, depth);
    }
    bool checkBalance(TreeNode* root, int& depth) {
        if (!root) {
            depth = 0;
            return true;
        }

        // 后序遍历
        int left_depth = 0;
        int right_depth = 0;
        if(!checkBalance(root->left, left_depth)) return false;
        if(!checkBalance(root->right, right_depth)) return false;
        if (abs(left_depth - right_depth) > 1) return false;

        depth = max(left_depth, right_depth) + 1;
        return true;
    }
};
// @lc code=end

