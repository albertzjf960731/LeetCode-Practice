/*
 * @lc app=leetcode id=132 lang=cpp
 *
 * [132] Palindrome Partitioning II
 *
 * https://leetcode.com/problems/palindrome-partitioning-ii/description/
 *
 * algorithms
 * Hard (29.17%)
 * Likes:    847
 * Dislikes: 29
 * Total Accepted:    119.9K
 * Total Submissions: 410.8K
 * Testcase Example:  '"aab"'
 *
 * Given a string s, partition s such that every substring of the partition is
 * a palindrome.
 * 
 * Return the minimum cuts needed for a palindrome partitioning of s.
 * 
 * Example:
 * 
 * 
 * Input: "aab"
 * Output: 1
 * Explanation: The palindrome partitioning ["aa","b"] could be produced using
 * 1 cut.
 * 
 * 
 */
#include<vector>
#include<string>
using namespace std;

// @lc code=start
class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n);
        vector<vector<bool>> is_pal(n, vector<bool>(n, false));

        for (int i=0; i<n; i++) {
            dp[i] = i;
            is_pal[i][i] = true;
        }
    
        for (int i=0; i<n; i++) {
            // 千万注意更新顺序！！
            for (int j=i; j>=0; j--) {
                // if (isPalindrome(s, j, i)) {
                if (s[i]==s[j] && (i-j<=1 || is_pal[j+1][i-1])) {
                    dp[i] = min(dp[i], j==0 ? 0 : dp[j-1]+1);
                    is_pal[j][i] = true;
                }
            }
        }
        return dp[n-1];
    }

    bool isPalindrome(string& s, int l, int r) {
        while (l<r) {
            if (s[l++]!=s[r--])
                return false;
        }
        return true;
    }

    //     int n = s.size();
        
    //     vector<int> dp(n+1);
    //     for(int i=0; i<=n; ++i) dp[i] = i-1;
        
    //     for(int i=0; i<n; i++) {
    //         for(int j=0; (i-j)>=0 && (i+j)<n && s[i-j]== s[i+j]; j++) 
    //             dp[i+j+1] = min(dp[i+j+1], dp[i-j]+1);

    //         for(int j=0; (i-j-1)>=0 && (i+j)<n && s[i-j-1]==s[i+j]; ++j) 
    //             dp[i+j+1] = min(dp[i+j+1], dp[i-j-1]+1);
    //     }
    //     return dp.back();
    // }
};
// @lc code=end

