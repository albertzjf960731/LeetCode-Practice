/*
 * @lc app=leetcode id=926 lang=cpp
 *
 * [926] Flip String to Monotone Increasing
 *
 * https://leetcode.com/problems/flip-string-to-monotone-increasing/description/
 *
 * algorithms
 * Medium (59.59%)
 * Likes:    3887
 * Dislikes: 166
 * Total Accepted:    163.5K
 * Total Submissions: 266.1K
 * Testcase Example:  '"00110"'
 *
 * A binary string is monotone increasing if it consists of some number of 0's
 * (possibly none), followed by some number of 1's (also possibly none).
 * 
 * You are given a binary string s. You can flip s[i] changing it from 0 to 1
 * or from 1 to 0.
 * 
 * Return the minimum number of flips to make s monotone increasing.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "00110"
 * Output: 1
 * Explanation: We flip the last digit to get 00111.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "010110"
 * Output: 2
 * Explanation: We flip to get 011111, or alternatively 000111.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "00011000"
 * Output: 2
 * Explanation: We flip to get 00000000.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 10^5
 * s[i] is either '0' or '1'.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int cur = 0;
        for (int c: s) if (c == '0') cur += 1;
        
        int ans = cur;
        for (char c: s) {
            cur += c=='0' ? -1 : 1;
            ans = min(ans, cur);
        }
        return ans;


        vector<int> left(s.size() + 1), right(s.size() + 1);
        for (int i=1, j=s.size()-1; j>=0; ++i, --j) {
            left[i] += left[i-1] + (s[i-1]=='0' ? 0 : 1);
            right[j] += right[j+1] + (s[j]=='1' ? 0 : 1);
        }

        int ans = INT_MAX;
        for (int i=0; i<=s.size(); ++i) 
            ans = min(ans, left[i] + right[i]);
        return ans;

    }
};
// @lc code=end

