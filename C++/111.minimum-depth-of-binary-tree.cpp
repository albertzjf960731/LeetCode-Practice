/*
 * @lc app=leetcode id=111 lang=cpp
 *
 * [111] Minimum Depth of Binary Tree
 *
 * https://leetcode.com/problems/minimum-depth-of-binary-tree/description/
 *
 * algorithms
 * Easy (36.25%)
 * Likes:    947
 * Dislikes: 540
 * Total Accepted:    349.2K
 * Total Submissions: 962.1K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, find its minimum depth.
 * 
 * The minimum depth is the number of nodes along the shortest path from the
 * root node down to the nearest leaf node.
 * 
 * Note: A leaf is a node with no children.
 * 
 * Example:
 * 
 * Given binary tree [3,9,20,null,null,15,7],
 * 
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * return its minimum depth = 2.
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
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        int left_depth = minDepth(root->left);
        int right_depth = minDepth(root->right);
        if (!left_depth || !right_depth)
            return left_depth + right_depth + 1;
        return min(left_depth, right_depth) + 1;
    }
};
// @lc code=end

