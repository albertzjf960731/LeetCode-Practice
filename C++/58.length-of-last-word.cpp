/*
 * @lc app=leetcode id=58 lang=cpp
 *
 * [58] Length of Last Word
 *
 * https://leetcode.com/problems/length-of-last-word/description/
 *
 * algorithms
 * Easy (32.36%)
 * Likes:    478
 * Dislikes: 1975
 * Total Accepted:    317.6K
 * Total Submissions: 981.1K
 * Testcase Example:  '"Hello World"'
 *
 * Given a string s consists of upper/lower-case alphabets and empty space
 * characters ' ', return the length of last word in the string.
 * 
 * If the last word does not exist, return 0.
 * 
 * Note: A word is defined as a character sequence consists of non-space
 * characters only.
 * 
 * Example:
 * 
 * 
 * Input: "Hello World"
 * Output: 5
 * 
 * 
 * 
 * 
 */
#include<string>
using namespace std;

// @lc code=start
class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0, index=s.size()-1;
        while (true) {
            if(index<0 || s[index]!=' ')
                break;
            index--;
        }
        for (int i=index; i>-1; i--) {
            if (s[i]==' ')
                break;
            count++;
        }
        return count;
    }
};
// @lc code=end

