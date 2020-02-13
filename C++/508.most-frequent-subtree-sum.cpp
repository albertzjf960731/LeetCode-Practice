/*
 * @lc app=leetcode id=508 lang=cpp
 *
 * [508] Most Frequent Subtree Sum
 *
 * https://leetcode.com/problems/most-frequent-subtree-sum/description/
 *
 * algorithms
 * Medium (56.52%)
 * Likes:    506
 * Dislikes: 98
 * Total Accepted:    61.3K
 * Total Submissions: 108.4K
 * Testcase Example:  '[5,2,-3]'
 *
 * 
 * Given the root of a tree, you are asked to find the most frequent subtree
 * sum. The subtree sum of a node is defined as the sum of all the node values
 * formed by the subtree rooted at that node (including the node itself). So
 * what is the most frequent subtree sum value? If there is a tie, return all
 * the values with the highest frequency in any order.
 * 
 * 
 * Examples 1
 * Input:
 * 
 * ⁠ 5
 * ⁠/  \
 * 2   -3
 * 
 * return [2, -3, 4], since all the values happen only once, return all of them
 * in any order.
 * 
 * 
 * Examples 2
 * Input:
 * 
 * ⁠ 5
 * ⁠/  \
 * 2   -5
 * 
 * return [2], since 2 happens twice, however -5 only occur once.
 * 
 * 
 * Note:
 * You may assume the sum of values in any subtree is in the range of 32-bit
 * signed integer.
 * 
 */

#include<vector>
#include<unordered_map>
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
    // vector<int> findFrequentTreeSum(TreeNode* root) {
    //     unordered_map<TreeNode*, int> hash_map;
    //     DFS(root, hash_map);
        
    //     unordered_map<int, int> cnts;
    //     for(auto it=hash_map.begin(); it!=hash_map.end(); it++) 
    //         cnts[it->second]++;

    //     int mode = INT_MIN;
    //     vector<int> res;
    //     for(auto it=cnts.begin(); it!=cnts.end(); it++) {
    //         if (it->second==mode) 
    //             res.push_back(it->first);
    //         else if (it->second > mode) {
    //             mode = it->second;
    //             res.clear();
    //             res.push_back(it->first);
    //         }
    //     }
    //     return res;
    // }
    
    // void DFS(TreeNode* node, unordered_map<TreeNode*, int>& hash_map) {
    //     if (node==NULL)
    //         return;
    //     DFS(node->left, hash_map);
    //     DFS(node->right, hash_map);
        
    //     int sum = node->val;
    //     if (node->left!=NULL)
    //         sum += hash_map[node->left];
    //     if (node->right!=NULL)
    //         sum += hash_map[node->right];
    //     hash_map[node] = sum;
    // }

    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> cnts;
        int mode = 0;
        DFS(root, mode, cnts);
        
        vector<int> res;
        for(auto it=cnts.begin(); it!=cnts.end(); it++) {
            if (it->second==mode) {
                mode = it->second;
                res.push_back(it->first);
            }
        }
        return res;
    }
    
    int DFS(TreeNode* node, int& mode, unordered_map<int, int>& cnts) {
        if (node==NULL) return 0;

        int sum = DFS(node->left, mode, cnts) + DFS(node->right, mode, cnts) + node->val;
        mode = max(mode, ++cnts[sum]);
        return sum;
    }
};
// @lc code=end

