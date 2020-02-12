/*
 * @lc app=leetcode id=515 lang=cpp
 *
 * [515] Find Largest Value in Each Tree Row
 *
 * https://leetcode.com/problems/find-largest-value-in-each-tree-row/description/
 *
 * algorithms
 * Medium (59.35%)
 * Likes:    644
 * Dislikes: 53
 * Total Accepted:    81K
 * Total Submissions: 136.4K
 * Testcase Example:  '[1,3,2,5,3,null,9]'
 *
 * You need to find the largest value in each row of a binary tree.
 * 
 * Example:
 * 
 * Input: 
 * 
 * ⁠         1
 * ⁠        / \
 * ⁠       3   2
 * ⁠      / \   \  
 * ⁠     5   3   9 
 * 
 * Output: [1, 3, 9]
 * 
 * 
 * 
 */
#include<vector>
#include<stack>
#include<queue>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// @lc code=start
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        if (root==NULL) return res;
        
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int level_max = INT_MIN;
            
            int q_size = q.size();
            while(q_size--) {
                TreeNode *cur = q.front();
                q.pop();
                
                level_max = max(level_max, cur->val);
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
            res.push_back(level_max);
        }
        return res;
    }
};
// @lc code=end

