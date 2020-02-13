/*
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
 *
 * https://leetcode.com/problems/binary-tree-maximum-path-sum/description/
 *
 * algorithms
 * Hard (32.19%)
 * Likes:    2554
 * Dislikes: 205
 * Total Accepted:    270.6K
 * Total Submissions: 840.1K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a non-empty binary tree, find the maximum path sum.
 * 
 * For this problem, a path is defined as any sequence of nodes from some
 * starting node to any node in the tree along the parent-child connections.
 * The path must contain at least one node and does not need to go through the
 * root.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,3]
 * 
 * ⁠      1
 * ⁠     / \
 * ⁠    2   3
 * 
 * Output: 6
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [-10,9,20,null,null,15,7]
 * 
 * -10
 * / \
 * 9  20
 * /  \
 * 15   7
 * 
 * Output: 42
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
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        maxPathSumWithRoot(root, ans);
        return ans;
    }
    int maxPathSumWithRoot(TreeNode* root, int& ans) {
        if (root==NULL) 
            return 0;
        int left_sum = maxPathSumWithRoot(root->left, ans);
        int right_sum = maxPathSumWithRoot(root->right, ans);
        left_sum = max(left_sum, 0);
        right_sum = max(right_sum, 0);
        
        ans = max(ans, left_sum+right_sum+root->val);
        return max(left_sum, right_sum) + root->val;
    }
};
// @lc code=end

