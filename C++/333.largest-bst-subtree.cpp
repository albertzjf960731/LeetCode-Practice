/*
 * @lc app=leetcode id=333 lang=cpp
 *
 * [333] Largest BST Subtree
 *
 * Given a binary tree, find the largest subtree which is a Binary Search Tree (BST), where largest means subtree with largest number of nodes in it.
 * 
 * Note:
 * A subtree must include all of its descendants.
 * 
 * Example:
 * 
 * Input: [10,5,15,1,8,null,7]
 * 
 * 10 
 * / \ 
 * 5  15 
 * / \   \ 
 * 1   8   7
 * 
 * Output: 3
 * 
 * Explanation: The Largest BST Subtree in this case is the highlighted one
 * The return value is the subtree's size, which is 3.
 * 
 * Follow up:
 * Can you figure out ways to solve it with O(n) time complexity?
 * Hint:
 * You can recursively use algorithm similar to 98. Validate Binary Search Tree at each node of the tree, which will result in O(nlogn) time complexity.
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
    // int largestBSTSubtree(TreeNode* root) {
    //     int ans = 0;
    //     DFS(root, ans);
    //     return ans;
    // }
    // void DFS(TreeNode *root, int &ans) {
    //     if (!root) return;
    //     int cnt = countBFS(root, INT_MIN, INT_MAX);
    //     if (cnt != -1) {
    //         ans = max(ans, cnt);
    //         return;
    //     }
    //     DFS(root->left, ans);
    //     DFS(root->right, ans);
    // }
    // int countBFS(TreeNode *root, int mn, int mx) {
    //     if (!root) return 0;
    //     if (root->val <= mn || root->val >= mx) return -1;
        
    //     int left = countBFS(root->left, mn, root->val);
    //     if (left == -1) return -1;
        
    //     int right = countBFS(root->right, root->val, mx);
    //     if (right == -1) return -1;
        
    //     return left + right + 1;
    // }


    int largestBSTSubtree(TreeNode* root) {
        vector<int> res = DFS(root);
        return res[2];
    }
    vector<int> DFS(TreeNode* node) {
        if (!node) return {INT_MAX, INT_MIN, 0};

        vector<int> left = DFS(node->left);
        vector<int> right = DFS(node->right);

        if (node->val>left[1] && node->val<right[0]) {
            return {min(node->val, left[0]), 
                    max(node->val, right[1]), 
                    left[2] + right[2] + 1};
        } else {
            return {INT_MIN, INT_MAX, max(left[2], right[2])};
        }
    }


};
// @lc code=end

