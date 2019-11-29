/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] Binary Tree Postorder Traversal
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;

        if (!root) return res;

        vector<tuple<TreeNode*, bool>> stack;
        stack.push_back(make_tuple(root, false));

        while (stack.size() > 0) {
            TreeNode *cur = get<0>(stack.back());
            bool visited = get<1>(stack.back());
            stack.pop_back();

            if (cur!=NULL) {
                if (visited) 
                    res.push_back(cur->val);
                else {
                    stack.push_back(make_tuple(cur, true));
                    stack.push_back(make_tuple(cur->right, false));
                    stack.push_back(make_tuple(cur->left, false));
                }
            }
        }
        return res;

        // vector<int> res;
        // if (!root) return res;

        // vector<TreeNode*> stack;
        // stack.push_back(root);

        // while (stack.size()>0) {
        //     TreeNode *cur = stack.back();
        //     stack.pop_back();

        //     res.push_back(cur->val);
        //     if (cur->left) stack.push_back(cur->left);
        //     if (cur->right) stack.push_back(cur->right);
        // }
        // reverse(res.begin(), res.end());
        // return res;
    }
};
// @lc code=end

