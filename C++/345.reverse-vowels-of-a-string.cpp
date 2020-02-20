/*
 * @lc app=leetcode id=345 lang=cpp
 *
 * [345] Reverse Vowels of a String
 *
 * https://leetcode.com/problems/reverse-vowels-of-a-string/description/
 *
 * algorithms
 * Easy (43.02%)
 * Likes:    534
 * Dislikes: 962
 * Total Accepted:    193.9K
 * Total Submissions: 450.6K
 * Testcase Example:  '"hello"'
 *
 * Write a function that takes a string as input and reverse only the vowels of
 * a string.
 * 
 * Example 1:
 * 
 * 
 * Input: "hello"
 * Output: "holle"
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "leetcode"
 * Output: "leotcede"
 * 
 * 
 * Note:
 * The vowels does not include the letter "y".
 * 
 * 
 * 
 */
#include<string>
#include<unordered_set>
using namespace std;

// @lc code=start
class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> vowels{'a','e','i','o','u','A','E','I','O','U'};
        int left=0, right=s.size()-1;
        while (left<right) {
            if(vowels.count(s[left]) && vowels.count(s[right]))
                swap(s[left++], s[right--]);
            if (!vowels.count(s[left]))
               left++;
            if (!vowels.count(s[right])) 
               right--;
        }
        return s;
    }
};
// @lc code=end

