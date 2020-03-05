/*
 * @lc app=leetcode id=246 lang=cpp
 *
 * [246] Strobogrammatic Number
 *
 * https://leetcode.com/problems/valid-anagram/description/
 *
 * algorithms
 * Easy (54.64%)
 * Likes:    1093
 * Dislikes: 128
 * Total Accepted:    464.4K
 * Total Submissions: 846K
 * Testcase Example:  '"anagram"\n"nagaram"'
 *
 * A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).
 * 
 * Write a function to determine if a number is strobogrammatic. The number is represented as a string.
 * 
 * Example 1:
 * Input:  "69"
 * Output: true
 * 
 * Example 2:
 * Input:  "88"
 * Output: true
 * 
 * Example 3:
 * Input:  "962"
 * Output: false
 * 
 */
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
    bool isStrobogrammatic(string num) {
        unordered_map<char, char> hash_map {{'0', '0'}, {'1', '1'}, {'8', '8'}, {'6', '9'}, {'9', '6'}};
        for (int i=0; i<=num.size()/2; ++i) {
            if (hash_map[num[i]] != num[num.size()-1-i]) return false;
        }
        return true;
    }
};