/*
 * @lc app=leetcode id=639 lang=cpp
 *
 * [639] Decode Ways II
 *
 * https://leetcode.com/problems/decode-ways-ii/description/
 *
 * algorithms
 * Hard (25.88%)
 * Likes:    336
 * Dislikes: 445
 * Total Accepted:    26.7K
 * Total Submissions: 103.1K
 * Testcase Example:  '"*"'
 *
 * 
 * A message containing letters from A-Z is being encoded to numbers using the
 * following mapping way:
 * 
 * 
 * 
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 * 
 * 
 * 
 * Beyond that, now the encoded string can also contain the character '*',
 * which can be treated as one of the numbers from 1 to 9.
 * 
 * 
 * 
 * 
 * Given the encoded message containing digits and the character '*', return
 * the total number of ways to decode it.
 * 
 * 
 * 
 * Also, since the answer may be very large, you should return the output mod
 * 10^9 + 7.
 * 
 * 
 * Example 1:
 * 
 * Input: "*"
 * Output: 9
 * Explanation: The encoded message can be decoded to the string: "A", "B",
 * "C", "D", "E", "F", "G", "H", "I".
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: "1*"
 * Output: 9 + 9 = 18
 * 
 * 
 * 
 * Note:
 * 
 * The length of the input string will fit in range [1, 10^5].
 * The input string will only contain the character '*' and digits '0' - '9'.
 * 
 * 
 */
#include<string>
#include<vector>
using namespace std;

// @lc code=start
class Solution {
private:
    int numDecodingChars(string str) {
        if (str.size()==1) {
            if (str[0]=='*') return 9;
            return str[0] == '0'? 0: 1;
        }
        // 11-26, except 20
        if (str=="**")  
            return 15;
        else if (str[1]=='*') {
            if (str[0] =='1') return 9;
            return str[0] == '2'? 6: 0;
        }
        else if (str[0]=='*') 
            return str[1]<='6'? 2:1;
        else 
            return stoi(str)>=10 && stoi(str)<=26 ? 1: 0; 
    }
    
public:
    int numDecodings(string str) {
        int n=str.size(), p=1e9+7;
        
        long num1=numDecodingChars(str.substr(0, 1)), num2=1;
        for (int i=1; i<n; i++) {
            long cur = (num1*numDecodingChars(str.substr(i, 1)))+(num2*numDecodingChars(str.substr(i-1, 2)));
            num2 = num1;
            num1 = cur%p;
        }
        return num1;

    
        if (str.empty())
            return 0;
        
        int n=str.size(), mode=1e9+7;
        vector<int> dp(n+1, 0);
        dp[0] = 1;

        for (int i=0; i<str.size(); i++) {
            char ch = str[i];
            if (ch >= '1' && ch <= '9') 
                dp[i+1] = dp[i];
            else if (ch == '*') 
                dp[i+1] = (9L*dp[i]) % mode;
            
            if (i > 0) {
                if (ch != '*') {
                    if (str[i-1] != '*') {
                        // int num = stoi(str.substr(i-1, 2));
                        int num = (str[i-1]-'0')*10 + (ch-'0');
                        if (num >= 10 && num <= 26) 
                            dp[i+1] = (dp[i+1] + dp[i-1]) % mode;
                    } 
                    else {
                        long cnt = 0;
                        if (ch >= '0' && ch <= '6')
                            cnt = 2;
                        else 
                            cnt = 1;
                        dp[i+1] = (dp[i+1] + dp[i-1]*cnt) % mode;
                    }
                } 
                else {
                    long cnt = 0;
                    if (str[i-1] == '*') 
                        cnt = 15;//9+7
                    else if (str[i-1] == '1') 
                        cnt = 9;
                    else if (str[i-1] == '2')
                        cnt = 6;         
                    dp[i+1] = (dp[i+1] + dp[i-1]*cnt) % mode;
                }
            }
        }
        return dp[n];
    }
};
// @lc code=end

