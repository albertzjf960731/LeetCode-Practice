/*
 * @lc app=leetcode id=767 lang=cpp
 *
 * [767] Reorganize String
 *
 * https://leetcode.com/problems/reorganize-string/description/
 *
 * algorithms
 * Medium (46.33%)
 * Likes:    972
 * Dislikes: 52
 * Total Accepted:    52.4K
 * Total Submissions: 113K
 * Testcase Example:  '"aab"'
 *
 * Given a string S, check if the letters can be rearranged so that two
 * characters that are adjacent to each other are not the same.
 * 
 * If possible, output any possible result.  If not possible, return the empty
 * string.
 * 
 * Example 1:
 * 
 * 
 * Input: S = "aab"
 * Output: "aba"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: S = "aaab"
 * Output: ""
 * 
 * 
 * Note:
 * 
 * 
 * S will consist of lowercase letters and have length in range [1, 500].
 * 
 * 
 * 
 * 
 */
#include<vector>
#include<unordered_map>
#include<string>
#include<queue>
using namespace std;

// @lc code=start
class Solution {
public:
    string reorganizeString(string str) {
        int n = str.size();
        unordered_map<char, int> cnts;
        for (char ch : str) ++cnts[ch];
        
        priority_queue<pair<int, char>> q;
        for (auto& it : cnts) {
            if (it.second>(n+1)/2) return "";
            q.push({it.second, it.first});
        }
        
        
        string res = "";
        
        while (q.size() >= 2) {
            auto t1 = q.top(); q.pop();
            auto t2 = q.top(); q.pop();
            res.push_back(t1.second);
            res.push_back(t2.second);
            if (--t1.first > 0) q.push(t1);
            if (--t2.first > 0) q.push(t2);
        }
        if (q.size()>0) 
            res.push_back(q.top().second);
        return res;

        // int n = S.size();
        
        // unordered_map<char, int> cnts;
        // for (char ch: S) cnts[ch]++;
        
        // vector<pair<char, int>> chs;
        // for (auto cnt: cnts)
        //     chs.push_back(cnt);
        
        // sort(chs.begin(), chs.end(), [](auto &p1, auto &p2) {
        //     return p1.second > p2.second;
        // });
        
        // if (chs[0].second > (n+1)/2)
        //     return "";
        
        // S.clear();
        // for (auto p: chs) {
        //     string tmp(p.second, p.first);
        //     S.append(tmp);
        // }
        
        // string res(n, '0');
        // int i=0, j=0;
        // while (i<n && j<n) {
        //     res[i] = S[j++];
        //     i += 2;
        // }
        // i = 1;
        // while (i<n && j<n) {
        //     res[i] = S[j++];
        //     i += 2;
        // }
        // return res;
    }
};
// @lc code=end

