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
    // int totalNQueens(int n) {
    //     int ans=0;
    //     vector<vector<string>> res;
    //     vector<string> path(n, string(n, '.'));
    //     DFS(ans, path, 0, n);
    //     // cout<<"ans="<<ans<<endl;
    //     // return res.size();
    //     return ans;
    // }

    // void DFS(int& ans, vector<string>& path, int row, int n) {
    //     if (row == n) {
    //         // res.push_back(path);
    //         ans += 1;
    //         return;
    //     }

    //     for (int col=0; col<n; col++) {
    //         if (isValid(path, row, col, n)) {
    //             path[row][col] = 'Q';
    //             DFS(ans, path, row+1, n);
    //             path[row][col] = '.';
    //         }
    //     }
    // }

    // bool isValid(vector<string>& path, int row, int col, int n) {
    //     for (int i=0; i<row; i++) 
    //         if(path[i][col] == 'Q')
    //             return false;
        
    //     for (int i=row-1, j=col-1; i>=0 && i>=0; i--, j--) 
    //         if(path[i][j]=='Q')
    //             return false;
        
    //     for (int i=row-1, j=col+1; i>=0 && j<n; i--, j++) 
    //         if(path[i][j]=='Q')
    //             return false;

    //     return true;
    // }
    // int totalNQueens(int n) {
    //     int ans = 0;
    //     DFS(n, 0, 0, 0, 0, ans);
    //     return ans;
    // }
    // void DFS(int n, int row, int num1, int num2, int num3, int& ans) {
    //     if (row==n) {
    //         ans++;
    //         return;
    //     }
    //     for (int col=0; col<n; col++) {
    //         int num = 1<<col;
    //         if (num&num1 || num&num2 || num&num3) continue;
    //         DFS(n, row+1, (num|num1), (num|num2)<<1, (num|num3)>>1, ans);
    //     }
    // }

    int totalNQueens(int n) {
        int ans = 0;
        vector<int> pos(n, -1);
        DFS(n, 0, pos, ans);
        return ans;
    }
    void DFS(int n, int row, vector<int>& pos, int& ans) {
        if (row==n) {
            ans++;
            return;
        }
        for (int col=0; col<n; col++) {
            if (isValid(pos, row, col)) {
                pos[row] = col;
                DFS(n, row+1, pos, ans);
                pos[row] = -1;
            }
        }
    }
    bool isValid(vector<int>& pos, int row, int col) {
        for (int i=0; i<row; i++) {
            if (col==pos[i] || abs(row-col)==abs(i-pos[i]))
                return false;
        }
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