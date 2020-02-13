/*
 * @lc app=leetcode id=671 lang=cpp
 *
 * [671] Second Minimum Node In a Binary Tree
 *
 * https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/description/
 *
 * algorithms
 * Easy (42.98%)
 * Likes:    488
 * Dislikes: 730
 * Total Accepted:    65K
 * Total Submissions: 151.3K
 * Testcase Example:  '[2,2,5,null,null,5,7]'
 *
 * Given a non-empty special binary tree consisting of nodes with the
 * non-negative value, where each node in this tree has exactly two or zero
 * sub-node. If the node has two sub-nodes, then this node's value is the
 * smaller value among its two sub-nodes. More formally, the property root.val
 * = min(root.left.val, root.right.val) always holds.
 * 
 * Given such a binary tree, you need to output the second minimum value in the
 * set made of all the nodes' value in the whole tree.
 * 
 * If no such second minimum value exists, output -1 instead.
 * 
 * Example 1:
 * 
 * 
 * Input: 
 * ⁠   2
 * ⁠  / \
 * ⁠ 2   5
 * ⁠    / \
 * ⁠   5   7
 * 
 * Output: 5
 * Explanation: The smallest value is 2, the second smallest value is 5.
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 
 * ⁠   2
 * ⁠  / \
 * ⁠ 2   2
 * 
 * Output: -1
 * Explanation: The smallest value is 2, but there isn't any second smallest
 * value.
 * 
 * 
 * 
 * 
 */

#include<vector>
#include<queue>
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
    int findSecondMinimumValue(TreeNode* root) {
        if (root==NULL) return -1;
        
        if (root->left==NULL) return -1;

        int left_ans = root->left->val;
        int right_ans = root->right->val;
        if (root->left->val==root->val)
            left_ans = findSecondMinimumValue(root->left);
        if (root->right->val==root->val)
            right_ans = findSecondMinimumValue(root->right);
        
        if (left_ans!=-1 && right_ans!=-1)
            return min(left_ans, right_ans);
        else if (left_ans==-1)
            return right_ans;
        else 
            return left_ans;
    }
};
// @lc code=end

