/*
 * @lc app=leetcode id=545 lang=cpp
 *
 * [545] Boundary of Binary Tree
 * 
 * Given a binary tree, return the values of its boundary in anti-clockwise direction starting from root. Boundary includes left boundary, leaves, and right boundary in order without duplicate nodes.
 *
 * Left boundary is defined as the path from root to the left-most node. Right boundary is defined as the path from root to the right-most node. If the root doesn't have left subtree or right subtree, then the root itself is left boundary or right boundary. Note this definition only applies to the input binary tree, and not applies to any subtrees.
 * 
 * The left-most node is defined as a leaf node you could reach when you always firstly travel to the left subtree if exists. If not, travel to the right subtree. Repeat until you reach a leaf node.
 * 
 * The right-most node is also defined by the same way with left and right exchanged.
 * ]
 * 
 * 
 */

#include<vector>
#include<unordered_map>
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
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> res;
        if (root==NULL) return res;

        if (root->left || root->right) 
            res.push_back(root->val);
        leftBoundary(root->left, res);
        leaves(root, res);
        rightBoundary(root->right, res);
        return res;
    }

    void leftBoundary(TreeNode* node, vector<int>& res) {
        if (!node || (!node->left && !node->right)) 
            return;
        res.push_back(node->val);
        if (!node->left) 
            leftBoundary(node->right, res);
        else 
            leftBoundary(node->left, res);
    }
    void rightBoundary(TreeNode* node, vector<int>& res) {
        if (!node || (!node->left && !node->right)) 
            return;
        if (!node->right) 
            rightBoundary(node->left, res);
        else 
            rightBoundary(node->right, res);
        res.push_back(node->val);
    }
    void leaves(TreeNode* node, vector<int>& res) {
        if (!node) 
            return;
        if (!node->left && !node->right)
            res.push_back(node->val);
        leaves(node->left, res);
        leaves(node->right, res);
    }
};
// @lc code=end

