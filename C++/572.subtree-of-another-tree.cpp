/*
 * @lc app=leetcode id=572 lang=cpp
 *
 * [572] Subtree of Another Tree
 *
 * https://leetcode.com/problems/subtree-of-another-tree/description/
 *
 * algorithms
 * Easy (43.68%)
 * Likes:    1792
 * Dislikes: 81
 * Total Accepted:    171.7K
 * Total Submissions: 393.1K
 * Testcase Example:  '[3,4,5,1,2]\n[4,1,2]'
 *
 * 
 * Given two non-empty binary trees s and t, check whether tree t has exactly
 * the same structure and node values with a subtree of s. A subtree of s is a
 * tree consists of a node in s and all of this node's descendants. The tree s
 * could also be considered as a subtree of itself.
 * 
 * 
 * Example 1:
 * 
 * Given tree s:
 * 
 * ⁠    3
 * ⁠   / \
 * ⁠  4   5
 * ⁠ / \
 * ⁠1   2
 * 
 * Given tree t:
 * 
 * ⁠  4 
 * ⁠ / \
 * ⁠1   2
 * 
 * Return true, because t has the same structure and node values with a subtree
 * of s.
 * 
 * 
 * Example 2:
 * 
 * Given tree s:
 * 
 * ⁠    3
 * ⁠   / \
 * ⁠  4   5
 * ⁠ / \
 * ⁠1   2
 * ⁠   /
 * ⁠  0
 * 
 * Given tree t:
 * 
 * ⁠  4
 * ⁠ / \
 * ⁠1   2
 * 
 * Return false.
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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (s==NULL && t==NULL) return true;
        if (s==NULL || t==NULL) return false;
        return isSubtreeWithRoot(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
    }
    bool isSubtreeWithRoot(TreeNode* s, TreeNode* t) {
        if (s==NULL && t==NULL) return true;
        if (s==NULL || t==NULL) return false;
        if (s->val != t->val) return false;
        return isSubtreeWithRoot(s->left, t->left) && isSubtreeWithRoot(s->right, t->right);
    }
};
// @lc code=end

