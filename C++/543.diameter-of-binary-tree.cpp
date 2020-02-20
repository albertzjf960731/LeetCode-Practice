/*
 * @lc app=leetcode id=543 lang=cpp
 *
 * [543] Diameter of Binary Tree
 *
 * https://leetcode.com/problems/diameter-of-binary-tree/description/
 *
 * algorithms
 * Easy (48.22%)
 * Likes:    2123
 * Dislikes: 136
 * Total Accepted:    203.6K
 * Total Submissions: 422.2K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * 
 * Given a binary tree, you need to compute the length of the diameter of the
 * tree. The diameter of a binary tree is the length of the longest path
 * between any two nodes in a tree. This path may or may not pass through the
 * root.
 * 
 * 
 * 
 * Example:
 * Given a binary tree 
 * 
 * ⁠         1
 * ⁠        / \
 * ⁠       2   3
 * ⁠      / \     
 * ⁠     4   5    
 * 
 * 
 * 
 * Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].
 * 
 * 
 * Note:
 * The length of path between two nodes is represented by the number of edges
 * between them.
 * 
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
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        DFS(root, ans);
        return ans;
    }
    int DFS(TreeNode* root, int& ans) {
        if (root==NULL) return 0;

        int left_depth = DFS(root->left, ans);
        int right_depth = DFS(root->right, ans);
        ans = max(ans, left_depth+right_depth);
        return max(left_depth, right_depth)+1;
    }
};
// @lc code=end

