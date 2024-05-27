/*
 * @lc app=leetcode id=877 lang=cpp
 *
 * [877] Stone Game
 *
 * https://leetcode.com/problems/stone-game/description/
 *
 * algorithms
 * Medium (69.73%)
 * Likes:    2668
 * Dislikes: 2573
 * Total Accepted:    189.3K
 * Total Submissions: 271.1K
 * Testcase Example:  '[5,3,4,5]'
 *
 * Alice and Bob play a game with piles of stones. There are an even number of
 * piles arranged in a row, and each pile has a positive integer number of
 * stones piles[i].
 * 
 * The objective of the game is to end with the most stones. The total number
 * of stones across all the piles is odd, so there are no ties.
 * 
 * Alice and Bob take turns, with Alice starting first. Each turn, a player
 * takes the entire pile of stones either from the beginning or from the end of
 * the row. This continues until there are no more piles left, at which point
 * the person with the most stones wins.
 * 
 * Assuming Alice and Bob play optimally, return true if Alice wins the game,
 * or false if Bob wins.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: piles = [5,3,4,5]
 * Output: true
 * Explanation: 
 * Alice starts first, and can only take the first 5 or the last 5.
 * Say she takes the first 5, so that the row becomes [3, 4, 5].
 * If Bob takes 3, then the board is [4, 5], and Alice takes 5 to win with 10
 * points.
 * If Bob takes the last 5, then the board is [3, 4], and Alice takes 4 to win
 * with 9 points.
 * This demonstrated that taking the first 5 was a winning move for Alice, so
 * we return true.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: piles = [3,7,2,3]
 * Output: true
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 2 <= piles.length <= 500
 * piles.length is even.
 * 1 <= piles[i] <= 500
 * sum(piles[i]) is odd.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        // 可以在第⼀步就观察好，奇数堆的⽯头总数多，还是偶数堆的 ⽯头总数多，
        return true;
    
        // 其中 dp[i][j] 表示在区间 [i, j] 内 Alex 比 Lee 多拿的石子数
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i=0; i<n; ++i) 
            dp[i][i] = piles[i];
        for (int len=2; len<=n; ++len) {
        	for (int i=0; i<n-len+1; ++i) {
                int j = i+len-1;
        		dp[i][j] = max(piles[i] - dp[i+1][j], 
                               piles[j] - dp[i][j-1]);
        	}
        }
        return dp[0][n-1] > 0;
    }
};
// @lc code=end

