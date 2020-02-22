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
 * Given a binary tree, you need to find the length of Longest Consecutive Path in Binary Tree.
 * 
 * Especially, this path can be either increasing or decreasing. For example, [1,2,3,4] and [4,3,2,1] are both considered valid, but the path [1,2,4,3] is not valid. On the other hand, the path can be in the child-Parent-child order, where not necessarily be parent-child order.
 * 
 * Example 1:
 * 
 * Input:
 *      1
 *     / \
 *    2   3
 * 
 * Output: 2
 * 
 * Explanation: The longest consecutive path is [1, 2] or [2, 1].
 * 
 * 
 * Example 2:
 * 
 * Input:
 *      2
 *     / \
 *    1   3
 * 
 * Output: 3
 * Explanation: The longest consecutive path is [1, 2, 3] or [3, 2, 1].
 * 
 * Note: All the values of tree nodes are in the range of [-1e7, 1e7].
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
        int ans = longestConsecutiveWithNode(root, 1) + longestConsecutiveWithNode(root, -1) + 1;
        return max(ans, max(longestConsecutive(root->left), longestConsecutive(root->right)));
        return ans;
    }
    int longestConsecutiveWithNode(TreeNode *node, int diff) {
        if (!node) return 0;

        int left = 0, right = 0;

        if (node->left && node->val - node->left->val == diff) 
            left = 1 + longestConsecutiveWithNode(node->left, diff);
        if (node->right && node->val - node->right->val == diff) 
            right = 1 + longestConsecutiveWithNode(node->right, diff);
        return max(left, right);
    }
};
// @lc code=end

