/*
 * @lc app=leetcode id=387 lang=cpp
 *
 * [387] First Unique Character in a String
 *
 * https://leetcode.com/problems/first-unique-character-in-a-string/description/
 *
 * algorithms
 * Easy (51.22%)
 * Likes:    1425
 * Dislikes: 98
 * Total Accepted:    378.2K
 * Total Submissions: 736.9K
 * Testcase Example:  '"leetcode"'
 *
 * 
 * Given a string, find the first non-repeating character in it and return it's
 * index. If it doesn't exist, return -1.
 * 
 * Examples:
 * 
 * s = "leetcode"
 * return 0.
 * 
 * s = "loveleetcode",
 * return 2.
 * 
 * 
 * 
 * 
 * Note: You may assume the string contain only lowercase letters.
 * 
 */
#include<unordered_map>
#include<string>
using namespace std;

// @lc code=start
class Solution {
public:
    int firstUniqChar(string str) {
        unordered_map<char, int> count;
        for(char ch: str) 
            count[ch]++;
        
        int ans = -1;
        for(int i=0; i<str.size(); ++i){
            if(count[str[i]]==1){
                ans = i;
                break;
            }
        }
        return ans;
    }
};
// @lc code=end

