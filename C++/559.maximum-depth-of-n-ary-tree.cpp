/*
 * @lc app=leetcode id=559 lang=cpp
 *
 * [559] Maximum Depth of N-ary Tree
 *
 * https://leetcode.com/problems/maximum-depth-of-n-ary-tree/description/
 *
 * algorithms
 * Easy (67.25%)
 * Likes:    603
 * Dislikes: 36
 * Total Accepted:    86.1K
 * Total Submissions: 128K
 * Testcase Example:  '[1,null,3,2,4,null,5,6]\r'
 *
 * Given a n-ary tree, find its maximum depth.
 * 
 * The maximum depth is the number of nodes along the longest path from the
 * root node down to the farthest leaf node.
 * 
 * Nary-Tree input serialization is represented in their level order traversal,
 * each group of children is separated by the null value (See examples).
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: root = [1,null,3,2,4,null,5,6]
 * Output: 3
 * 
 * 
 * Example 2:
 * 
 * 
 * 
 * 
 * Input: root =
 * [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
 * Output: 5
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The depth of the n-ary tree is less than or equal to 1000.
 * The total number of nodes is between [0, 10^4].
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
/*
// Definition for a Node.
*/
class Solution {
public:
    int maxDepth(Node* root) {
        // if (!root) return 0;
        // int child_depth = 0;
        // for (auto child: root->children) 
        //     child_depth = max(child_depth, maxDepth(child));
        // return child_depth+1;

        if (!root) return 0;
        
        int ans = 0;
        
        queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
            int q_size = q.size();
            for (int i=0; i<q_size; i++) {
                Node* node = q.front();
                q.pop();
                
                for (auto child: node->children) 
                    q.push(child);
            }
            ans++;
        } 
        return ans;       
    }
};
// @lc code=end

