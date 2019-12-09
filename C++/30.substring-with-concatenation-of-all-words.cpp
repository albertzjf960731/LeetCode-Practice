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
        vector<int> res;
        if (words.empty())
            return res;

        unordered_map<string, int> hash_map;
        for (string word: words){
            hash_map[word]++;
        }

        int num_word = words.size(), word_len = words[0].size();
        for (int i=0; i<s.size()-num_word*word_len+1; i++) {
            unordered_map<string, int> temp_map;
            
            int j = 0;
            for (; j<num_word; j++) {
                string word = s.substr(i+j*word_len, word_len);
                if(hash_map.find(word) != hash_map.end()) {
                    temp_map[word]++;
                    if (temp_map[word]>hash_map[word])
                        break;
                }
                else 
                    break;
            }
            if (j==num_word)
                res.push_back(i);
        }
        return res;
    }
};
// @lc code=end

