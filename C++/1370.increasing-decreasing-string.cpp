/*
 * @lc app=leetcode id=1370 lang=cpp
 *
 * [1370] Increasing Decreasing String
 *
 * https://leetcode.com/problems/increasing-decreasing-string/description/
 *
 * algorithms
 * Easy (75.55%)
 * Likes:    205
 * Dislikes: 187
 * Total Accepted:    21.9K
 * Total Submissions: 29K
 * Testcase Example:  '"aaaabbbbcccc"'
 *
 * Given a string s. You should re-order the string using the following
 * algorithm:
 * 
 * 
 * Pick the smallest character from s and append it to the result.
 * Pick the smallest character from s which is greater than the last appended
 * character to the result and append it.
 * Repeat step 2 until you cannot pick more characters.
 * Pick the largest character from s and append it to the result.
 * Pick the largest character from s which is smaller than the last appended
 * character to the result and append it.
 * Repeat step 5 until you cannot pick more characters.
 * Repeat the steps from 1 to 6 until you pick all characters from s.
 * 
 * 
 * In each step, If the smallest or the largest character appears more than
 * once you can choose any occurrence and append it to the result.
 * 
 * Return the result string after sorting s with this algorithm.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "aaaabbbbcccc"
 * Output: "abccbaabccba"
 * Explanation: After steps 1, 2 and 3 of the first iteration, result = "abc"
 * After steps 4, 5 and 6 of the first iteration, result = "abccba"
 * First iteration is done. Now s = "aabbcc" and we go back to step 1
 * After steps 1, 2 and 3 of the second iteration, result = "abccbaabc"
 * After steps 4, 5 and 6 of the second iteration, result = "abccbaabccba"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "rat"
 * Output: "art"
 * Explanation: The word "rat" becomes "art" after re-ordering it with the
 * mentioned algorithm.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "leetcode"
 * Output: "cdelotee"
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: s = "ggggggg"
 * Output: "ggggggg"
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: s = "spo"
 * Output: "ops"
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 500
 * s contains only lower-case English letters.
 * 
 * 
 */
#include<string>
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    string sortString(string s) {
        string stack1 = s;
        sort(stack1.rbegin(), stack1.rend());
        string stack2 = "", ans = "";

        while (!stack1.empty() || !stack2.empty()) {
            while (!stack1.empty()) {
                char ch = stack1.back();
                stack1.pop_back();
                ans.push_back(ch);

                while (!stack1.empty() && stack1.back()==ch) {
                    stack2.push_back(stack1.back());
                    stack1.pop_back();
                }
            }

            while (!stack2.empty()) {
                char ch = stack2.back();
                stack2.pop_back();
                ans.push_back(ch);

                while (!stack2.empty() && stack2.back()==ch) {
                    stack1.push_back(stack2.back());
                    stack2.pop_back();
                }
            }
        }
        return ans;

        
        vector<int> cnts(26);
        for(int i=0; i<s.size(); i ++) cnts[s[i]-'a'] ++;
        
        int cnt = s.size();
        string ans = "";
        while(cnt > 0){
            addIncrease(ans, 0, cnts, cnt);
            addIncrease(ans, 1, cnts, cnt);
        }
        return ans;
    }
    
    void addIncrease(string& ans, int flag, vector<int>& cnts, int& cnt){
        if(flag == 0){
            for(int i=0; i<26; ++i){
                if(cnts[i] > 0) {
                    ans.push_back('a'+i);
                    cnts[i] --;
                    cnt --;
                }
            }
        }
        else{
            for(int i=25; i>=0; --i){
               if(cnts[i] > 0) {
                    ans.push_back('a' + i);
                    cnts[i] --;
                    cnt --;
                } 
            }
        }
    }
};
// @lc code=end

