/*
 * @lc app=leetcode id=394 lang=cpp
 *
 * [394] Decode String
 *
 * https://leetcode.com/problems/decode-string/description/
 *
 * algorithms
 * Medium (47.57%)
 * Likes:    2323
 * Dislikes: 122
 * Total Accepted:    159.2K
 * Total Submissions: 333.7K
 * Testcase Example:  '"3[a]2[bc]"'
 *
 * Given an encoded string, return its decoded string.
 * 
 * The encoding rule is: k[encoded_string], where the encoded_string inside the
 * square brackets is being repeated exactly k times. Note that k is guaranteed
 * to be a positive integer.
 * 
 * You may assume that the input string is always valid; No extra white spaces,
 * square brackets are well-formed, etc.
 * 
 * Furthermore, you may assume that the original data does not contain any
 * digits and that digits are only for those repeat numbers, k. For example,
 * there won't be input like 3a or 2[4].
 * 
 * Examples:
 * 
 * 
 * s = "3[a]2[bc]", return "aaabcbc".
 * s = "3[a2[c]]", return "accaccacc".
 * s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
 * 
 * 
 * 
 * 
 */
#include<vector>
#include<string>
using namespace std;

// @lc code=start
class Solution {
public:
    string decodeString(string str) {
        string stack;
        for (int i=0; i<str.size(); i++) {
            if (str[i]==']') {
                string path = "";
                while (stack.back()!='[') {
                    path.push_back(stack.back());
                    stack.pop_back();
                }
                stack.pop_back();
                    
                string num="";
                while (!stack.empty() && isdigit(stack.back())) {
                    num = stack.back() + num;
                    stack.pop_back();
                }
                // reverse(num.begin(), num.end());
                int k = stoi(num);
                
                while(k--) {
                    for (int j=path.size()-1; j>=0; j--) {
                        stack.push_back(path[j]);
                    }
                }
            }
            else 
                stack.push_back(str[i]);
        }
        return stack;
    }
};
// @lc code=end

