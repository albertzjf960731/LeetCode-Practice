/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] Implement strStr()
 */
#include<string>
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int strStr(string s, string p) {
        if (p.empty()) return 0;
        if (s.empty()) return -1;
        vector<int> next = getNext(p);
        int m = s.size(), n = p.size();
        int i=0, j=0;
        while (i<m && j<n) {
            if (j==-1 || s[i]==p[j]) {
                ++i;
                ++j;
            }
            else {
                j = next[j];
            }
        }
        return (j==n) ? i-j : -1;
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

