/*
 * @lc app=leetcode id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
 *
 * https://leetcode.com/problems/binary-tree-right-side-view/description/
 *
 * algorithms
 * Medium (51.39%)
 * Likes:    1645
 * Dislikes: 87
 * Total Accepted:    230.1K
 * Total Submissions: 447.6K
 * Testcase Example:  '[1,2,3,null,5,null,4]'
 *
 * Given a binary tree, imagine yourself standing on the right side of it,
 * return the values of the nodes you can see ordered from top to bottom.
 * 
 * Example:
 * 
 * 
 * Input: [1,2,3,null,5,null,4]
 * Output: [1, 3, 4]
 * Explanation:
 * 
 * ⁠  1            <---
 * ⁠/   \
 * 2     3         <---
 * ⁠\     \
 * ⁠ 5     4       <---
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (root==NULL) return res;
        
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* right_most = NULL;
            
            int q_size = q.size();
            while (q_size--) {
                TreeNode* cur = q.front();
                q.pop();
                
                right_most = cur;
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
            res.push_back(right_most->val);
        }
        return res;
    }
};
// @lc code=end

