/*
 * @lc app=leetcode id=290 lang=cpp
 *
 * [290] Word Pattern
 *
 * https://leetcode.com/problems/word-pattern/description/
 *
 * algorithms
 * Easy (36.07%)
 * Likes:    879
 * Dislikes: 123
 * Total Accepted:    168.5K
 * Total Submissions: 466.1K
 * Testcase Example:  '"abba"\n"dog cat cat dog"'
 *
 * Given a pattern and a string str, find if str follows the same pattern.
 * 
 * Here follow means a full match, such that there is a bijection between a
 * letter in pattern and a non-empty word in str.
 * 
 * Example 1:
 * 
 * 
 * Input: pattern = "abba", str = "dog cat cat dog"
 * Output: true
 * 
 * Example 2:
 * 
 * 
 * Input:pattern = "abba", str = "dog cat cat fish"
 * Output: false
 * 
 * Example 3:
 * 
 * 
 * Input: pattern = "aaaa", str = "dog cat cat dog"
 * Output: false
 * 
 * Example 4:
 * 
 * 
 * Input: pattern = "abba", str = "dog dog dog dog"
 * Output: false
 * 
 * Notes:
 * You may assume pattern contains only lowercase letters, and str contains
 * lowercase letters that may be separated by a single space.
 * 
 */
#include<string>
#include<unordered_map>
#include<iostream>
#include<sstream>
using namespace std;

// @lc code=start
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, int> p2i;
        unordered_map<string, int> w2i;

        istringstream in(str);
        int i=0, n=pattern.size();
        for (string word; in >> word; ++i) {
            if (i==n || p2i[pattern[i]]!=w2i[word])
                return false;
            p2i[pattern[i]] = w2i[word] = i+1;
        }
        return i==n;
    }
};
// @lc code=end

