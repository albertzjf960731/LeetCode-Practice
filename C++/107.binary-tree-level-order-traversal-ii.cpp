/*
 * @lc app=leetcode id=107 lang=cpp
 *
 * [107] Binary Tree Level Order Traversal II
 *
 * https://leetcode.com/problems/binary-tree-level-order-traversal-ii/description/
 *
 * algorithms
 * Easy (49.11%)
 * Likes:    939
 * Dislikes: 177
 * Total Accepted:    265.3K
 * Total Submissions: 539K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the bottom-up level order traversal of its
 * nodes' values. (ie, from left to right, level by level from leaf to root).
 * 
 * 
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 
 * return its bottom-up level order traversal as:
 * 
 * [
 * ⁠ [15,7],
 * ⁠ [9,20],
 * ⁠ [3]
 * ]
 * 
 * 
 */
#include<vector>
#include<queue>
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res; 
        
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            vector<int> item;
            int q_size = q.size();
            for (int i=0; i<q_size; i++) {
                TreeNode* node = q.front();
                q.pop();

                item.push_back(node->val);
                if (node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            res.push_back(item);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end

