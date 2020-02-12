/*
 * @lc app=leetcode id=654 lang=cpp
 *
 * [654] Maximum Binary Tree
 *
 * https://leetcode.com/problems/maximum-binary-tree/description/
 *
 * algorithms
 * Medium (78.15%)
 * Likes:    1450
 * Dislikes: 198
 * Total Accepted:    113.1K
 * Total Submissions: 144.6K
 * Testcase Example:  '[3,2,1,6,0,5]'
 *
 * 
 * Given an integer array with no duplicates. A maximum tree building on this
 * array is defined as follow:
 * 
 * The root is the maximum number in the array. 
 * The left subtree is the maximum tree constructed from left part subarray
 * divided by the maximum number.
 * The right subtree is the maximum tree constructed from right part subarray
 * divided by the maximum number. 
 * 
 * 
 * 
 * 
 * Construct the maximum tree by the given array and output the root node of
 * this tree.
 * 
 * 
 * Example 1:
 * 
 * Input: [3,2,1,6,0,5]
 * Output: return the tree root node representing the following tree:
 * 
 * ⁠     6
 * ⁠   /   \
 * ⁠  3     5
 * ⁠   \    / 
 * ⁠    2  0   
 * ⁠      \
 * ⁠       1
 * 
 * 
 * 
 * Note:
 * 
 * The size of the given array will be in the range [1,1000].
 * 
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return DFS(nums, 0, nums.size()-1);
    }
    TreeNode* DFS(vector<int>& nums, int left, int right) {
        if (left>right) return NULL;
        
        int max_num=nums[left], max_idx = left;
        for (int i=left; i<=right; i++) {
            if (nums[i]>max_num) {
                max_num = nums[i];
                max_idx = i;
            }
        }
        
        TreeNode* root = new TreeNode(nums[max_idx]);
        root->left = DFS(nums, left, max_idx-1);
        root->right = DFS(nums, max_idx+1, right);
        return root;
    }
};
// @lc code=end

