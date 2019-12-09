/*
 * @lc app=leetcode id=72 lang=cpp
 *
 * [72] Edit Distance
 *
 * https://leetcode.com/problems/edit-distance/description/
 *
 * algorithms
 * Hard (40.40%)
 * Likes:    2752
 * Dislikes: 44
 * Total Accepted:    211K
 * Total Submissions: 522.3K
 * Testcase Example:  '"horse"\n"ros"'
 *
 * Given two words word1 and word2, find the minimum number of operations
 * required to convert word1 to word2.
 * 
 * You have the following 3 operations permitted on a word:
 * 
 * 
 * Insert a character
 * Delete a character
 * Replace a character
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: word1 = "horse", word2 = "ros"
 * Output: 3
 * Explanation: 
 * horse -> rorse (replace 'h' with 'r')
 * rorse -> rose (remove 'r')
 * rose -> ros (remove 'e')
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: word1 = "intention", word2 = "execution"
 * Output: 5
 * Explanation: 
 * intention -> inention (remove 't')
 * inention -> enention (replace 'i' with 'e')
 * enention -> exention (replace 'n' with 'x')
 * exention -> exection (replace 'n' with 'c')
 * exection -> execution (insert 'u')
 * 
 * 
 */
#include<string>
#include<iostream>
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int minDistance(string word1, string word2) {
        // 递归 会超时
        // if (word1.empty() && word2.empty())
        //     return 0;
        // if (word1.empty())
        //     return word2.size();
        // if (word2.empty())
        //     return word1.size();

        // int x = minDistance(word1, word2.substr(1)) + 1;
        // int y = minDistance(word1.substr(1), word2) + 1;
        // int z = minDistance(word1.substr(1), word2.substr(1));
        // if (word1[0]!= word2[0])
        //     z++;
        // return min(min(x, y), z);

        // 动态规划
        int size1 = word1.size(), size2 = word2.size();
        vector<vector<int>> dp(size1+1, vector<int>(size2+1, 0));

        for (int i=0; i<size1+1; i++)
            dp[i][0] = i;
        for (int j=0; j<size2+1; j++)
            dp[0][j] = j;

        for (int i=1; i<size1+1; i++) {
            for (int j=1; j<size2+1; j++) {
                if (word1[i-1] == word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = min(dp[i][j-1]+1, min(dp[i-1][j]+1, dp[i-1][j-1]+1));
            }
        }
        return dp[size1][size2];

        // int size1 = word1.size(), size2 = word2.size();
        // vector<int> pre(size2+1, 0), cur(size2+1, 0);
        // for (int j=0; j<size2+1; j++)
        //     pre[j] = j;

        // for (int i=1; i<size1+1; i++){
        //     cur[0] = i;
        //     for (int j=1; j<size2+1; j++) {
        //         if (word1[i-1]==word2[j-1]) 
        //             cur[j] = pre[j-1];
        //         else 
        //             cur[j] = min(pre[j-1], min(cur[j-1], pre[j]))+1;
        //     }
        //     fill(pre.begin(), pre.end(), 0);
        //     swap(pre, cur);
        // }
        // return pre[size2];
    }
};
// @lc code=end

int main() {
    string s="abcdxabcde", p="abcdeabcdx";
    Solution sol;
    int ans = sol.minDistance(s, p);
    cout <<"ans="<<ans;
}