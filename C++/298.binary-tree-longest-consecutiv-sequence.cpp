/*
 * @lc app=leetcode id=298 lang=cpp
 *
 * [298] Binary Tree Longest Consecutive Sequence 
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
 * 
 * Given a binary tree, find the length of the longest consecutive sequence path
 * 
 * The path refers to any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The longest consecutive path need to be from parent to child (cannot be the reverse).
 * 
 * For example,
 * 
 * 1
 *  \
 *   3
 *  / \
 * 2   4
 *      \
 *       5
 * 
 * Longest consecutive sequence path is 3-4-5, so return 3.
 * 
 *   2
 *    \
 *     3
 *    / 
 *   2    
 *  / 
 * 1
 * 
 * Longest consecutive sequence path is 2-3,not3-2-1, so return 2.
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
    int longestConsecutive(TreeNode* root) {
        if (root==NULL) return 0;
        int ans = 0;
        DFS(root, root->val, 0, ans);
        return ans;
    }
    void DFS(TreeNode *node, int v, int path, int &ans) {
        if (!node) return;

        if (node->val == v+1) 
            ++path;
        else 
            path = 1;
        ans = max(ans, path);
        DFS(node->left, node->val, path, ans);
        DFS(node->right, node->val, path, ans);
    }
};
// @lc code=end

