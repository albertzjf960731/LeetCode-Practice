/*
 * @lc app=leetcode id=130 lang=cpp
 *
 * [130] Surrounded Regions
 *
 * https://leetcode.com/problems/surrounded-regions/description/
 *
 * algorithms
 * Medium (25.22%)
 * Likes:    1165
 * Dislikes: 536
 * Total Accepted:    183.6K
 * Total Submissions: 727.4K
 * Testcase Example:  '[["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]'
 *
 * Given a 2D board containing 'X' and 'O' (the letter O), capture all regions
 * surrounded by 'X'.
 * 
 * A region is captured by flipping all 'O's into 'X's in that surrounded
 * region.
 * 
 * Example:
 * 
 * 
 * X X X X
 * X O O X
 * X X O X
 * X O X X
 * 
 * 
 * After running your function, the board should be:
 * 
 * 
 * X X X X
 * X X X X
 * X X X X
 * X O X X
 * 
 * 
 * Explanation:
 * 
 * Surrounded regions shouldn’t be on the border, which means that any 'O' on
 * the border of the board are not flipped to 'X'. Any 'O' that is not on the
 * border and it is not connected to an 'O' on the border will be flipped to
 * 'X'. Two cells are connected if they are adjacent cells connected
 * horizontally or vertically.
 * 
 */

#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;
        
        int rows=board.size(), cols=board[0].size();
        for (int i=0; i<rows; i++) {
            if (board[i][0]=='O')
                DFS(board, i, 0);
            if (board[i][cols-1]=='O')
                DFS(board, i, cols-1);
        }
        for (int j=0; j<cols; j++) {
            if (board[0][j]=='O')
                DFS(board, 0, j);
            if (board[rows-1][j]=='O') {
                DFS(board, rows-1, j);
            }
        }
        
        for (int i=0; i<rows; i++) {
            for (int j=0; j<cols; j++) {
                if (board[i][j]=='O')
                    board[i][j] = 'X';
                else if (board[i][j]=='#')
                    board[i][j] = 'O';
            }
        }
    }
    
    void DFS(vector<vector<char>>& board, int i, int j) {
        if (i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j]!='O')
            return;
        board[i][j] = '#';
        DFS(board, i-1, j);
        DFS(board, i+1, j);
        DFS(board, i, j-1);
        DFS(board, i, j+1);
    }
};
// @lc code=end

