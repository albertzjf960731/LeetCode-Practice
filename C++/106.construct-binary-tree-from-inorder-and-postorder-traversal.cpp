/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
 *
 * algorithms
 * Medium (42.09%)
 * Likes:    1157
 * Dislikes: 25
 * Total Accepted:    182.3K
 * Total Submissions: 431.4K
 * Testcase Example:  '[9,3,15,20,7]\n[9,15,7,20,3]'
 *
 * Given inorder and postorder traversal of a tree, construct the binary tree.
 * 
 * Note:
 * You may assume that duplicates do not exist in the tree.
 * 
 * For example, given
 * 
 * 
 * inorder = [9,3,15,20,7]
 * postorder = [9,15,7,20,3]
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
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> hash_map;
        for (int i=0; i<inorder.size(); i++) {
            hash_map[inorder[i]] = i;
        }
        
        return DFS(inorder, postorder, hash_map, 0, inorder.size()-1);
    }

    TreeNode* DFS(vector<int>& inorder, vector<int>& postorder, unordered_map<int, int>& hash_map, int l, int r) {
        if (l > r) return nullptr;

        TreeNode* root = new TreeNode(postorder.back());
        postorder.pop_back();
        int m = hash_map[root->val];
        
        root->right = DFS(inorder, postorder, hash_map, m+1, r);
        root->left = DFS(inorder, postorder, hash_map, l, m-1);
        return root;
    }     
};
// @lc code=end

