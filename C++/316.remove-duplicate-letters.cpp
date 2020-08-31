/*
 * @lc app=leetcode id=316 lang=cpp
 *
 * [316] Remove Duplicate Letters
 */
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

// @lc code=start
class Solution {
public:
    string removeDuplicateLetters(string s) {
        if (s.empty()) return s;
        
        unordered_map<char, int> cnts;
        for (char ch: s) cnts[ch] ++;
        bool visited[256] = {false};
        
        string ans{s[0]};
        visited[s[0]] = true;
        cnts[s[0]] --;
        
        for (int i=1; i<s.size(); ++i) {
            char ch = s[i];
            cnts[ch] --;
            if (visited[ch]) continue;
            
            while (!ans.empty() && ch<ans.back() && cnts[ans.back()]>0) {
                visited[ans.back()] = false;
                ans.pop_back();
            }
            ans.push_back(ch);
            visited[ch] = true;
        }
        return ans;
    }
};
// @lc code=end

