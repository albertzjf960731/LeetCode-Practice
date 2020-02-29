/*
 * @lc app=leetcode id=222 lang=cpp
 *
 * [222] Count Complete Tree Nodes
 *
 * https://leetcode.com/problems/count-complete-tree-nodes/description/
 *
 * algorithms
 * Medium (40.74%)
 * Likes:    1586
 * Dislikes: 169
 * Total Accepted:    179.4K
 * Total Submissions: 439.3K
 * Testcase Example:  '[1,2,3,4,5,6]'
 *
 * Given a complete binary tree, count the number of nodes.
 * 
 * Note: 
 * 
 * Definition of a complete binary tree from Wikipedia:
 * In a complete binary tree every level, except possibly the last, is
 * completely filled, and all nodes in the last level are as far left as
 * possible. It can have between 1 and 2^h nodes inclusive at the last level
 * h.
 * 
 * Example:
 * 
 * 
 * Input: 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   3
 * ⁠/ \  /
 * 4  5 6
 * 
 * Output: 6
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
    int countNodes(TreeNode* root) {

        if (root==NULL)
            return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
        
        
        TreeNode *node = root;
        int height = 0;
        while(node!=NULL) {
            height ++;
            node = node->left;
        }
        int ans = 1<<(height-1);
        
        node = root;
        while (--height>0) {
            TreeNode *right = node->right;
            
            if (helper(right, height)) {
                ans += 1<< (height-1);
                node = node->right;
            }
            else {
                node = node->left;
            }
        }
        return ans;
    }
    int helper(TreeNode* node, int height) {
        while (node!=NULL) {
            height --;
            node = node->left;
        }
        return height==0;
    }
};
// @lc code=end

