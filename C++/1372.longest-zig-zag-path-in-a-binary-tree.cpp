/*
 * @lc app=leetcode id=1372 lang=cpp
 *
 * [1372] Longest ZigZag Path in a Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 */
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int longestZigZag(TreeNode* root) {
        int ans = 0;
        DFS(root, ans);
        return ans;
    }
    vector<int> DFS(TreeNode* root, int& ans) {
        if (root==nullptr) return {0, 0};
        vector<int> left = DFS(root->left, ans);
        vector<int> right = DFS(root->right, ans);
        ans = max({ans, left[1], right[0]});
        return {left[1]+1, right[0]+1};
    }
};
// @lc code=end
