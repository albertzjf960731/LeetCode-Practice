/*
 * @lc app=leetcode id=821 lang=cpp
 *
 * [821] Shortest Distance to a Character
 *
 * https://leetcode.com/problems/shortest-distance-to-a-character/description/
 *
 * algorithms
 * Easy (65.51%)
 * Likes:    826
 * Dislikes: 67
 * Total Accepted:    53.2K
 * Total Submissions: 81.3K
 * Testcase Example:  '"loveleetcode"\n"e"'
 *
 * Given a string S and a character C, return an array of integers representing
 * the shortest distance from the character C in the string.
 * 
 * Example 1:
 * 
 * 
 * Input: S = "loveleetcode", C = 'e'
 * Output: [3, 2, 1, 0, 1, 0, 0, 1, 2, 2, 1, 0]
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * S string length is in [1, 10000].
 * C is a single character, and guaranteed to be in string S.
 * All letters in S and C are lowercase.
 * 
 * 
 */
#include<vector>
#include<string>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> shortestToChar(string str, char ch) {
        int pos = -str.size();
        
        vector<int> res(str.size());
        for (int i=0; i<str.size(); ++i) {
            if (str[i] == ch) 
                pos = i;
            res[i] = i-pos;
        }
        
        for (int i = pos; i >= 0; --i) {
            if (str[i]==ch)  
                pos = i;
            res[i] = min(res[i], pos-i);
        }
        return res;
    }
};
// @lc code=end

