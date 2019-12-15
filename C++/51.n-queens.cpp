/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 *
 * https://leetcode.com/problems/n-queens/description/
 *
 * algorithms
 * Hard (42.62%)
 * Likes:    1307
 * Dislikes: 59
 * Total Accepted:    169.7K
 * Total Submissions: 397.8K
 * Testcase Example:  '4'
 *
 * The n-queens puzzle is the problem of placing n queens on an n×n chessboard
 * such that no two queens attack each other.
 * 
 * 
 * 
 * Given an integer n, return all distinct solutions to the n-queens puzzle.
 * 
 * Each solution contains a distinct board configuration of the n-queens'
 * placement, where 'Q' and '.' both indicate a queen and an empty space
 * respectively.
 * 
 * Example:
 * 
 * 
 * Input: 4
 * Output: [
 * ⁠[".Q..",  // Solution 1
 * ⁠ "...Q",
 * ⁠ "Q...",
 * ⁠ "..Q."],
 * 
 * ⁠["..Q.",  // Solution 2
 * ⁠ "Q...",
 * ⁠ "...Q",
 * ⁠ ".Q.."]
 * ]
 * Explanation: There exist two distinct solutions to the 4-queens puzzle as
 * shown above.
 * 
 * 
 */
#include<string>
#include<vector>
#include<iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    // vector<vector<string>> solveNQueens(int n) {
    //     vector<vector<int>> res;
    //     vector<int> queens, xy_dif, xy_sum;
    //     DFS(queens, xy_dif, xy_sum, res, n);
        
    //     vector<vector<string>> str_res;
    //     for (auto sol: res) {
    //         vector<string> str_sol;
    //         for (int i: sol) {
    //             string dot1(i, '.');
    //             string dot2(n-i-1, '.');
    //             str_sol.push_back(dot1+"Q"+dot2);
    //         }
    //         str_res.push_back(str_sol);
    //     }
    //     return str_res;
    // }

    // void DFS(vector<int>& queens, vector<int>& xy_dif, vector<int>& xy_sum, vector<vector<int>>& res, int n) {
    //     int p = queens.size();
    //     if(p==n){
    //         res.push_back(queens);
    //         return ;
    //     }
        
    //     for (int q=0; q<n; q++) {
    //         if (find(queens.begin(), queens.end(), q)==queens.end() && find(xy_dif.begin(), xy_dif.end(), p-q)==xy_dif.end() && find(xy_sum.begin(), xy_sum.end(), p+q)==xy_sum.end()) {
    //             queens.push_back(q);
    //             xy_dif.push_back(p-q);
    //             xy_sum.push_back(p+q);
    //             DFS(queens, xy_dif, xy_sum, res, n);
    //             xy_sum.pop_back();
    //             xy_dif.pop_back();
    //             queens.pop_back();
    //         }
    //     }
    // }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> path(n, string(n, '.'));
        DFS(res, path, 0, n);
        return res;
    }

    void DFS(vector<vector<string>>& res, vector<string>& path, int row, int n) {
        if (row == n) {
            res.push_back(path);
            return;
        }

        for (int col=0; col<n; col++) {
            if (isValid(path, row, col, n)) {
                path[row][col] = 'Q';
                DFS(res, path, row+1, n);
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
    vector<vector<string>> res = sol.solveNQueens(n);
}