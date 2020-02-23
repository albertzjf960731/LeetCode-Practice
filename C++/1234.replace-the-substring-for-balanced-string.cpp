/*
 * @lc app=leetcode id=1234 lang=cpp
 *
 * [1234] Replace the Substring for Balanced String
 *
 * https://leetcode.com/problems/replace-the-substring-for-balanced-string/description/
 *
 * algorithms
 * Medium (31.33%)
 * Likes:    161
 * Dislikes: 32
 * Total Accepted:    6.8K
 * Total Submissions: 21.8K
 * Testcase Example:  '"QWER"'
 *
 * You are given a string containing only 4 kinds of characters 'Q', 'W', 'E'
 * and 'R'.
 * 
 * A string is said to be balanced if each of its characters appears n/4 times
 * where n is the length of the string.
 * 
 * Return the minimum length of the substring that can be replaced with any
 * other string of the same length to make the original string s balanced.
 * 
 * Return 0 if the string is already balanced.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "QWER"
 * Output: 0
 * Explanation: s is already balanced.
 * 
 * Example 2:
 * 
 * 
 * Input: s = "QQWE"
 * Output: 1
 * Explanation: We need to replace a 'Q' to 'R', so that "RQWE" (or "QRWE") is
 * balanced.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "QQQW"
 * Output: 2
 * Explanation: We can replace the first "QQ" to "ER". 
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: s = "QQQQ"
 * Output: 3
 * Explanation: We can replace the last 3 'Q' to make s = "QWER".
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 10^5
 * s.length is a multiple of 4
 * s contains only 'Q', 'W', 'E' and 'R'.
 * 
 * 
 */
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

// @lc code=start
class Solution {
public:
    int balancedString(string s) {
//         unordered_map<char, int> cnts;
//         for (char ch: s) cnts[ch] ++;
        
//         int cnt = 0;
//         for(auto it: cnts) {
//             if (it.second > s.size()/4) {
//                 cnts[it.first] = it.second-s.size()/4;
//                 cnt += cnts[it.first];
//             }
//             else 
//                 cnts[it.first] = 0;
//         }
//         int ans = s.size();
//         for (int left=0, right=0; right<s.size(); right++) {
//             char ch_r = s[right];
//             if (cnts[ch_r] > 0)
//                 cnt --;
//             cnts[ch_r]--;

//             while (cnt==0) {
//                 ans = min(ans, right-left+1);
                
//                 char ch_left = s[left];
//                 if(cnts[ch_left]==0) 
//                     cnt++;
//                 cnts[ch_left]++;
//                 left++;
//             }
//         }
//         return ans;
        
        unordered_map<char, int> counts;
        int n = s.size(), ans = n, k = n / 4;
        for (int i = 0; i < n; ++i) {
            counts[s[i]]++;
        }
        for (int i = 0, j = 0; j < n; ++j) {
            counts[s[j]]--;
            while (i<n && counts['Q']<=k && counts['W']<=k && counts['E']<=k && counts['R']<=k) {
                ans = min(ans, j-i+1);
                counts[s[i++]] += 1;
            }
        }
        return ans;
 
    }
};
// @lc code=end

