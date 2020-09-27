/*
 * @lc app=leetcode id=241 lang=cpp
 *
 * [241] Different Ways to Add Parentheses
 *
 * https://leetcode.com/problems/different-ways-to-add-parentheses/description/
 *
 * algorithms
 * Medium (53.07%)
 * Likes:    1331
 * Dislikes: 66
 * Total Accepted:    90.4K
 * Total Submissions: 170.3K
 * Testcase Example:  '"2-1-1"'
 *
 * Given a string of numbers and operators, return all possible results from
 * computing all the different possible ways to group numbers and operators.
 * The valid operators are +, - and *.
 * 
 * Example 1:
 * 
 * 
 * Input: "2-1-1"
 * Output: [0, 2]
 * Explanation: 
 * ((2-1)-1) = 0 
 * (2-(1-1)) = 2
 * 
 * Example 2:
 * 
 * 
 * Input: "2*3-4*5"
 * Output: [-34, -14, -10, -10, 10]
 * Explanation: 
 * (2*(3-(4*5))) = -34 
 * ((2*3)-(4*5)) = -14 
 * ((2*(3-4))*5) = -10 
 * (2*((3-4)*5)) = -10 
 * (((2*3)-4)*5) = 10
 * 
 */
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;
// @lc code=start
class Solution {
private:
    unordered_map<string, vector<int>> cache;
    
public:
    vector<int> diffWaysToCompute(string str) {
        if (cache.count(str)) return cache[str];
        
        vector<int> res;
        for (int i=0; i<str.size(); i++) {
            char ch = str[i];
            if (ch=='+' || ch=='-' || ch=='*') {
                vector<int> left_ans = diffWaysToCompute(str.substr(0, i));
                vector<int> right_ans = diffWaysToCompute(str.substr(i+1));
                
                for (int num1:left_ans) {
                    for (int num2: right_ans) {
                        if (ch=='+')
                            res.push_back(num1+num2);
                        else if (ch=='-')
                            res.push_back(num1-num2);
                        else 
                            res.push_back(num1*num2);
                    }
                }
            }
        }
        if (res.empty())
            res.push_back(stoi(str));
        cache[str] = res;
        return res;    
    }
};
// @lc code=end

