/*
 * @lc app=leetcode id=965 lang=cpp
 *
 * [965] Univalued Binary Tree
 *
 * https://leetcode.com/problems/univalued-binary-tree/description/
 *
 * algorithms
 * Easy (67.18%)
 * Likes:    337
 * Dislikes: 39
 * Total Accepted:    68K
 * Total Submissions: 101.3K
 * Testcase Example:  '[1,1,1,1,1,null,1]'
 *
 * A binary tree is univalued if every node in the tree has the same value.
 * 
 * Return true if and only if the given tree is univalued.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [1,1,1,1,1,null,1]
 * Output: true
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [2,2,2,5,2]
 * Output: false
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The number of nodes in the given tree will be in the range [1, 100].
 * Each node's value will be an integer in the range [0, 99].
 * 
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
    bool isUnivalTree(TreeNode* root) {        vector<TreeNode*> stack;
        TreeNode *cur = root;
        int num = root->val;
        while (cur || !stack.empty()) {
            while (cur) {
                stack.push_back(cur);
                cur = cur->left;
            }
            cur = stack.back();
            stack.pop_back();
            if (cur->val!=num)
                return false;
            cur = cur->right;
        }
        return true;
    }
};
// @lc code=end

