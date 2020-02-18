/*
 * @lc app=leetcode id=65 lang=cpp
 *
 * [65] Valid Number
 *
 * https://leetcode.com/problems/valid-number/description/
 *
 * algorithms
 * Hard (14.57%)
 * Likes:    558
 * Dislikes: 3974
 * Total Accepted:    145K
 * Total Submissions: 994.6K
 * Testcase Example:  '"0"'
 *
 * Validate if a given string can be interpreted as a decimal number.
 * 
 * Some examples:
 * "0" => true
 * " 0.1 " => true
 * "abc" => false
 * "1 a" => false
 * "2e10" => true
 * " -90e3   " => true
 * " 1e" => false
 * "e3" => false
 * " 6e-1" => true
 * " 99e2.5 " => false
 * "53.5e93" => true
 * " --6 " => false
 * "-+3" => false
 * "95a54e53" => false
 * 
 * Note: It is intended for the problem statement to be ambiguous. You should
 * gather all requirements up front before implementing one. However, here is a
 * list of characters that can be in a valid decimal number:
 * 
 * 
 * Numbers 0-9
 * Exponent - "e"
 * Positive/negative sign - "+"/"-"
 * Decimal point - "."
 * 
 * 
 * Of course, the context of these characters also matters in the input.
 * 
 * Update (2015-02-10):
 * The signature of the C++ function had been updated. If you still see your
 * function signature accepts a const char * argument, please click the reload
 * button to reset your code definition.
 * 
 */
#include<string>
using namespace std;

// @lc code=start
class Solution {
public:
    bool isNumber(string s) {
        int n=s.size(), i=0, n_digit=0, n_dot=0;
        
        // skip the whitespaces
        // for(; i<n && s[i]==' '; i++) {}
        for(; i<n && isspace(s[i]); i++) {}
    
        // check the significand
        if (s[i]=='+' || s[i]=='-') i++; // skip the sign if exist
    
        // for (; (s[i]>='0'&&s[i]<='9') || s[i]=='.'; i++)
        for (; i<n && (isdigit(s[i]) || s[i]=='.'); i++)
            s[i]=='.' ? n_dot++ : n_digit++;   

        if (n_dot>1 || n_digit<1)
            return false;

        // check the exponent if exist
        if(s[i]=='e') {
            i++;
            if(s[i]=='+' || s[i]=='-') i++; 
            
            n_digit = 0;
            for(; i<n && isdigit(s[i]); i++)  n_digit++;
            if(n_digit<1) return false;
        }
    
        // skip the trailing whitespaces
        for(; s[i]==' '; i++) {}
        return i==n;
    }
};
// @lc code=end

