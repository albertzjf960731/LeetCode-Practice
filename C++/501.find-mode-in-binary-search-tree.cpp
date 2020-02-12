/*
 * @lc app=leetcode id=501 lang=cpp
 *
 * [501] Find Mode in Binary Search Tree
 *
 * https://leetcode.com/problems/find-mode-in-binary-search-tree/description/
 *
 * algorithms
 * Easy (41.03%)
 * Likes:    727
 * Dislikes: 282
 * Total Accepted:    72.6K
 * Total Submissions: 176.9K
 * Testcase Example:  '[1,null,2,2]'
 *
 * Given a binary search tree (BST) with duplicates, find all the mode(s) (the
 * most frequently occurred element) in the given BST.
 * 
 * Assume a BST is defined as follows:
 * 
 * 
 * The left subtree of a node contains only nodes with keys less than or equal
 * to the node's key.
 * The right subtree of a node contains only nodes with keys greater than or
 * equal to the node's key.
 * Both the left and right subtrees must also be binary search trees.
 * 
 * 
 * 
 * 
 * For example:
 * Given BST [1,null,2,2],
 * 
 * 
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  2
 * 
 * 
 * 
 * 
 * return [2].
 * 
 * Note: If a tree has more than one mode, you can return them in any order.
 * 
 * Follow up: Could you do that without using any extra space? (Assume that the
 * implicit stack space incurred due to recursion does not count).
 * 
 */

/**
 * Definition for a binary tree node.
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
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> hash_map;
        
        vector<TreeNode*> stack;
        TreeNode* cur = root;
        while (cur!=NULL || !stack.empty()) {
            while (cur!=NULL) {
                stack.push_back(cur);
                cur = cur->left;
            }
            cur = stack.back();
            stack.pop_back();
            hash_map[cur->val]++;
                
            cur = cur->right;
        }
        
        int mode = INT_MIN;
        vector<int> res;
        for(auto it=hash_map.begin(); it!=hash_map.end(); it++) {
            if (it->second==mode) 
                res.push_back(it->first);
            else if (it->second > mode) {
                mode = it->second;
                res.clear();
                res.push_back(it->first);
            }
        }
        return res;
    }
};
// @lc code=end

