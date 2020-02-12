/*
 * @lc app=leetcode id=863 lang=cpp
 *
 * [863] All Nodes Distance K in Binary Tree
 *
 * https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/description/
 *
 * algorithms
 * Medium (52.63%)
 * Likes:    1420
 * Dislikes: 32
 * Total Accepted:    52.4K
 * Total Submissions: 99.4K
 * Testcase Example:  '[3,5,1,6,2,0,8,null,null,7,4]\n5\n2'
 *
 * We are given a binary tree (with root node root), a target node, and an
 * integer value K.
 * 
 * Return a list of the values of all nodes that have a distance K from the
 * target node.  The answer can be returned in any order.
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, K = 2
 * 
 * Output: [7,4,1]
 * 
 * Explanation: 
 * The nodes that are a distance 2 from the target node (with value 5)
 * have values 7, 4, and 1.
 * 
 * 
 * 
 * Note that the inputs "root" and "target" are actually TreeNodes.
 * The descriptions of the inputs above are just serializations of these
 * objects.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The given tree is non-empty.
 * Each node in the tree has unique values 0 <= node.val <= 500.
 * The target node is a node in the tree.
 * 0 <= K <= 1000.
 * 
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
    vector<int> res;   
    unordered_map<TreeNode*, TreeNode*> pat_map;  // son=>parent  
    unordered_set<TreeNode*> visited;    //record visied node
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        if(!root) return {};

        findParent(root, NULL);
        DFS(target, K);
        return res;
    }

    void findParent(TreeNode* node, TreeNode* parent){
        if(node) {
            pat_map[node] = parent;
            findParent(node->left, node);
            findParent(node->right, node);
        }
    }

    void DFS(TreeNode* node, int K){
	    if(node && !visited.count(node)){
			visited.insert(node);
			
			if(K==0) {
				res.push_back(node->val);
				return;
			}
			else {
				DFS(node->left, K-1);
				DFS(node->right, K-1);
				DFS(pat_map[node], K-1);	
			}
		}
    }
};
// @lc code=end

