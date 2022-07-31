/*
 * @lc app=leetcode id=1358 lang=cpp
 *
 * [1358] Number of Substrings Containing All Three Characters
 *
 * https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/description/
 *
 * algorithms
 * Medium (43.05%)
 * Likes:    45
 * Dislikes: 0
 * Total Accepted:    1.8K
 * Total Submissions: 4.2K
 * Testcase Example:  '"abcabc"'
 *
 * Given a string s consisting only of characters a, b and c.
 * 
 * Return the number of substrings containing at least one occurrence of all
 * these characters a, b and c.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "abcabc"
 * Output: 10
 * Explanation: The substrings containing at least one occurrence of the
 * characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab",
 * "bcabc", "cab", "cabc" and "abc" (again). 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "aaacb"
 * Output: 3
 * Explanation: The substrings containing at least one occurrence of the
 * characters a, b and c are "aaacb", "aacb" and "acb". 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "abc"
 * Output: 1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 3 <= s.length <= 5 x 10^4
 * s only consists of a, b or c characters.
 * 
 */
#include<vector>
#include<string>
using namespace std;

// @lc code=start
class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans = 0;
        vector<int> counts(3, 0);
        int left=0, right=0;
        while (right<s.size()) {
            counts[s[right]-'a'] ++;
            right ++;
            
            while (counts[0] && counts[1] && counts[2]) {
                counts[s[left]-'a']--;
                left ++;
            }
            ans += left;
        }
        return ans;

        int ans = 0;
        unordered_map<char, int> cnts;
        
        for (int left=0, right=0; right<s.size(); ++right) {
            cnts[s[right]] += 1;
            
            if (cnts.size() < 3) continue;
            
            while (cnts[s[left]] > 1) {
                cnts[s[left]] -= 1;
                left += 1;
            }
            ans += left + 1;
        }
        return ans;

        int ans = 0;
        vector<int> last{-1, -1, -1};
        for (int i=0; i<s.size(); ++i) {
            last[s[i] - 'a'] = i;
            ans += 1 + min({last[0], last[1], last[2]});
        }
        return ans;
    }
};
// @lc code=end

