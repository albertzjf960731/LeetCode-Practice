/*
 * @lc app=leetcode id=513 lang=cpp
 *
 * [513] Find Bottom Left Tree Value
 *
 * https://leetcode.com/problems/find-bottom-left-tree-value/description/
 *
 * algorithms
 * Medium (60.19%)
 * Likes:    707
 * Dislikes: 119
 * Total Accepted:    90.2K
 * Total Submissions: 149.8K
 * Testcase Example:  '[2,1,3]'
 *
 * 
 * Given a binary tree, find the leftmost value in the last row of the tree. 
 * 
 * 
 * Example 1:
 * 
 * Input:
 * 
 * ⁠   2
 * ⁠  / \
 * ⁠ 1   3
 * 
 * Output:
 * 1
 * 
 * 
 * 
 * ⁠ Example 2: 
 * 
 * Input:
 * 
 * ⁠       1
 * ⁠      / \
 * ⁠     2   3
 * ⁠    /   / \
 * ⁠   4   5   6
 * ⁠      /
 * ⁠     7
 * 
 * Output:
 * 7
 * 
 * 
 * 
 * Note:
 * You may assume the tree (i.e., the given root node) is not NULL.
 * 
 */

#include<vector>
#include<stack>
#include<queue>

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
    int findBottomLeftValue(TreeNode* root) {
        if (root==NULL) return -1;
        
        // vector<int> bottom_level;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode *cur = NULL;
        while (!q.empty()) {
            // vector<int> tmp;
            
            int q_size = q.size();
            while(q_size--) {
                cur = q.front();
                q.pop();
                
                // tmp.push_back(cur->val);
                if(cur->right) q.push(cur->right);
                if(cur->left) q.push(cur->left);
            }
            // bottom_level = tmp;
        }
        return cur->val;
    }
};
// @lc code=end

