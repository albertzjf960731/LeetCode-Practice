/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 *
 * https://leetcode.com/problems/word-search/description/
 *
 * algorithms
 * Medium (33.05%)
 * Likes:    2526
 * Dislikes: 132
 * Total Accepted:    365.4K
 * Total Submissions: 1.1M
 * Testcase Example:  '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
 *
 * Given a 2D board and a word, find if the word exists in the grid.
 * 
 * The word can be constructed from letters of sequentially adjacent cell,
 * where "adjacent" cells are those horizontally or vertically neighboring. The
 * same letter cell may not be used more than once.
 * 
 * Example:
 * 
 * 
 * board =
 * [
 * ⁠ ['A','B','C','E'],
 * ⁠ ['S','F','C','S'],
 * ⁠ ['A','D','E','E']
 * ]
 * 
 * Given word = "ABCCED", return true.
 * Given word = "SEE", return true.
 * Given word = "ABCB", return false.
 * 
 * 
 */
#include<vector>
#include<string>
using namespace std; 

// @lc code=start
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty()) return false;
        for (int i=0; i<board.size(); i++) {
            for (int j=0; j<board[0].size(); j++) {
                if (DFS(board, i, j, word)) return true;
                // if (DFS(board, i, j, word, 0)) return true;
            }
        }
        return false;
    }

    bool DFS(vector<vector<char>>& board, int i, int j, string& word) {
        if (word.empty()) return true;
        if (i<0 || i>=board.size() || j<0 ||j>=board[0].size() || board[i][j] != word[0]) return false;

        char temp = board[i][j];
        board[i][j] = '#';
        string str = word.substr(1);
        bool res = (DFS(board, i+1, j, str) || DFS(board, i-1, j, str) || DFS(board, i, j+1, str) || DFS(board, i, j-1, str)) ;
        board[i][j] = temp;
        return res;  
    }
};
// @lc code=end

