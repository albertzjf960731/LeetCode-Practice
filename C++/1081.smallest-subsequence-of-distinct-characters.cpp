/*
 * @lc app=leetcode id=1081 lang=cpp
 *
 * [1081] Smallest Subsequence of Distinct Characters
 *
 * https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/description/
 *
 * algorithms
 * Medium (50.50%)
 * Likes:    479
 * Dislikes: 73
 * Total Accepted:    13K
 * Total Submissions: 25.5K
 * Testcase Example:  '"cdadabcc"'
 *
 * Return the lexicographically smallest subsequence of text that contains all
 * the distinct characters of text exactly once.
 * 
 * Example 1:
 * 
 * 
 * Input: "cdadabcc"
 * Output: "adbc"
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "abcd"
 * Output: "abcd"
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "ecbacba"
 * Output: "eacb"
 * 
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: "leetcode"
 * Output: "letcod"
 * 
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= text.length <= 1000
 * text consists of lowercase English letters.
 * 
 * 
 * Note: This question is the same as 316:
 * https://leetcode.com/problems/remove-duplicate-letters/
 * 
 * 
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
    string smallestSubsequence(string s) {
        if (s.empty()) return s;
        
        unordered_map<char, int> cnts;
        for (char ch: s) cnts[ch] ++;
        bool visited[256] = {false};
        
        string ans = "0";
        for (char ch : s) {
            cnts[ch] --;
            if (visited[ch]) continue;
            
            while (!ans.empty() && ch<ans.back() && cnts[ans.back()]>0) {
                visited[ans.back()] = false;
                ans.pop_back();
            }
            ans.push_back(ch);
            visited[ch] = true;
        }
        return ans.substr(1);
    }
};
// @lc code=end

