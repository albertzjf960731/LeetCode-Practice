/*
 * @lc app=leetcode id=437 lang=cpp
 *
 * [437] Path Sum III
 *
 * https://leetcode.com/problems/path-sum-iii/description/
 *
 * algorithms
 * Easy (44.71%)
 * Likes:    2676
 * Dislikes: 197
 * Total Accepted:    148.8K
 * Total Submissions: 332.6K
 * Testcase Example:  '[10,5,-3,3,2,null,11,3,-2,null,1]\n8'
 *
 * You are given a binary tree in which each node contains an integer value.
 * 
 * Find the number of paths that sum to a given value.
 * 
 * The path does not need to start or end at the root or a leaf, but it must go
 * downwards
 * (traveling only from parent nodes to child nodes).
 * 
 * The tree has no more than 1,000 nodes and the values are in the range
 * -1,000,000 to 1,000,000.
 * 
 * Example:
 * 
 * root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8
 * 
 * ⁠     10
 * ⁠    /  \
 * ⁠   5   -3
 * ⁠  / \    \
 * ⁠ 3   2   11
 * ⁠/ \   \
 * 3  -2   1
 * 
 * Return 3. The paths that sum to 8 are:
 * 
 * 1.  5 -> 3
 * 2.  5 -> 2 -> 1
 * 3. -3 -> 11
 * 
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
    // int pathSum(TreeNode* root, int sum) {
    // 时间复杂度为O(N2)。递归栈的最大深度为logN，因此空间复杂度为O(logN)。
    //     if (root==NULL) return 0;
    //     return pathSumWithRoot(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    // }

    // int pathSumWithRoot(TreeNode* root, int sum) {
    //     int ans = 0;
    //     if (root==NULL) return ans;
        
    //     if (root->val == sum)
    //         ans += 1;
    //     ans += pathSumWithRoot(root->left, sum-root->val);
    //     ans += pathSumWithRoot(root->right, sum-root->val);
    //     return ans;
    // }

    int pathSum(TreeNode* root, int sum) {
        unordered_map<int, int> hash_map{{0, 1}};
        
        int ans = 0;
        DFS(root, hash_map, 0, sum, ans);
        return ans;
    }
    // 前缀和
    void DFS(TreeNode *node, unordered_map<int, int> &hash_map, int path, int target, int &ans) {
        if (node==NULL) return;

        path += node->val;
        if (hash_map.count(path-target)) 
            ans += hash_map[path-target];
        
        hash_map[path]++;
        DFS(node->left, hash_map, path, target, ans);
        DFS(node->right, hash_map, path, target, ans);
        hash_map[path]--;
    }

};
// @lc code=end

