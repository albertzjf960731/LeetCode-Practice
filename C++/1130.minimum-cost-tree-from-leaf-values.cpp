/*
 * @lc app=leetcode id=1130 lang=cpp
 *
 * [1130] Minimum Cost Tree From Leaf Values
 *
 * https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/description/
 *
 * algorithms
 * Medium (66.18%)
 * Likes:    1445
 * Dislikes: 115
 * Total Accepted:    38.9K
 * Total Submissions: 58K
 * Testcase Example:  '[6,2,4]'
 *
 * Given an array arr of positive integers, consider all binary trees such
 * that:
 * 
 * 
 * Each node has either 0 or 2 children;
 * The values of arr correspond to the values of each leaf in an in-order
 * traversal of the tree.  (Recall that a node is a leaf if and only if it has
 * 0 children.)
 * The value of each non-leaf node is equal to the product of the largest leaf
 * value in its left and right subtree respectively.
 * 
 * 
 * Among all possible binary trees considered, return the smallest possible sum
 * of the values of each non-leaf node.  It is guaranteed this sum fits into a
 * 32-bit integer.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: arr = [6,2,4]
 * Output: 32
 * Explanation:
 * There are two possible trees.  The first has non-leaf node sum 36, and the
 * second has non-leaf node sum 32.
 * 
 * ⁠   24            24
 * ⁠  /  \          /  \
 * ⁠ 12   4        6    8
 * ⁠/  \               / \
 * 6    2             2   4
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 2 <= arr.length <= 40
 * 1 <= arr[i] <= 15
 * It is guaranteed that the answer fits into a 32-bit signed integer (ie. it
 * is less than 2^31).
 * 
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int mctFromLeafValues(vector<int>& nums) {
        // dp[i, j] = dp[i, k] + dp[k + 1, j] + max(A[i, k]) * max(A[k + 1, j])
        int n = nums.size();
        vector<vector<pair<int, int>>> dp(n, 
                                    vector<pair<int, int>>(n, {INT_MAX, 0}));
        for(int i=0; i<n; i++) {
            dp[i][i].first = 0;       //sum
            dp[i][i].second = nums[i]; //maxval
        }
        
        for(int len=1; len<=n; ++len) {
            for(int i=0; i<n-len+1; ++i) {
                int j = i+len-1;
                for(int k=i; k<j; ++k) {
                    int val = dp[i][k].first+dp[k+1][j].first+
                        dp[i][k].second*dp[k+1][j].second;
                    if(dp[i][j].first > val) {               
                        dp[i][j].first = val;  
                        dp[i][j].second = max(dp[i][k].second, dp[k+1][j].second);
                    }
                }
            }
        }
        return dp[0][n-1].first;

        int ans = 0;
        vector<int> stack = {INT_MAX};
        for (int num : nums) {
            while (stack.back() <= num) {
                int mid = stack.back();
                stack.pop_back();
                ans += mid * min(stack.back(), num);
            }
            stack.push_back(num);
        }
        
        for (int i=2; i<stack.size(); ++i) {
            ans += stack[i] * stack[i-1];
        }
        return ans;

    }
};
// @lc code=end

