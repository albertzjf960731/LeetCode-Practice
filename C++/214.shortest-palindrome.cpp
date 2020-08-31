/*
 * @lc app=leetcode id=214 lang=cpp
 *
 * [214] Shortest Palindrome
 *
 * https://leetcode.com/problems/shortest-palindrome/description/
 *
 * algorithms
 * Hard (28.90%)
 * Likes:    910
 * Dislikes: 103
 * Total Accepted:    88.7K
 * Total Submissions: 307K
 * Testcase Example:  '"aacecaaa"'
 *
 * Given a string s, you are allowed to convert it to a palindrome by adding
 * characters in front of it. Find and return the shortest palindrome you can
 * find by performing this transformation.
 * 
 * Example 1:
 * 
 * 
 * Input: "aacecaaa"
 * Output: "aaacecaaa"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "abcd"
 * Output: "dcbabcd"
 */
#include<vector>
#include<string>
using namespace std;

// @lc code=start
class Solution {
public:
    string shortestPalindrome(string s) {
        string r = s;
        reverse(r.begin(), r.end());
        string t = s + "#" + r;
        
        // vector<int> next(t.size(), 0);
        // for (int i=1; i<t.size(); ++i) {
        //     int j = next[i-1];
        //     while (j>0 && t[i]!=t[j]) 
        //         j = next[j-1];
        //     next[i] = (j += t[i]==t[j]);
        // }
        vector<int> next = getNext(t);
        return r.substr(0, s.size()-next.back()-1) + s;
    }
    vector<int> getNext(string p) {
        vector<int> next(p.size(), -1);
        int k=-1, j=0;
        while (j < p.size()-1) {
            if (k==-1 || p[k]==p[j]) {
                ++k;
                ++j;
                next[j] = k;
            }
            else {
                k = next[k];
            }
        }
        return next;
    }
};
// @lc code=end

