/*
 * @lc app=leetcode id=589 lang=cpp
 *
 * [589] N-ary Tree Preorder Traversal
 *
 * https://leetcode.com/problems/n-ary-tree-preorder-traversal/description/
 *
 * algorithms
 * Easy (70.13%)
 * Likes:    398
 * Dislikes: 51
 * Total Accepted:    78.6K
 * Total Submissions: 112.1K
 * Testcase Example:  '[1,null,3,2,4,null,5,6]'
 *
 * Given an n-ary tree, return the preorder traversal of its nodes' values.
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
 * Output: [1,3,5,6,2,4]
 * 
 * 
 * Example 2:
 * 
 * 
 * 
 * 
 * Input: root =
 * [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
 * Output: [1,2,3,6,7,11,14,4,8,12,5,9,13,10]
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
    vector<int> preorder(Node* root) {
        vector<int> res;

        if (!root) return res;

        vector<Node*> stack;
        stack.push_back(root);
        while (stack.size() > 0) {
            Node *cur = stack.back();
            stack.pop_back();

            if (cur!=NULL) {
                res.push_back(cur->val);
                
                vector<Node*> children = cur->children;
                for(auto child=children.rbegin(); child!=children.rend(); child++)
                    stack.push_back(*child);
            }
        }
        return res;

        // vector<int> res;
        // DFS(root, res);
        // return res;
    }

    // void DFS(Node* node, vector<int>& res) {
    //     if (node==NULL) return;
    //     res.push_back(node->val);
    //     for(auto child: node->children)
    //         DFS(child, res);
    // }
};
// @lc code=end

