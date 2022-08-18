/*
 * @lc app=leetcode id=30 lang=cpp
 *
 * [30] Substring with Concatenation of All Words
 */
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
         int n_w = words.size(), l_w = words[0].size();
        
        unordered_map<string, int> hmap;
        for (string& word: words) hmap[word] += 1;
        
        vector<int> ans;
        for (int i=0; i<s.size()-n_w*l_w+1; ++i) {
            unordered_map<string, int> tmp = hmap;
            
            int j = 0;
            for (; j<n_w; ++j) {
                string w = s.substr(i+j*l_w, l_w);
                if (tmp.count(w) && tmp[w]>0) tmp[w] -= 1;
                else break;
            }
            if (j==n_w) ans.push_back(i);
        }
        return ans;
    }
};
// @lc code=end

