/*
 * @lc app=leetcode id=634 lang=cpp
 *
 * [634] Find the Derangement of An Array
 *
 * In combinatorial mathematics, a derangement is a permutation of the elements of a set, such that no element appears in its original position.
 * 
 * There's originally an array consisting of n integers from 1 to n in ascending order, you need to find the number of derangement it can generate.
 * 
 * Also, since the answer may be very large, you should return the output mod 109 + 7.
 * 
 * Example 1:
 * 
 * Input: 3
 * Output: 2
 * Explanation: The original array is [1,2,3]. The two derangements are [2,3,1] and [3,1,2].
 *
 * Note:
 * n is in the range of [1, 106].
 * 
 * 
 */
# include<vector>
using namespace std; 

// @lc code=start
class Solution {
public:
    int findDerangement(int n) {
        if (n==1) return 0;
        if (n==2) return 1;

        // 定义一个数组 dp 存储错误方式数量，dp[i] 表示前 i 个信和信封的错误方式数量。假设第 i 个信装到第 j 个信封里面，而第 j 个信装到第 k 个信封里面。根据 i 和 k 是否相等，有两种情况：

        // i==k，交换 i 和 j 的信后，它们的信和信封在正确的位置，但是其余 i-2 封信有 dp[i-2] 种错误装信的方式。由于 j 有 i-1 种取值，因此共有 (i-1)*dp[i-2] 种错误装信方式。
        // i != k，交换 i 和 j 的信后，第 i 个信和信封在正确的位置，其余 i-1 封信有 dp[i-1] 种错误装信方式。由于 j 有 i-1 种取值，因此共有 (i-1)*dp[i-1] 种错误装信方式。

        int ans = 0;
        int a=0, b=1;
        for (int i=3; i <= n; ++i) {
            ans = (i - 1) * (a + b);
            a = b;
            b = ans;
        }
        return ans;
    }
};
// @lc code=end

