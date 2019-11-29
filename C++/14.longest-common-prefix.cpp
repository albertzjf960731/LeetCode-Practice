/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */

#include<iostream>
#include<vector>
#include<string>

using namespace std;

// @lc code=start
class Solution {
public:

    // int startsWith(string s, string sub){
    //         return s.find(sub)==0?1:0;
    // }

    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0)
            return "";
        
        // string ans = strs[0];
        // for (int i=1; i<strs.size(); i++) {
        //     while (not startsWith(strs[i], ans))
        //         ans.pop_back();
        // }
        // return ans;

        string ans = strs[0];
        for (int i=0; i<ans.size(); i++) {
            char ch= ans[i];
            for (int j=1; j<strs.size(); j++) {
                if (strs[j][i] != ch)
                    return ans.substr(0, i);
            }
        }
        return ans;
    }
};
// @lc code=end

