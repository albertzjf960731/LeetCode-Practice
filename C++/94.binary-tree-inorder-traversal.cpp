/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
 */

#include<vector>
#include<stack>

using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// @lc code=start
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<TreeNode*> stack;
        vector<int> res;

        TreeNode *cur = root;
        while (cur!=NULL || stack.size()>0) {
            while (cur!=NULL) {
                stack.push_back(cur);
                cur = cur->left;
            }
            cur = stack.back();
            stack.pop_back();
            res.push_back(cur->val);
            cur = cur->right;
        }

        return res;
    }
};
// @lc code=end

