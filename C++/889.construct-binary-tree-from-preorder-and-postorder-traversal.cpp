/*
 * @lc app=leetcode id=889 lang=cpp
 *
 * [889] Construct Binary Tree from Preorder and Postorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/description/
 *
 * algorithms
 * Medium (63.79%)
 * Likes:    585
 * Dislikes: 38
 * Total Accepted:    27K
 * Total Submissions: 42.2K
 * Testcase Example:  '[1,2,4,5,3,6,7]\n[4,5,2,6,7,3,1]'
 *
 * Return any binary tree that matches the given preorder and postorder
 * traversals.
 * 
 * Values in the traversals pre and post are distinct positive integers.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: pre = [1,2,4,5,3,6,7], post = [4,5,2,6,7,3,1]
 * Output: [1,2,3,4,5,6,7]
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= pre.length == post.length <= 30
 * pre[] and post[] are both permutations of 1, 2, ..., pre.length.
 * It is guaranteed an answer exists. If there exists multiple answers, you can
 * return any of them.
 * 
 * 
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
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        unordered_map<int, int> post_idx;
        for (int i=0; i<post.size(); i++) post_idx[post[i]] = i;
        return DFS(pre, 0, pre.size()-1, post, 0, post.size()-1, post_idx);
    }

    TreeNode* DFS(vector<int>& pre, int pre_l, int pre_r, vector<int>& post, int post_l, int post_r, unordered_map<int, int>& post_idx) {
        if (pre_l>pre_r || post_l >post_r) return NULL;

        TreeNode* root = new TreeNode(pre[pre_l]);
        if (pre_l+1<=pre_r){
            int delta = post_idx[pre[pre_l+1]] - post_l;
            root->left = DFS(pre, pre_l+1, pre_l+1+delta, post, post_l, post_l+delta, post_idx);
            root->right = DFS(pre, pre_l+1+delta+1, pre_r, post, post_l+delta+1, post_r-1, post_idx);
        }
        return root;
    }
};
// @lc code=end

