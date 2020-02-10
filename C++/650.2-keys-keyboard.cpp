/*
 * @lc app=leetcode id=650 lang=cpp
 *
 * [650] 2 Keys Keyboard
 *
 * https://leetcode.com/problems/2-keys-keyboard/description/
 *
 * algorithms
 * Medium (48.06%)
 * Likes:    885
 * Dislikes: 69
 * Total Accepted:    45.3K
 * Total Submissions: 94.2K
 * Testcase Example:  '3'
 *
 * Initially on a notepad only one character 'A' is present. You can perform
 * two operations on this notepad for each step:
 * 
 * 
 * Copy All: You can copy all the characters present on the notepad (partial
 * copy is not allowed).
 * Paste: You can paste the characters which are copied last time.
 * 
 * 
 * 
 * 
 * Given a number n. You have to get exactly n 'A' on the notepad by performing
 * the minimum number of steps permitted. Output the minimum number of steps to
 * get n 'A'.
 * 
 * Example 1:
 * 
 * 
 * Input: 3
 * Output: 3
 * Explanation:
 * Intitally, we have one character 'A'.
 * In step 1, we use Copy All operation.
 * In step 2, we use Paste operation to get 'AA'.
 * In step 3, we use Paste operation to get 'AAA'.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The n will be in the range [1, 1000].
 * 
 * 
 * 
 * 
 */
#include<vector>
#include<math.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int minSteps(int n) {
        // 0: 0
        // 1: 0
        // 2: 2
        // 3: 3
        // 4: 4
        // 5: dp[4]+1=5
        // 6: dp[3]+2=5

        if (n == 1) return 0;
        for (int i=2; i<n; i++)
            if (n%i==0) 
                // paste+dp[n/i]
                return i + minSteps(n/i);
        return n;

        vector<int> dp(n+1, 0);
        for (int i=2; i<=n; i++) {
            dp[i] = i;
            for (int j=2; j<i; j++) 
                if (i%j==0) {
                    dp[i] = dp[i/j] + j;
                    break;
                }
        }
        return dp[n];
    }
};
// @lc code=end

