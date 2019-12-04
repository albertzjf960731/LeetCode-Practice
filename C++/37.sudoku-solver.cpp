/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] Sudoku Solver
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        Solve(board);
    }

    bool Solve(vector<vector<char>>& board) {        
        for (int i=0; i<9; i++) {
            for (int j=0; j<9; j++) {
                if (board[i][j] == '.') {
                    int num = 1;
                    while (num<=9) {
                        if(IsValid(i, j, board, num)) {
                            board[i][j] = num+'0';
                            if (Solve(board))
                                return true;
                            else 
                                board[i][j] = '.';
                        }
                        num++;
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    bool IsValid(int row, int col, vector<vector<char>>& board, int num) {
        for (int i=0; i<9; i++){
            if (board[i][col] == num+'0')
                return false;
        }
        for (int j=0; j<9; j++) {
            if (board[row][j] == num+'0')
                return false;
        }
        int row_start=row/3*3, col_start=col/3*3;
        for (int i=0; i<3; i++){
            for (int j=0; j<3; j++){
                if (board[row_start+i][col_start+j]==num+'0')
                    return false;
            }
        }
        return true;
    }
};
// @lc code=end

