/*
 * @lc app=leetcode id=438 lang=cpp
 *
 * [438] Find All Anagrams in a String
 *
 * https://leetcode.com/problems/find-all-anagrams-in-a-string/description/
 *
 * algorithms
 * Medium (39.74%)
 * Likes:    2149
 * Dislikes: 156
 * Total Accepted:    174.3K
 * Total Submissions: 435.6K
 * Testcase Example:  '"cbaebabacd"\n"abc"'
 *
 * Given a string s and a non-empty string p, find all the start indices of p's
 * anagrams in s.
 * 
 * Strings consists of lowercase English letters only and the length of both
 * strings s and p will not be larger than 20,100.
 * 
 * The order of output does not matter.
 * 
 * Example 1:
 * 
 * Input:
 * s: "cbaebabacd" p: "abc"
 * 
 * Output:
 * [0, 6]
 * 
 * Explanation:
 * The substring with start index = 0 is "cba", which is an anagram of "abc".
 * The substring with start index = 6 is "bac", which is an anagram of
 * "abc".
 * 
 * 
 * 
 * Example 2:
 * 
 * Input:
 * s: "abab" p: "ab"
 * 
 * Output:
 * [0, 1, 2]
 * 
 * Explanation:
 * The substring with start index = 0 is "ab", which is an anagram of "ab".
 * The substring with start index = 1 is "ba", which is an anagram of "ab".
 * The substring with start index = 2 is "ab", which is an anagram of "ab".
 * 
 * 
 */
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        // vector<int> res;

        // int s_size = s.size(), p_size = p.size();
        // for (int i=0; i<s_size-p_size; ++i){
        //     if (isAnagram(s.substr(i, p_size), p))
        //         res.push_back(i);
        // }
        // return res;

        // vector<int> res;
        // if(s.size() < p.size())
        //    return res;
 
        // unordered_map<char, int> hash_map;
        // for (char ch: p) hash_map[ch]++;
        
        // int s_size=s.size(), p_size=p.size();
        // for (int i=0; i<s_size-p_size+1; ++i) {
        //     unordered_map<char, int> temp_map;
        //     int j = 0;
            
        //     for(; j<p_size; ++j) {
        //         char ch = s[i+j];
        //         if (hash_map.find(ch)!=hash_map.end()) {
        //             temp_map[ch] ++ ;
        //             if (temp_map[ch]>hash_map[ch])
        //                 break;
        //         }
        //         else 
        //             break;
        //     }
        //     if (j==p_size)
        //         res.push_back(i);
        // }
        // return res;

        vector<int> res;
        vector<int> p_count(26, 0), s_count(26, 0);
        if(s.size() < p.size())
            return res;

        for (int i=0; i<p.size(); ++i){
            p_count[p[i]-'a']++;
            s_count[s[i]-'a']++;
        }
        if (p_count==s_count) 
            res.push_back(0);

        for(int i=p.size(); i<s.size(); ++i) {
            s_count[s[i]-'a']++;
            s_count[s[i-p.size()]-'a']--;

            if(s_count==p_count)
                res.push_back(i-p.size()+1);
        }
        return res;
    }

private:
    bool isAnagram(string s, string t) {
        // sort(s.begin(), s.end());
        // sort(t.begin(), t.end());
        // return s==t;

        if(s.size() != t.size()) return false;
        unordered_map<char, int> count;
        for(int i=0; i<s.size(); ++i){
            count[s[i]] ++;
            count[t[i]] --;
        }
        for(auto it:count) {
            if(it.second) return false;
        }
        return true;
    }
};
// @lc code=end

