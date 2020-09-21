/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (45.29%)
 * Likes:    2506
 * Dislikes: 70
 * Total Accepted:    294.7K
 * Total Submissions: 650.7K
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * Given preorder and inorder traversal of a tree, construct the binary tree.
 * 
 * Note:
 * You may assume that duplicates do not exist in the tree.
 * 
 * For example, given
 * 
 * 
 * preorder = [3,9,20,15,7]
 * inorder = [9,3,15,20,7]
 * 
 * Return the following binary tree:
 * 
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 */

/**
 * Definition for a binary tree node.
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
private:
    int pre_idx = 0;
    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inorder_idx;
        for (int i=0; i<inorder.size(); i++) inorder_idx[inorder[i]] = i;
        
        return DFS(preorder, inorder, inorder_idx, 0, inorder.size()-1);
    }
    TreeNode* DFS(vector<int>& preorder, vector<int>& inorder, unordered_map<int, int>& inorder_idx, int left, int right) {
        if (left>right) return NULL;
        
        TreeNode* root = new TreeNode(preorder[pre_idx++]);
        // preorder.erase(preorder.begin());
        
        int idx = inorder_idx[root->val];
        root->left = DFS(preorder, inorder, inorder_idx, left, idx-1);
        root->right = DFS(preorder, inorder, inorder_idx, idx+1, right);
        return root;
    }
};
// @lc code=end

