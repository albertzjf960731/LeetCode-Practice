/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] Binary Tree Preorder Traversal
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;

        if (!root) return res;

        vector<TreeNode*> stack;
        stack.push_back(root);
        while (stack.size() > 0) {
            TreeNode *cur = stack.back();
            stack.pop_back();

            if (cur!=NULL) {
                res.push_back(cur->val);
                stack.push_back(cur->right);
                stack.push_back(cur->left);
            }
        }
        return res;
    }
};
// @lc code=end

