/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
 */

#include<vector>
#include<stack>
#include<queue>
#include<stack>
#include<iostream>

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<TreeNode*> stack;
        vector<int> res;

        TreeNode *cur = root;
        while (cur!=NULL || stack.size()>0) {
            while (cur!=NULL) {
                stack.push_back(cur);
                cur = cur->left;
            }
            cur = stack.back();
            stack.pop_back();
            res.push_back(cur->val);
            cur = cur->right;
        }

        return res;


        vector<int> res;
        DFS(root, res);
        return res;
    }

    void DFS(TreeNode* node, vector<int>& res) {
        if (node==NULL) return;
        DFS(node->left, res);
        res.push_back(node->val);
        DFS(node->right, res);
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

void printTree(TreeNode *root) {
    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()) {
        TreeNode *node = q.front();
        q.pop();

        if (node==NULL) 
            cout << "# ";
        else {
            cout << node->val << " ";
            q.push(node->left);
            q.push(node->right);
        }
    }
}

int main() {
    vector<int> nums{1, 2, 3, -1, 4, -1, -1};
    TreeNode* root = createTree(nums);

    // Solution sol;
    // vector<int> res = sol.inorderTraversal(root);
    // for (int num: res) cout << num << " ";
    // cout << endl;

    printTree(root);
    cout << endl;
}