/*
 * @lc app=leetcode id=114 lang=cpp
 *
 * [114] Flatten Binary Tree to Linked List
 *
 * https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/
 *
 * algorithms
 * Medium (45.32%)
 * Likes:    1992
 * Dislikes: 257
 * Total Accepted:    284.9K
 * Total Submissions: 626.7K
 * Testcase Example:  '[1,2,5,3,4,null,6]'
 *
 * Given a binary tree, flatten it to a linked list in-place.
 * 
 * For example, given the following tree:
 * 
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   5
 * ⁠/ \   \
 * 3   4   6
 * 
 * 
 * The flattened tree should look like:
 * 
 * 
 * 1
 * ⁠\
 * ⁠ 2
 * ⁠  \
 * ⁠   3
 * ⁠    \
 * ⁠     4
 * ⁠      \
 * ⁠       5
 * ⁠        \
 * ⁠         6
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
    void flatten(TreeNode* root) {
        while (root) {
            // if (root->left && root->right) {
            // }
            if(root->left) {
                TreeNode *tmp = root->left;
                while (tmp->right) {
                    tmp = tmp->right;
                }
                tmp->right = root->right;
                root->right = root->left;
                root->left = NULL;
            }
            root = root->right;
        }

        if (root==NULL) return;
        
        flatten(root->left);
        flatten(root->right);
        
        TreeNode* right = root->right;
        if (root->left!=NULL) {
            root->right = root->left;
            root->left = NULL;
            
            while (root->right!=NULL)
                root = root->right;
            root->right = right;
        } 
    }
};
// @lc code=end

TreeNode* createTree(vector<int>& nums) {
    int n = nums.size();

    if (n==0) return NULL;

    vector<TreeNode*> tree(n);
    for(int i=0; i<n; i++) {
        if (nums[i]==-1){
            tree[i] = NULL;
            continue;
        }
        tree[i] = new TreeNode(nums[i]);
    }
    
    int pos=1;
    for(int i=0; i<n && pos<n; i++) {
        if (tree[i]){
            tree[i]->left = tree[pos++];
            if (pos<n){
                tree[i]->right = tree[pos++];
            }
        }
    }
    return tree[0];
}


int main() {
    vector<int> nums{1, 2, 3, -1, 4, -1, -1};
    TreeNode* root = createTree(nums);
}