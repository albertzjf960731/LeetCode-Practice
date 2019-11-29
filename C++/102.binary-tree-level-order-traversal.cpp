/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
 */

/**
 * Definition for a binary tree node.
 */
#include<vector>
#include<iostream>
#include<queue>

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            vector<int> temp;

            int q_size = q.size();
            for (int i=0; i<q_size; i++){
                TreeNode *cur = q.front();
                q.pop();

                temp.push_back(cur->val);
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
            res.push_back(temp);
        }
    return res;
    }
};
// @lc code=end

void printTree(TreeNode *root)
{
    if (root == NULL){
        printf("# ");
        return;
    }
    printf("%d ", root->val );

    printTree(root->left);
    printTree(root->right);
}

void printTree_level_order(TreeNode *root)
{
    queue<TreeNode*> q;
    q.push(root);
    while (q.size()>0){
        TreeNode* n = q.front();
        q.pop();
        if (n==NULL){
            cout << "# ";
            continue;
        }
        cout << n->val << " ";
        q.push(n->left);
        q.push(n->right);
    } 
    cout << endl;
}

TreeNode* createTree(int a[], int n)
{
    if (n<=0) return NULL;

    TreeNode **tree = new TreeNode*[n];

    for(int i=0; i<n; i++) {
        if (a[i]==0 ){
            tree[i] = NULL;
            continue;
        }
        tree[i] = new TreeNode(a[i]);
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

void printMatrix(vector< vector<int> > &vv){
    for(int i=0; i<vv.size(); i++) {
        cout << "[";
        for(int j=0; j<vv[i].size(); j++) {
            cout << " " << vv[i][j];
        }
        cout << "]" << endl;;
    }
}

int main()
{
    Solution sol;
    TreeNode *root;
    vector< vector<int> > vv;

    int nums[] = {3,9,20,0,0,15,7};
    root = createTree(nums, sizeof(nums)/sizeof(int));

    printTree_level_order(root);

    vv = sol.levelOrder(root);
    printMatrix(vv);

    cout << endl;    
}