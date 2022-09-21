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
    	for (int i=0; i<s.size(); ++i) {
    		if (s[i] == ')') continue;
            
			int j=i+1;
            for (int cnt=1; j<s.size(); ++j) {
                if (s[j]=='(') cnt++;
                else if (s[j]==')') cnt--;
                if (cnt == 0) break;
    		}
            
    		int sub_ans = scoreOfParentheses(s.substr(i+1, j-i-1));
    		ans += max(2*sub_ans, 1);
    		i = j;
    	}
    	return ans;

        int ans = 0;
        vector<int> stack;
        
    	for (char c: s) {
            if (c == '(') {
                stack.push_back(ans);
                ans = 0;
            }
            else {
                ans = stack.back() + max(ans * 2, 1);
                stack.pop_back();
            }
        }
        return ans;
    }
};
// @lc code=end

