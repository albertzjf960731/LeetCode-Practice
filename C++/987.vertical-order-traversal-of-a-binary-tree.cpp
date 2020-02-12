/*
 * @lc app=leetcode id=987 lang=cpp
 *
 * [987] Vertical Order Traversal of a Binary Tree
 *
 * https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/description/
 *
 * algorithms
 * Medium (34.11%)
 * Likes:    286
 * Dislikes: 708
 * Total Accepted:    29.4K
 * Total Submissions: 86.1K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the vertical order traversal of its nodes
 * values.
 * 
 * For each node at position (X, Y), its left and right children respectively
 * will be at positions (X-1, Y-1) and (X+1, Y-1).
 * 
 * Running a vertical line from X = -infinity to X = +infinity, whenever the
 * vertical line touches some nodes, we report the values of the nodes in order
 * from top to bottom (decreasing Y coordinates).
 * 
 * If two nodes have the same position, then the value of the node that is
 * reported first is the value that is smaller.
 * 
 * Return an list of non-empty reports in order of X coordinate.  Every report
 * will have a list of values of nodes.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * 
 * Input: [3,9,20,null,null,15,7]
 * Output: [[9],[3,15],[20],[7]]
 * Explanation: 
 * Without loss of generality, we can assume the root node is at position (0,
 * 0):
 * Then, the node with value 9 occurs at position (-1, -1);
 * The nodes with values 3 and 15 occur at positions (0, 0) and (0, -2);
 * The node with value 20 occurs at position (1, -1);
 * The node with value 7 occurs at position (2, -2).
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * 
 * 
 * Input: [1,2,3,4,5,6,7]
 * Output: [[4],[2],[1,5,6],[3],[7]]
 * Explanation: 
 * The node with value 5 and the node with value 6 have the same position
 * according to the given scheme.
 * However, in the report "[1,5,6]", the node value of 5 comes first since 5 is
 * smaller than 6.
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The tree will have between 1 and 1000 nodes.
 * Each node's value will be between 0 and 1000.
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 */
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>

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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, set<int>>> coords;

        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();

            TreeNode* node = cur.first;
            int x=cur.second.first, y=cur.second.second;
            coords[x][y].insert(node->val);
            if (node -> left) q.push({node->left, {x-1, y+1}});
            if (node -> right) q.push({node->right, {x+1, y+1}});
        }

        vector<vector<int>> res;
        for (auto itx=coords.begin(); itx!=coords.end(); itx++) {
            vector<int> col;
            for (auto ity=itx->second.begin(); ity!=itx->second.end(); ity++) {
                col.insert(col.end(), ity->second.begin(), ity->second.end());
            }
            res.push_back(col);
        }
        return res;
    }
};
// @lc code=end

