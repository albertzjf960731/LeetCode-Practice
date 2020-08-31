/*
 * @lc app=leetcode id=856 lang=cpp
 *
 * [856] Score of Parentheses
 *
 * https://leetcode.com/problems/score-of-parentheses/description/
 *
 * algorithms
 * Medium (58.93%)
 * Likes:    918
 * Dislikes: 32
 * Total Accepted:    32.1K
 * Total Submissions: 54.2K
 * Testcase Example:  '"()"'
 *
 * Given a balanced parentheses string S, compute the score of the string based
 * on the following rule:
 * 
 * 
 * () has score 1
 * AB has score A + B, where A and B are balanced parentheses strings.
 * (A) has score 2 * A, where A is a balanced parentheses string.
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "()"
 * Output: 1
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "(())"
 * Output: 2
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "()()"
 * Output: 2
 * 
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: "(()(()))"
 * Output: 6
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * S is a balanced parentheses string, containing only ( and ).
 * 2 <= S.length <= 50
 * 
 * 
 * 
 * 
 * 
 * 
 */

#include<vector>
#include<string>
using namespace std;

// @lc code=start
class Solution {
public:
    int scoreOfParentheses(string str) {
    	int ans = 0;
    	for (int i=0; i<str.size(); ++i) {
    		if (str[i] == ')') continue;
            
			int j=i+1;
            for (int cnt=1; j<str.size() && cnt!=0; ++j) {
                if (str[j]=='(') cnt++;
                else if (str[j]==')') cnt--;
    		}
    		int sub_ans = scoreOfParentheses(str.substr(i+1, j-i-2));
    		ans += max(2*sub_ans, 1);
    		i= j-1;
    	}
    	return ans;
    }
};
// @lc code=end

