/*
 * @lc app=leetcode id=990 lang=cpp
 *
 * [990] Satisfiability of Equality Equations
 *
 * https://leetcode.com/problems/satisfiability-of-equality-equations/description/
 *
 * algorithms
 * Medium (45.12%)
 * Likes:    580
 * Dislikes: 5
 * Total Accepted:    21.2K
 * Total Submissions: 46.6K
 * Testcase Example:  '["a==b","b!=a"]'
 *
 * Given an array equations of strings that represent relationships between
 * variables, each string equations[i] has length 4 and takes one of two
 * different forms: "a==b" or "a!=b".  Here, a and b are lowercase letters (not
 * necessarily different) that represent one-letter variable names.
 * 
 * Return true if and only if it is possible to assign integers to variable
 * names so as to satisfy all the given equations.
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: ["a==b","b!=a"]
 * Output: false
 * Explanation: If we assign say, a = 1 and b = 1, then the first equation is
 * satisfied, but not the second.  There is no way to assign the variables to
 * satisfy both equations.
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ["b==a","a==b"]
 * Output: true
 * Explanation: We could assign a = 1 and b = 1 to satisfy both equations.
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: ["a==b","b==c","a==c"]
 * Output: true
 * 
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: ["a==b","b!=c","c==a"]
 * Output: false
 * 
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: ["c==c","b==d","x!=z"]
 * Output: true
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= equations.length <= 500
 * equations[i].length == 4
 * equations[i][0] and equations[i][3] are lowercase letters
 * equations[i][1] is either '=' or '!'
 * equations[i][2] is '='
 * 
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
    bool equationsPossible(vector<string>& equations) {
        vector<int> root(26);
        for (int i=0; i<26; ++i) root[i] = i;
        
        for (string str: equations) {
            if (str[1]=='=')
                root[findRoot(root, str[0]-'a')] = findRoot(root, str[3]-'a');
        }
        
        for (string str: equations) {
            if (str[1]=='!') {
                if (findRoot(root, str[0]-'a')==findRoot(root, str[3]-'a'))
                    return false;
            }
        }
        return true;
    }

    int findRoot(vector<int>& root, int i) {
        while (i != root[i]) i = root[i];
        return i;
    }
};
// @lc code=end

