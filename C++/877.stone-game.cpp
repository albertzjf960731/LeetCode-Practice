/*
 * @lc app=leetcode id=877 lang=cpp
 *
 * [877] Stone Game
 */
#include<vector>
using namespace std;

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

