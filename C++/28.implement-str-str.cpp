/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Implement strStr()
 *
 * https://leetcode.com/problems/implement-strstr/description/
 *
 * algorithms
 * Easy (34.55%)
 * Likes:    1770
 * Dislikes: 2013
 * Total Accepted:    717.5K
 * Total Submissions: 2.1M
 * Testcase Example:  '"hello"\n"ll"'
 *
 * Implement strStr().
 * 
 * Return the index of the first occurrence of needle in haystack, or -1 if
 * needle is not part of haystack.
 * 
 * Example 1:
 * 
 * 
 * Input: haystack = "hello", needle = "ll"
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: haystack = "aaaaa", needle = "bba"
 * Output: -1
 * 
 * 
 * Clarification:
 * 
 * What should we return when needle is an empty string? This is a great
 * question to ask during an interview.
 * 
 * For the purpose of this problem, we will return 0 when needle is an empty
 * string. This is consistent to C's strstr() and Java's indexOf().
 * 
 * 
 * Constraints:
 * 
 * 
 * haystack and needle consist only of lowercase English characters.
 * 
 * 
 */

// @lc code=start
#include<string>
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int strStr(string s, string p) {
        if (p.empty()) return 0;
        
        int s_size = s.size(), p_size = p.size();
        if (s_size < p_size) return -1;
        
        for (int i=0; i<=s_size-p_size; ++i) {
            
            int j = 0;
            for (j=0; j<p_size; ++j) {
                if (s[i+j] != p[j]) break;
            }
            if (j==p_size) return i;
        }
        return -1;

        
        if (p.empty()) return 0;
        if (s.empty()) return -1;
        vector<int> next = getNext(p);
        int m = s.size(), n = p.size();
        int i=0, j=0;
        while (i<m && j<n) {
            if (j==-1 || s[i]==p[j]) {
                ++i;
                ++j;
            }
            else {
                j = next[j];
            }
        }
        return (j==n) ? i-j : -1;
    }
    vector<int> getNext(string p) {
        vector<int> next(p.size(), -1);
        int k=-1, j=0;
        while (j < p.size()-1) {
            if (k==-1 || p[k]==p[j]) {
                ++k;
                ++j;
                next[j] = k;
            }
            else {
                k = next[k];
            }
        }
        return next;
    }
};
// @lc code=end


// @lc code=end

