/*
 * @lc app=leetcode id=887 lang=cpp
 *
 * [887] Super Egg Drop
 *
 * https://leetcode.com/problems/super-egg-drop/description/
 *
 * algorithms
 * Hard (27.02%)
 * Likes:    943
 * Dislikes: 86
 * Total Accepted:    21.1K
 * Total Submissions: 78.1K
 * Testcase Example:  '1\n2'
 *
 * You are given K eggs, and you have access to a building with N floors from 1
 * to N. 
 * 
 * Each egg is identical in function, and if an egg breaks, you cannot drop it
 * again.
 * 
 * You know that there exists a floor F with 0 <= F <= N such that any egg
 * dropped at a floor higher than F will break, and any egg dropped at or below
 * floor F will not break.
 * 
 * Each move, you may take an egg (if you have an unbroken one) and drop it
 * from any floor X (with 1 <= X <= N). 
 * 
 * Your goal is to know with certainty what the value of F is.
 * 
 * What is the minimum number of moves that you need to know with certainty
 * what F is, regardless of the initial value of F?
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
 * Input: K = 1, N = 2
 * Output: 2
 * Explanation: 
 * Drop the egg from floor 1.  If it breaks, we know with certainty that F = 0.
 * Otherwise, drop the egg from floor 2.  If it breaks, we know with certainty
 * that F = 1.
 * If it didn't break, then we know with certainty F = 2.
 * Hence, we needed 2 moves in the worst case to know what F is with
 * certainty.
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: K = 2, N = 6
 * Output: 3
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: K = 3, N = 14
 * Output: 4
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= K <= 100
 * 1 <= N <= 10000
 * 
 * 
 * 
 * 
 * 
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int superEggDrop(int K, int N) {
        vector<vector<int>> dp(K+1, vector<int>(N+1));
        
        for (int h=1; h<=N; ++h) dp[1][h] = h;
        
        for (int k=2; k<=K; ++k) {
            for (int h=1; h<=N; ++h) {
                dp[k][h] = h;
                // for (int i=1; i<h; ++i) {
                //     dp[k][h] = min(dp[k][h], 
                //                    max(dp[k-1][i-1], dp[k][h-i]) + 1);
                // }
				int left = 1, right = h;
				while (left < right) {
					int mid = left + (right - left) / 2;
					if (dp[k-1][mid-1] < dp[k][h-mid]) left = mid + 1;
					else right = mid;
				}
				dp[k][h] = min(dp[k][h], 
                               max(dp[k-1][left-1], dp[k][h-left]) + 1);
            }
        }
        return dp[K][N];

		// vector<vector<int>> dp(K + 1, vector<int>(N + 1));
        
		// for (int h=1; h<=N; ++h) dp[1][h] = h;
        
		// for (int n_egg=2; n_egg<=K; ++n_egg) {
		// 	int s = 1;
		// 	for (int h=1; h<=N; ++h) {
		// 		dp[n_egg][h] = h;
		// 		while (s<h && dp[n_egg-1][s-1]<dp[n_egg][h-s]) 
        //             ++s;
		// 		dp[n_egg][h] = min(dp[n_egg][h], 
        //                            max(dp[n_egg-1][s-1], dp[n_egg][h-s]) + 1);
		// 	}
		// }
		// return dp[K][N];

        // 用一个二维 DP 数组，其中 dp[i][j] 表示当有i次操作，且有j个鸡蛋时能测出的最高的楼层数。再来考虑状态转移方程如何写，由于 dp[i][j] 表示的是在第i次移动且使用第j个鸡蛋测试第 dp[i-1][j-1]+1 层，因为上一个状态是第i-1次移动，且用第j-1个鸡蛋。此时还是有两种情况：

        // 鸡蛋碎掉：说明至少可以测到的不会碎的层数就是 dp[i-1][j-1]。
        // 鸡蛋没碎：那这个鸡蛋可以继续利用，此时我们还可以再向上查找 dp[i-1][j] 层。
        // 那么加上当前层，总共可以通过i次操作和j个鸡蛋查找的层数范围是 [0, dp[i-1][j-1] + dp[i-1][j] + 1]，这样就可以得到状态转移方程如下：

        // dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j] + 1

        // 当 dp[i][K] 正好小于N的时候，i就是我们要求的最小次数了

		vector<vector<int>> dp(N+1, vector<int>(K+1));
        
		for (int m=1; m<=N; ++m) {
			for (int j=1; j<=K; ++j) {
				dp[m][j] = dp[m-1][j-1] + dp[m-1][j]+1;
			}
            if (dp[m][K] >= N) return m;
		}
        return -1;
    }
};
// @lc code=end

