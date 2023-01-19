/*
 * @lc app=leetcode id=151 lang=cpp
 *
 * [151] Reverse Words in a String
 *
 * https://leetcode.com/problems/reverse-words-in-a-string/description/
 *
 * algorithms
 * Medium (19.26%)
 * Likes:    814
 * Dislikes: 2626
 * Total Accepted:    352.6K
 * Total Submissions: 1.8M
 * Testcase Example:  '"the sky is blue"'
 *
 * Given an input string, reverse the string word by word.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "the sky is blue"
 * Output: "blue is sky the"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "  hello world!  "
 * Output: "world! hello"
 * Explanation: Your reversed string should not contain leading or trailing
 * spaces.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "a good   example"
 * Output: "example good a"
 * Explanation: You need to reduce multiple spaces between two words to a
 * single space in the reversed string.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * A word is defined as a sequence of non-space characters.
 * Input string may contain leading or trailing spaces. However, your reversed
 * string should not contain leading or trailing spaces.
 * You need to reduce multiple spaces between two words to a single space in
 * the reversed string.
 * 
 * 
 * 
 * 
 * Follow up:
 * 
 * For C programmers, try to solve it in-place in O(1) extra space.
 */

#include<vector>
#include<string>
using namespace std;

// @lc code=start
class Solution {
public:
   void reverseword(string &s, int l, int r){
        while(l<r) swap(s[l], s[r]);
    }
    
    string reverseWords(string s) {
        if (s.empty()) return s;
        
        int n=s.size();
        int l=0, r=0;
        while (r<n) {
            int flag = 0;
            while (r<n && s[r]==' ') r++;
            while(r<n && s[r]!=' ') {
                s[l++] = s[r++];
                flag = 1;
            }
            if (flag) s[l++] = ' ';
        }
        n = l - 1;
        if (n<=0) return "";
        
        l=0, r=0;
        while (l<n && r<n) {
            l = r;
            while (l<n && s[l]==' ') l++;
            r = l;
            while (r<n && s[r]!=' ') r++;
            reverse(s.begin()+l, s.begin()+r);
        }
        reverse(s.begin(), s.begin()+n);
        
        return string(s.begin(), s.begin()+n);



        vector<string> strs;
        istringstream in(s);
        
        string w;
        while (in >> w) strs.push_back(w);
        reverse(strs.begin(), strs.end());
        
        string ans;
        for (int i=0; i<strs.size(); ++i) {
            ans += strs[i];
            if (i < strs.size()-1) ans += " ";
        }
        return ans;
    }
};
// @lc code=end

