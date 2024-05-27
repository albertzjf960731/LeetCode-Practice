/*
 * @lc app=leetcode id=1140 lang=cpp
 *
 * [1140] Stone Game II
 *
 * https://leetcode.com/problems/stone-game-ii/description/
 *
 * algorithms
 * Medium (64.77%)
 * Likes:    2105
 * Dislikes: 461
 * Total Accepted:    61.8K
 * Total Submissions: 92.1K
 * Testcase Example:  '[2,7,9,4,4]'
 *
 * Alice and Bob continue their games with piles of stones.  There are a number
 * of piles arranged in a row, and each pile has a positive integer number of
 * stones piles[i].  The objective of the game is to end with the most
 * stones. 
 * 
 * Alice and Bob take turns, with Alice starting first.  Initially, M = 1.
 * 
 * On each player's turn, that player can take all the stones in the first X
 * remaining piles, where 1 <= X <= 2M.  Then, we set M = max(M, X).
 * 
 * The game continues until all the stones have been taken.
 * 
 * Assuming Alice and Bob play optimally, return the maximum number of stones
 * Alice can get.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: piles = [2,7,9,4,4]
 * Output: 10
 * Explanation:  If Alice takes one pile at the beginning, Bob takes two piles,
 * then Alice takes 2 piles again. Alice can get 2 + 4 + 4 = 10 piles in total.
 * If Alice takes two piles at the beginning, then Bob can take all three piles
 * left. In this case, Alice get 2 + 7 = 9 piles in total. So we return 10
 * since it's larger. 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: piles = [1,2,3,4,5,100]
 * Output: 104
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= piles.length <= 100
 * 1 <= piles[i] <= 10^4
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
//         在示例 1 中，Alice 一开始有两个选择：拿前一堆/前两堆石子。如果 Alice 拿前一堆，那么轮到 Bob 时，他也可以在剩下的四堆石子中，拿前一堆/前两堆石子。如果 Bob 拿前一堆，那么又轮到 Alice，……

// 不断这样思考下去，可以画出如下搜索树。注意如果可以全部拿完，就全拿。

        // dfs(i,m) 表示前 i 堆石头已经被取走，当前的 M=m 的情况下，接下去取石头的玩家可以比另一方多取的石头数。
        vector<vector<int>> dp(n+1, vector<int>(n+1, INT_MIN));

        for (int i=n; i>=0; --i) {
            for (int m=1; m<=n; ++m) {
                if (i == n) dp[i][m] = 0;
                else {
                    int sum = 0;
                    for (int x=1; x<=2*m; ++x) {
                        if (i + x > n) break;

                        sum += piles[i+x-1];
                        dp[i][m] = max(dp[i][m], sum - dp[i+x][min(n, max(m, x))]);
                    }
                }
            }
        }
        return (dp[0][1] + accumulate(piles.begin(), piles.end(), 0)) / 2;
    }
};
// @lc code=end

