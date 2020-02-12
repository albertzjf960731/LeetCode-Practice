/*
 * @lc app=leetcode id=1008 lang=cpp
 *
 * [1008] Construct Binary Search Tree from Preorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/description/
 *
 * algorithms
 * Medium (74.57%)
 * Likes:    507
 * Dislikes: 19
 * Total Accepted:    34K
 * Total Submissions: 45.5K
 * Testcase Example:  '[8,5,1,7,10,12]'
 *
 * Return the root node of a binary search tree that matches the given preorder
 * traversal.
 * 
 * (Recall that a binary search tree is a binary tree where for every node, any
 * descendant of node.left has a value < node.val, and any descendant of
 * node.right has a value > node.val.  Also recall that a preorder traversal
 * displays the value of the node first, then traverses node.left, then
 * traverses node.right.)
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [8,5,1,7,10,12]
 * Output: [8,5,10,1,7,null,12]
 * 
 * 
 * 
 * 
 * 
 * Note: 
 * 
 * 
 * 1 <= preorder.length <= 100
 * The values of preorder are distinct.
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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return DFS(preorder, 0, preorder.size()-1);
    }
    
    TreeNode* DFS(vector<int>& preorder, int left, int right) {
        if (left > right) return NULL;
        
        TreeNode *root = new TreeNode(preorder[left]);
        
        int mid = left+1;
        while (mid<=right && preorder[mid]<preorder[left]) 
            mid++;
        
        root->left = DFS(preorder, left+1, mid-1);
        root->right = DFS(preorder, mid, right);
        return root;
    }
};
// @lc code=end

