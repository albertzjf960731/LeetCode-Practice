/*
 * @lc app=leetcode id=236 lang=cpp
 *
 * [236] Lowest Common Ancestor of a Binary Tree
 *
 * https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/
 *
 * algorithms
 * Medium (42.23%)
 * Likes:    2871
 * Dislikes: 157
 * Total Accepted:    385.1K
 * Total Submissions: 911.6K
 * Testcase Example:  '[3,5,1,6,2,0,8,null,null,7,4]\n5\n1'
 *
 * Given a binary tree, find the lowest common ancestor (LCA) of two given
 * nodes in the tree.
 * 
 * According to the definition of LCA on Wikipedia: “The lowest common ancestor
 * is defined between two nodes p and q as the lowest node in T that has both p
 * and q as descendants (where we allow a node to be a descendant of itself).”
 * 
 * Given the following binary tree:  root = [3,5,1,6,2,0,8,null,null,7,4]
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
 * Output: 3
 * Explanation: The LCA of nodes 5 and 1 is 3.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
 * Output: 5
 * Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant
 * of itself according to the LCA definition.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * All of the nodes' values will be unique.
 * p and q are different and both values will exist in the binary tree.
 * 
 * 
 */

/**
 * Definition for a binary tree node.
 */
#include<vector>
#include<unordered_map>
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 以根节点为起点，往左右分支上寻找，如果找到了 p 或 q 节点，则返回该节点。否则，继续向叶子节点寻找，假想一下，如果一直递归到 null 还是找不到该节点，那么说明这个分支上不存在该节点。

        if (!root) 
            return NULL;
        if (p==root || q==root)
            return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if (left!=NULL && right!=NULL)
            return root;
        if (left!=NULL)
            return left;
        if (right!=NULL)
            return right;
    }

    unordered_map<TreeNode*, TreeNode*> pat_map;  // son=>parent  

    void findParent(TreeNode* node, TreeNode* parent){
        if(node) {
            pat_map[node] = parent;
            findParent(node->left, node);
            findParent(node->right, node);
        }
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)  {
        findParent(root, NULL);

        unordered_set<TreeNode*> node_set;

        TreeNode* curr;
        curr = p;
        while (curr != NULL) {
            node_set.insert(curr);
            curr = pat_map[curr];
        }

        curr = q;
        while (curr != NULL) {
            if (node_set.count(curr)) 
                return curr;
            curr = pat_map[curr];
        }
        return curr;
    }
};
// @lc code=end
