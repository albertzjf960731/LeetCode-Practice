/*
 * @lc app=leetcode id=1339 lang=cpp
 *
 * [1339] Maximum Product of Splitted Binary Tree
 *
 * https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/description/
 *
 * algorithms
 * Medium (37.11%)
 * Likes:    336
 * Dislikes: 33
 * Total Accepted:    17.6K
 * Total Submissions: 47.3K
 * Testcase Example:  '[1,2,3,4,5,6]'
 *
 * Given a binary tree root. Split the binary tree into two subtrees by
 * removing 1 edge such that the product of the sums of the subtrees are
 * maximized.
 * 
 * Since the answer may be too large, return it modulo 10^9 + 7.
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: root = [1,2,3,4,5,6]
 * Output: 110
 * Explanation: Remove the red edge and get 2 binary trees with sum 11 and 10.
 * Their product is 110 (11*10)
 * 
 * 
 * Example 2:
 * 
 * 
 * 
 * 
 * Input: root = [1,null,2,3,4,null,null,5,6]
 * Output: 90
 * Explanation:  Remove the red edge and get 2 binary trees with sum 15 and
 * 6.Their product is 90 (15*6)
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: root = [2,3,9,10,7,8,6,5,4,11,1]
 * Output: 1025
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: root = [1,1]
 * Output: 1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * Each tree has at most 50000 nodes and at least 2 nodes.
 * Each node's value is between [1, 10000].
 * 
 */
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// @lc code=start
/**
 * Definition for a binary tree node.
 */
class Solution {
public:
    int maxProduct(TreeNode* root) {
        vector<long> sums;
        long root_sum = DFS(root, sums);
        
        int mode = 1e9+7;
        long ans = 0;
        for (int i=0; i<sums.size(); i++) {
            long prod = (root_sum-sums[i])*sums[i];
            ans = max(ans, prod);
        }
        return (int)(ans%mode);
    }
    
    long DFS(TreeNode* root, vector<long>& sums) {
        if (root==NULL) return 0;
        long sum = root->val + DFS(root->left, sums) + DFS(root->right, sums);
        sums.push_back(sum); 
        return sum;
    }
};
// @lc code=end

