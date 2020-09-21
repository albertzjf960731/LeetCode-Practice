/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

#include<vector>
#include<string>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        DFS(n, n, res, "");
        return res;
    }

    void DFS(int left, int right, vector<string>& res, string path) {
        if (left==0 && right==0) res.push_back(path);

        if (left>0) DFS(left-1, right, res, path+"(");
        if (right>left) DFS(left, right-1, res, path+")");
    }
};
// @lc code=end

