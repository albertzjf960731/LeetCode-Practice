/*
 * @lc app=leetcode id=557 lang=cpp
 *
 * [557] Reverse Words in a String III
 *
 * https://leetcode.com/problems/reverse-words-in-a-string-iii/description/
 *
 * algorithms
 * Easy (67.44%)
 * Likes:    819
 * Dislikes: 81
 * Total Accepted:    173.9K
 * Total Submissions: 257.7K
 * Testcase Example:  `"Let's take LeetCode contest"`
 *
 * Given a string, you need to reverse the order of characters in each word
 * within a sentence while still preserving whitespace and initial word order.
 * 
 * Example 1:
 * 
 * Input: "Let's take LeetCode contest"
 * Output: "s'teL ekat edoCteeL tsetnoc"
 * 
 * 
 * 
 * Note:
 * In the string, each word is separated by single space and there will not be
 * any extra space in the string.
 * 
 */
#include<string>
using namespace std;

// @lc code=start
class Solution {
public:
   void reverseword(string &s, int l, int r){
        while(l<r) swap(s[l], s[r]);
    }
    
    string reverseWords(string s) {
        int n = s.size();
        int l=0, r=0;
        while (l<n && r<n) {
            l = r;
            while (l<n && s[l]==' ') l++;
            r = l;
            while (r<n && s[r]!=' ') r++;
            reverse(s.begin()+l, s.begin()+r);
        }  
        return s;
    }
};
// @lc code=end

