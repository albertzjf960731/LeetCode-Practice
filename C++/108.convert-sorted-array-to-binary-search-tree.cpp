/*
 * @lc app=leetcode id=108 lang=cpp
 *
 * [108] Convert Sorted Array to Binary Search Tree
 *
 * https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/
 *
 * algorithms
 * Easy (53.87%)
 * Likes:    1639
 * Dislikes: 163
 * Total Accepted:    325.4K
 * Total Submissions: 602.2K
 * Testcase Example:  '[-10,-3,0,5,9]'
 *
 * Given an array where elements are sorted in ascending order, convert it to a
 * height balanced BST.
 * 
 * For this problem, a height-balanced binary tree is defined as a binary tree
 * in which the depth of the two subtrees of every node never differ by more
 * than 1.
 * 
 * Example:
 * 
 * 
 * Given the sorted array: [-10,-3,0,5,9],
 * 
 * One possible answer is: [0,-3,9,-10,null,5], which represents the following
 * height balanced BST:
 * 
 * ⁠     0
 * ⁠    / \
 * ⁠  -3   9
 * ⁠  /   /
 * ⁠-10  5
 * 
 * 
 */
#include<vector>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// @lc code=start
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return DFS(nums, 0, nums.size());
    }
    TreeNode* DFS(vector<int>& nums, int start, int end) {
        if(start==end) return NULL;

        int m = (start+end) / 2;
        TreeNode *root = new TreeNode(nums[m]);
        root->left = DFS(nums, start, m);
        root->right = DFS(nums, m+1, end);
        return root;
    }
};
// @lc code=end

