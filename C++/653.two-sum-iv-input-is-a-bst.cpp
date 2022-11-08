/*
 * @lc app=leetcode id=653 lang=cpp
 *
 * [653] Two Sum IV - Input is a BST
 *
 * https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/
 *
 * algorithms
 * Easy (54.26%)
 * Likes:    1163
 * Dislikes: 125
 * Total Accepted:    119.1K
 * Total Submissions: 219.4K
 * Testcase Example:  '[5,3,6,2,4,null,7]\n9'
 *
 * Given a Binary Search Tree and a target number, return true if there exist
 * two elements in the BST such that their sum is equal to the given target.
 * 
 * Example 1:
 * 
 * 
 * Input: 
 * ⁠   5
 * ⁠  / \
 * ⁠ 3   6
 * ⁠/ \   \
 * 2   4   7
 * 
 * Target = 9
 * 
 * Output: True
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 
 * ⁠   5
 * ⁠  / \
 * ⁠ 3   6
 * ⁠/ \   \
 * 2   4   7
 * 
 * Target = 28
 * 
 * Output: False
 * 
 * 
 * 
 * 
 */

#include<vector>
#include<unordered_set>
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
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> hash_set;

        vector<TreeNode*> stack;
        TreeNode* cur = root;
        while (cur!=NULL || !stack.empty()){
            while(cur!=NULL) {
                stack.push_back(cur);
                cur = cur->left;
            }
            cur = stack.back();
            stack.pop_back();

            if (hash_set.count(cur->val)) 
                return true;
            hash_set.insert(k - cur->val);
            cur = cur->right;
        }
        return false;

        vector<int> nums;
        Inorder(root, nums);
        
        int i = 0, j = nums.size()-1;
        while (i < j) {
            int sum = nums[i] + nums[j];
            if (sum == k) return true;
            else if (sum > k) j -= 1;
            else i += 1;
        }
        return false;
    }
    
    void Inorder(TreeNode* root, vector<int>& nums) {
        if (!root) return;
        Inorder(root->left, nums);
        nums.push_back(root->val);
        Inorder(root->right, nums);
    }
};
// @lc code=end

