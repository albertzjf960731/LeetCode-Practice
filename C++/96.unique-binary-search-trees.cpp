/*
 * @lc app=leetcode id=96 lang=cpp
 *
 * [96] Unique Binary Search Trees
 *
 * https://leetcode.com/problems/unique-binary-search-trees/description/
 *
 * algorithms
 * Medium (48.75%)
 * Likes:    2383
 * Dislikes: 90
 * Total Accepted:    239.3K
 * Total Submissions: 488.9K
 * Testcase Example:  '3'
 *
 * Given n, how many structurally unique BST's (binary search trees) that store
 * values 1 ... n?
 * 
 * Example:
 * 
 * 
 * Input: 3
 * Output: 5
 * Explanation:
 * Given n = 3, there are a total of 5 unique BST's:
 * 
 * ⁠  1         3     3      2      1
 * ⁠   \       /     /      / \      \
 * ⁠    3     2     1      1   3      2
 * ⁠   /     /       \                 \
 * ⁠  2     1         2                 3
 * 
 * 
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int numTrees(int n) {
        if (n==0) return 0;
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        
        for (int i=1; i<=n; i++) {
            for (int root_idx=1; root_idx<=i; root_idx++) {
                int l_len = root_idx-1;
                int r_len = i-root_idx;
                dp[i] += dp[l_len]*dp[r_len];
            }
        }
        return dp[n];
    }
};
// @lc code=end

