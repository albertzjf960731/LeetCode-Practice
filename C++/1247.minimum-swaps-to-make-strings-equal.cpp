/*
 * @lc app=leetcode id=1247 lang=cpp
 *
 * [1247] Minimum Swaps to Make Strings Equal
 *
 * https://leetcode.com/problems/minimum-swaps-to-make-strings-equal/description/
 *
 * algorithms
 * Medium (63.95%)
 * Likes:    1134
 * Dislikes: 229
 * Total Accepted:    32.7K
 * Total Submissions: 51.2K
 * Testcase Example:  '"xx"\n"yy"'
 *
 * You are given two strings s1 and s2 of equal length consisting of letters
 * "x" and "y" only. Your task is to make these two strings equal to each
 * other. You can swap any two characters that belong to different strings,
 * which means: swap s1[i] and s2[j].
 * 
 * Return the minimum number of swaps required to make s1 and s2 equal, or
 * return -1 if it is impossible to do so.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s1 = "xx", s2 = "yy"
 * Output: 1
 * Explanation: Swap s1[0] and s2[1], s1 = "yx", s2 = "yx".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s1 = "xy", s2 = "yx"
 * Output: 2
 * Explanation: Swap s1[0] and s2[0], s1 = "yy", s2 = "xx".
 * Swap s1[0] and s2[1], s1 = "xy", s2 = "xy".
 * Note that you cannot swap s1[0] and s1[1] to make s1 equal to "yx", cause we
 * can only swap chars in different strings.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s1 = "xx", s2 = "xy"
 * Output: -1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s1.length, s2.length <= 1000
 * s1, s2 only contain 'x' or 'y'.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int minimumSwap(string s1, string s2) {
        if (s1.size() != s2.size()) return -1;

        array<int, 2> cnts;
        for (char c: s1) cnts[c-'x'] += 1;
        for (char c: s2) cnts[c-'x'] += 1;
        if (cnts[0] % 2 ==1 || cnts[1] % 2 == 1) return -1;

        int n = s1.size(), xy = 0, yx = 0;
        for (int i=0; i<n; ++i) {
            if (s1[i]=='x' & s2[i]=='y') xy += 1;
            if (s1[i]=='y' & s2[i]=='x') yx += 1;
        }
        int ans = xy/2 + yx/2;
        if (xy%2==1 && yx%2==1) ans += 2;
        return ans;

    }
};
// @lc code=end

