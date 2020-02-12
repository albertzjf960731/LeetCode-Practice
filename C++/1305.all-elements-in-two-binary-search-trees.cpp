/*
 * @lc app=leetcode id=1305 lang=cpp
 *
 * [1305] All Elements in Two Binary Search Trees
 *
 * https://leetcode.com/problems/all-elements-in-two-binary-search-trees/description/
 *
 * algorithms
 * Medium (74.62%)
 * Likes:    160
 * Dislikes: 5
 * Total Accepted:    13.2K
 * Total Submissions: 17.7K
 * Testcase Example:  '[2,1,4]\r\n[1,0,3]\r'
 *
 * Given two binary search trees root1 and root2.
 * 
 * Return a list containing all the integers from both trees sorted in
 * ascending order.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root1 = [2,1,4], root2 = [1,0,3]
 * Output: [0,1,1,2,3,4]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root1 = [0,-10,10], root2 = [5,1,7,0,2]
 * Output: [-10,0,0,1,2,5,7,10]
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: root1 = [], root2 = [5,1,7,0,2]
 * Output: [0,1,2,5,7]
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: root1 = [0,-10,10], root2 = []
 * Output: [-10,0,10]
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: root1 = [1,null,8], root2 = [8,1]
 * Output: [1,1,8,8]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * Each tree has at most 5000 nodes.
 * Each node's value is between [-10^5, 10^5].
 * 
 * 
 */
/**
 * Definition for a binary tree node.
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
     vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> res;
        vector<TreeNode*> stack1, stack2;
        
        pushLeft(stack1, root1);
        pushLeft(stack2, root2);
        
        while (!stack1.empty() || !stack2.empty()) {
            vector<TreeNode*> &stack = stack1.empty()? stack2: stack2.empty()? stack1: stack1.back()->val<stack2.back()->val? stack1 : stack2;
            
            TreeNode* node = stack.back();
            stack.pop_back();
            res.push_back(node->val);

            pushLeft(stack, node->right); 
        }
        return res;
    }
    void pushLeft(vector<TreeNode*>& stack, TreeNode* node) {
        while (node) {
            stack.push_back(node);
            node = node->left;
        }
    }
};
// @lc code=end

