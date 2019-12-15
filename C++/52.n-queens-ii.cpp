/*
 * @lc app=leetcode id=52 lang=cpp
 *
 * [52] N-Queens II
 *
 * https://leetcode.com/problems/n-queens-ii/description/
 *
 * algorithms
 * Hard (54.69%)
 * Likes:    365
 * Dislikes: 130
 * Total Accepted:    115.3K
 * Total Submissions: 210.6K
 * Testcase Example:  '4'
 *
 * The n-queens puzzle is the problem of placing n queens on an n×n chessboard
 * such that no two queens attack each other.
 * 
 * 
 * 
 * Given an integer n, return the number of distinct solutions to the n-queens
 * puzzle.
 * 
 * Example:
 * 
 * 
 * Input: 4
 * Output: 2
 * Explanation: There are two distinct solutions to the 4-queens puzzle as
 * shown below.
 * [
 * [".Q..",  // Solution 1
 * "...Q",
 * "Q...",
 * "..Q."],
 * 
 * ["..Q.",  // Solution 2
 * "Q...",
 * "...Q",
 * ".Q.."]
 * ]
 * 
 * 
 */
#include<vector>
#include<string>
#include<iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    int totalNQueens(int n) {
        int ans=0;
        vector<vector<string>> res;
        vector<string> path(n, string(n, '.'));
        DFS(ans, path, 0, n);
        // cout<<"ans="<<ans<<endl;
        // return res.size();
        return ans;
    }

    void DFS(int& ans, vector<string>& path, int row, int n) {
        if (row == n) {
            // res.push_back(path);
            ans += 1;
            return;
        }

        for (int col=0; col<n; col++) {
            if (isValid(path, row, col, n)) {
                path[row][col] = 'Q';
                DFS(ans, path, row+1, n);
                path[row][col] = '.';
            }
        }
    }

    bool isValid(vector<string>& path, int row, int col, int n) {
        for (int i=0; i<row; i++) 
            if(path[i][col] == 'Q')
                return false;
        
        for (int i=row-1, j=col-1; i>=0 && i>=0; i--, j--) 
            if(path[i][j]=='Q')
                return false;
        
        for (int i=row-1, j=col+1; i>=0 && j<n; i--, j++) 
            if(path[i][j]=='Q')
                return false;

        return true;
    }

};
// @lc code=end


int main() {
    Solution sol;
    int n = 4;
    int res = sol.totalNQueens(n);
    cout<<"res="<<res<<endl;
}