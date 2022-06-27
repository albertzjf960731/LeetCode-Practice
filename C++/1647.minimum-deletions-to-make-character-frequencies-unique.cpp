/*
 * @lc app=leetcode id=1647 lang=cpp
 *
 * [1647] Minimum Deletions to Make Character Frequencies Unique
 *
 * https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/description/
 *
 * algorithms
 * Medium (56.41%)
 * Likes:    1446
 * Dislikes: 30
 * Total Accepted:    91.4K
 * Total Submissions: 162K
 * Testcase Example:  '"aab"'
 *
 * A string s is called good if there are no two different characters in s that
 * have the same frequency.
 * 
 * Given a string s, return the minimum number of characters you need to delete
 * to make s good.
 * 
 * The frequency of a character in a string is the number of times it appears
 * in the string. For example, in the string "aab", the frequency of 'a' is 2,
 * while the frequency of 'b' is 1.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "aab"
 * Output: 0
 * Explanation: s is already good.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "aaabbbcc"
 * Output: 2
 * Explanation: You can delete two 'b's resulting in the good string "aaabcc".
 * Another way it to delete one 'b' and one 'c' resulting in the good string
 * "aaabbc".
 * 
 * Example 3:
 * 
 * 
 * Input: s = "ceabaacb"
 * Output: 2
 * Explanation: You can delete both 'c's resulting in the good string "eabaab".
 * Note that we only care about characters that are still in the string at the
 * end (i.e. frequency of 0 is ignored).
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 10^5
 * s contains only lowercase English letters.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> cnts(26, 0);
        for (char c: s) cnts[c-'a'] += 1;
        sort(cnts.begin(), cnts.end(), greater<int>());
    
        int allow = s.size(), ans = 0;
        for (int i=0; i<26 && cnts[i]>0; ++i) {
            if (cnts[i] > allow) {
                ans += cnts[i] - allow;
                cnts[i] = allow;
            }
            allow = max(0, cnts[i] - 1);
        }
        
        return ans;
    }
};
// @lc code=end

