/*
 * @lc app=leetcode id=316 lang=cpp
 *
 * [316] Remove Duplicate Letters
 *
 * https://leetcode.com/problems/remove-duplicate-letters/description/
 *
 * algorithms
 * Hard (35.95%)
 * Likes:    1501
 * Dislikes: 115
 * Total Accepted:    83.6K
 * Total Submissions: 231K
 * Testcase Example:  '"bcabc"'
 *
 * Given a string which contains only lowercase letters, remove duplicate
 * letters so that every letter appears once and only once. You must make sure
 * your result is the smallest in lexicographical order among all possible
 * results.
 * 
 * Example 1:
 * 
 * 
 * Input: "bcabc"
 * Output: "abc"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "cbacdcbc"
 * Output: "acdb"
 * 
 * 
 * Note: This question is the same as 1081:
 * https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/
 * 
 */

// @lc code=start
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

// @lc code=start
class Solution {
public:
    string removeDuplicateLetters(string s) {
        if (s.empty()) return s;
        
        unordered_map<char, int> cnts;
        for (char ch: s) cnts[ch] ++;
        bool visited[256] = {false};
        
        string ans{s[0]};
        visited[s[0]] = true;
        cnts[s[0]] --;
        
        for (int i=1; i<s.size(); ++i) {
            char ch = s[i];
            cnts[ch] --;
            if (visited[ch]) continue;
            
            while (!ans.empty() && ch<ans.back() && cnts[ans.back()]>0) {
                visited[ans.back()] = false;
                ans.pop_back();
            }
            ans.push_back(ch);
            visited[ch] = true;
        }
        return ans;
    }
};
// @lc code=end

