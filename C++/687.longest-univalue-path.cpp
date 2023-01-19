/*
 * @lc app=leetcode id=687 lang=cpp
 *
 * [687] Longest Univalue Path
 *
 * https://leetcode.com/problems/longest-univalue-path/description/
 *
 * algorithms
 * Easy (35.08%)
 * Likes:    1330
 * Dislikes: 356
 * Total Accepted:    77.3K
 * Total Submissions: 220.4K
 * Testcase Example:  '[5,4,5,1,1,5]'
 *
 * Given a binary tree, find the length of the longest path where each node in
 * the path has the same value. This path may or may not pass through the
 * root.
 * 
 * The length of path between two nodes is represented by the number of edges
 * between them.
 * 
 * 
 * 
 * Example 1:
 * 
 * Input:
 * 
 * 
 * ⁠             5
 * ⁠            / \
 * ⁠           4   5
 * ⁠          / \   \
 * ⁠         1   1   5
 * 
 * 
 * Output: 2
 * 
 * 
 * 
 * Example 2:
 * 
 * Input:
 * 
 * 
 * ⁠             1
 * ⁠            / \
 * ⁠           4   5
 * ⁠          / \   \
 * ⁠         4   4   5
 * 
 * 
 * Output: 2
 * 
 * 
 * 
 * Note: The given binary tree has not more than 10000 nodes. The height of the
 * tree is not more than 1000.
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

    // Case 1: If the root value is equal to BOTH the left and right subtree root values, then set m to the maximum of itself compared to the "up-side-down-V shaped" path created by including the left and right subtrees max paths with the root ( l=l+1 and r=r+1 ). Return the max path value of the left and right subtrees return max(l,r) which is needed in case the next parent up the recursive stack is also the same value.

    // Case 2: If the root value is NOT equal to EITHER the left INCLUSIVE-OR right subtree values, then set BOTH l=0 and r=0 and return 0 ( i.e. return max(0,0) ).

    // Case 3: If the root value is equal to the left subtree root value XOR the right subtree root value, then either l=0 and r=r+1 XOR l=l+1 and r=0, return the maximum of the left and right subtree path values ( i.e. return max(l,0) XOR return max(0,r) ).

    int longestUnivaluePath(TreeNode* root) {
        int ans = 0;
        DFS(root, ans);
        return ans;
    }

    // 以该结 点为终点的最长路径长度
    int DFS(TreeNode* node, int& ans) {
        if (node==NULL) return 0;
        
        int left = DFS(root->left, ans);
        int right = DFS(root->right, ans);
        
        if (root->left && root->left->val != root->val) left = 0;
        if (root->right && root->right->val != root->val) right = 0;
        
        ans = max(ans, left+right+1);
        return max(left, right) + 1;
    }
};
// @lc code=end

