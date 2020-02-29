/*
 * @lc app=leetcode id=984 lang=cpp
 *
 * [984] String Without AAA or BBB
 *
 * https://leetcode.com/problems/string-without-aaa-or-bbb/description/
 *
 * algorithms
 * Medium (35.93%)
 * Likes:    143
 * Dislikes: 207
 * Total Accepted:    14.4K
 * Total Submissions: 39.9K
 * Testcase Example:  '1\n2'
 *
 * Given two integers A and B, return any string S such that:
 * 
 * 
 * S has length A + B and contains exactly A 'a' letters, and exactly B 'b'
 * letters;
 * The substring 'aaa' does not occur in S;
 * The substring 'bbb' does not occur in S.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: A = 1, B = 2
 * Output: "abb"
 * Explanation: "abb", "bab" and "bba" are all correct answers.
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: A = 4, B = 1
 * Output: "aabaa"
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 0 <= A <= 100
 * 0 <= B <= 100
 * It is guaranteed such an S exists for the given A and B.
 * 
 * 
 */
#include<string>
using namespace std;

// @lc code=start
class Solution {
public:
    string strWithout3a3b(int A, int B) {
        // if(A == 0) return string(B, 'b');
        // else if(B == 0) return string(A, 'a');
        // else if(A == B) return "ab" + strWithout3a3b(A-1, B-1);
        // else if(A > B) return "aab" + strWithout3a3b(A-2, B-1);
        // // else return strWithout3a3b(A-1, B-2) + "abb";
        // else return "bba" + strWithout3a3b(A-1, B-2) ;

        string ans = "";
        if (A >= B*2) {
            for (int i=0; i<B; i++)
                ans += "aab";
            for (int i=0; i<A-2*B; i++)
                ans += "a";
        }
        else if (B >= A*2) {
            for (int i=0; i<A; i++)
                ans += "bba";
            for (int i=0; i<B-2*A; i++)
                ans += "b";
        }
        else if (A >= B) {
            for (int i=0; i<A-B; i++)
                ans += "aab";
            for (int i=0; i<2*B-A; i++)
                ans += "ab";
        }
        else {
            for (int i=0; i<B-A; i++)
                ans += "bba";
            for (int i=0; i<2*A-B; i++)
                ans += "ba";
        }
        return ans;
    }
};
// @lc code=end

