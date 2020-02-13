/*
 * @lc app=leetcode id=95 lang=cpp
 *
 * [95] Unique Binary Search Trees II
 *
 * https://leetcode.com/problems/unique-binary-search-trees-ii/description/
 *
 * algorithms
 * Medium (37.71%)
 * Likes:    1653
 * Dislikes: 134
 * Total Accepted:    163.2K
 * Total Submissions: 431.1K
 * Testcase Example:  '3'
 *
 * Given an integer n, generate all structurally unique BST's (binary search
 * trees) that store values 1 ... n.
 * 
 * Example:
 * 
 * 
 * Input: 3
 * Output:
 * [
 * [1,null,3,2],
 * [3,2,null,1],
 * [3,1,null,null,2],
 * [2,1,3],
 * [1,null,2,null,3]
 * ]
 * Explanation:
 * The above output corresponds to the 5 unique BST's shown below:
 * 
 * ⁠  1         3     3      2      1
 * ⁠   \       /     /      / \      \
 * ⁠    3     2     1      1   3      2
 * ⁠   /     /       \                 \
 * ⁠  2     1         2                 3
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
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> res;
        if (n==0) return res;
        return DFS(1, n);
    }
     vector<TreeNode*> DFS(int left, int right) {
        vector<TreeNode*> res;
    
        if (left>right) {
            res.push_back(NULL);
            return res;
        }

        for (int i=left; i<=right; i++) {
            vector<TreeNode*> left_trees = DFS(left, i-1);
            vector<TreeNode*> right_trees = DFS(i+1, right);
            
            for (TreeNode* left: left_trees) {
                for (TreeNode* right: right_trees) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};
// @lc code=end

