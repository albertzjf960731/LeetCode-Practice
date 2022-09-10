/*
 * @lc app=leetcode id=662 lang=cpp
 *
 * [662] Maximum Width of Binary Tree
 *
 * https://leetcode.com/problems/maximum-width-of-binary-tree/description/
 *
 * algorithms
 * Medium (40.39%)
 * Likes:    5409
 * Dislikes: 788
 * Total Accepted:    211.3K
 * Total Submissions: 522.8K
 * Testcase Example:  '[1,3,2,5,3,null,9]'
 *
 * Given the root of a binary tree, return the maximum width of the given
 * tree.
 * 
 * The maximum width of a tree is the maximum width among all levels.
 * 
 * The width of one level is defined as the length between the end-nodes (the
 * leftmost and rightmost non-null nodes), where the null nodes between the
 * end-nodes that would be present in a complete binary tree extending down to
 * that level are also counted into the length calculation.
 * 
 * It is guaranteed that the answer will in the range of a 32-bit signed
 * integer.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [1,3,2,5,3,null,9]
 * Output: 4
 * Explanation: The maximum width exists in the third level with length 4
 * (5,3,null,9).
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [1,3,2,5,null,null,9,6,null,7]
 * Output: 7
 * Explanation: The maximum width exists in the fourth level with length 7
 * (6,null,null,null,null,null,7).
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: root = [1,3,2,5]
 * Output: 2
 * Explanation: The maximum width exists in the second level with length 2
 * (3,2).
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [1, 3000].
 * -100 <= Node.val <= 100
 * 
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<string>> printTree(TreeNode* root) {
        long long ans = 0, idx, pre_idx, left, right;
        
        queue<pair<TreeNode*, long long>> q;
        q.push(make_pair(root, 0));
        
        while (!q.empty()) {            
            int q_size = q.size();
            pre_idx = q.front().second;
            
            left = right = -1;
            while (q_size--) {
                auto [node, idx] = q.front(); q.pop();
                idx -= pre_idx;
            
                if (left == -1) left = idx;
                right = idx;
                
                if (node->left) 
                   q.push(make_pair(node->left, 2*idx));
                       
                if (node->right) 
                    q.push(make_pair(node->right, 2*idx+1));
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
// @lc code=end

