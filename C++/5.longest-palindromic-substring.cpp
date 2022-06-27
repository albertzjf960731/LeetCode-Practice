/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

#include <string>
#include<vector>

using namespace std; 

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        // const int size_s = s.size();

        // int max_s = 0, max_l = 0;
        // for (int i=0; i<size_s;) {
        //     int start = i, end = i;
            
        //     // Skip duplicate characters.
        //     // don't need to check whether the palindrome is odd or even compared to many brute force solutions.
        //     while (end+1<size_s and s[end]==s[end+1]) end ++;
        //     i = end + 1;

        //     while (start-1>=0 and end+1<size_s and s[start-1]==s[end+1]) {
        //         start--;
        //         end++;
        //     }
            
        //     if (end-start+1 > max_l) {
        //         max_l = end-start+1;
        //         max_s = start;
        //     }
        // }
        // return s.substr(max_s, max_l);
        if (s.empty()) return "";
        
        int n=s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int i=0; i<n; ++i) dp[i][i] = true;
        
        int left = 0, len = 1;
        for (int i=0; i<n; ++i) {
            for (int j=0; j<i; ++j) {
                dp[j][i] = (s[i]==s[j] && (i-j<2 || dp[j+1][i-1]));
                
                if (dp[j][i] && len<i-j+1) {
                    len = i-j+1;
                    left = j;
                }
            }
        }
        return s.substr(left, len);

        // 
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int i=0; i<n; ++i) dp[i][i] = true;
        
        int max_len = 1, start = 0;
        for (int len=2; len<=n; ++len) {
            for (int i=0; i<n-len+1; ++i) {
                int j = i + len - 1;
                
                if (s[i] == s[j] && (j-i==1 || dp[i+1][j-1])) 
                    dp[i][j] = true;
                
                
                if (dp[i][j] && len > max_len) {
                    max_len = len;
                    start = i;
                }
            }
        }
        return s.substr(start, max_len);
        

        // 

        int start = 0, max_len = 0;
        for (int i=0; i<s.size(); ++i) {
            helper(s, i, i, start, max_len);
            helper(s, i, i+1, start, max_len);
        }
        return s.substr(start, max_len);
    }
    
    void helper(string& s, int left, int right, int& start, int& max_len) {
        while (left>=0 && right<s.size() && s[left]==s[right]) {
            left -= 1;
            right += 1;
        }
        if (max_len < right-left-1) {
            start = left + 1;
            max_len = right -left - 1;
        }
    }
};
// @lc code=end

