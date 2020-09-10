/*
 * @lc app=leetcode id=1259 lang=cpp
 *
 * [1259] Handshakes That Don't Cross
 *
 * You are given an even number of people num_people that stand around a circle and each person shakes hands with someone else, so that there are num_people / 2 handshakes total.
 * 
 * Return the number of ways these handshakes could occur such that none of the handshakes cross.
 * 
 * Since this number could be very big, return the answer mod 10^9 + 7
 * 
 * Example 1:
 * Input: num_people = 2
 * Output: 1
 * 
 * Input: num_people = 4
 * Output: 2
 * Explanation: There are two ways to do it, the first way is [(1,2),(3,4)] and the second one is [(2,3),(4,1)].
 * 
 * Input: num_people = 6
 * Output: 5
 * 
 * Example 4:
 * Input: num_people = 8
 * Output: 14
 * 
 * Constraints:
 * 2 <= num_people <= 1000
 * num_people % 2 == 0
 * 
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    #define LL long long
    int numberOfWays(int num_people) {
        int mode = 1e9 + 7;

        vector<int> dp(num_people + 1, 0);
        dp[0] = 1;

        for (int i=2; i<=num_people; i+=2)
            for (int j=1; j<i; j+=2)
                dp[i] += (dp[j-1]) * dp[i-j-1] % mode;

        return dp[num_people];
    }
};
// @lc code=end

