/*
 * @lc app=leetcode id=590 lang=cpp
 *
 * [590] N-ary Tree Postorder Traversal
 *
 * https://leetcode.com/problems/n-ary-tree-postorder-traversal/description/
 *
 * algorithms
 * Easy (70.13%)
 * Likes:    465
 * Dislikes: 53
 * Total Accepted:    69.2K
 * Total Submissions: 98.7K
 * Testcase Example:  '[1,null,3,2,4,null,5,6]\r'
 *
 * Given an n-ary tree, return the postorder traversal of its nodes' values.
 * 
 * Nary-Tree input serialization is represented in their level order traversal,
 * each group of children is separated by the null value (See examples).
 * 
 * 
 * 
 * Follow up:
 * 
 * Recursive solution is trivial, could you do it iteratively?
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: root = [1,null,3,2,4,null,5,6]
 * Output: [5,6,3,2,4,1]
 * 
 * 
 * Example 2:
 * 
 * 
 * 
 * 
 * Input: root =
 * [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
 * Output: [2,6,14,11,7,3,12,8,4,13,9,10,5,1]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The height of the n-ary tree is less than or equal to 1000
 * The total number of nodes is between [0, 10^4]
 * 
 * 
 */

#include<vector>
#include<queue>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
// @lc code=start
class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> res;

        if (!root) return res;

        vector<Node*> stack;
        stack.push_back(root);
        while (stack.size() > 0) {
            Node *cur = stack.back();
            stack.pop_back();

            if (cur!=NULL) {
                res.push_back(cur->val);
                
                for(auto child: cur->children)
                    stack.push_back(child);
            }
        }
        reverse(res.begin(), res.end());
        return res;

        // vector<int> res;
        // DFS(root, res);
        // return res;
    }

    // void DFS(Node* node, vector<int>& res) {
    //     if (node==NULL) return;
    //     for(auto child: node->children)
    //         DFS(child, res);
    //     res.push_back(node->val);
    // }
};
// @lc code=end

