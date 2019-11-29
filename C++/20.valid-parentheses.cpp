/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */
#include<string>
#include<vector>
#include<unordered_map>
#include<iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    bool isValid(string s) {

        unordered_map<char, char> hash_map = {{'(', ')'}, {'[', ']'}, {'{', '}'}};

        vector<char> stack;
        for (char ch: s) {
            if (ch=='(' || ch=='{' || ch=='[') 
                stack.push_back(ch);
            else if (stack.size()!=0 && ch==hash_map[stack.back()])
                stack.pop_back();
            else 
                return false;
        }
        return stack.size() == 0;
    }
};
// @lc code=end
int main() {
    Solution sol;
    string s = "()";
    cout << sol.isValid(s) << endl;
}
