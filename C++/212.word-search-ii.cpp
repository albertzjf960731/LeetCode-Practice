/*
 * @lc app=leetcode id=212 lang=cpp
 *
 * [212] Word Search II
 *
 * https://leetcode.com/problems/word-search-ii/description/
 *
 * algorithms
 * Hard (31.82%)
 * Likes:    1767
 * Dislikes: 89
 * Total Accepted:    160.5K
 * Total Submissions: 504.4K
 * Testcase Example:  '[["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]]\n' +
  '["oath","pea","eat","rain"]'
 *
 * Given a 2D board and a list of words from the dictionary, find all words in
 * the board.
 * 
 * Each word must be constructed from letters of sequentially adjacent cell,
 * where "adjacent" cells are those horizontally or vertically neighboring. The
 * same letter cell may not be used more than once in a word.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: 
 * board = [
 * ⁠ ['o','a','a','n'],
 * ⁠ ['e','t','a','e'],
 * ⁠ ['i','h','k','r'],
 * ⁠ ['i','f','l','v']
 * ]
 * words = ["oath","pea","eat","rain"]
 * 
 * Output: ["eat","oath"]
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * All inputs are consist of lowercase letters a-z.
 * The values of words are distinct.
 * 
 * 
 */

// @lc code=start

struct TrieNode {
    TrieNode *child[26];
    string str;
    TrieNode() : str("") {
        for (auto &x: child) x = nullptr;
    }
};


class Solution {
public:
    
    TrieNode* root = new TrieNode();
    
    void insert(string word) {
        TrieNode *cur = root;
        for (char ch: word) {
            if (!cur->child[ch-'a']) cur->child[ch-'a'] = new TrieNode();
            cur = cur->child[ch-'a'];
        }
        cur->str = word;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ans;
        if (words.empty() || board.empty() || board[0].empty()) return ans;
        
        int n = board.size(), m = board[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        
        for (auto &w : words) insert(w);
        
        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                if (root->child[board[i][j]-'a']) {
                    search(board, root->child[board[i][j]-'a'], i, j, visited, ans);
                }
            }
        }
        return ans;
    }
    
    vector<vector<int>> dirs{{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    void search(vector<vector<char>>& board, TrieNode* cur, int i, int j, vector<vector<bool>>& visited, vector<string>& ans) { 
        if (!cur->str.empty()) {
            ans.push_back(cur->str);
            cur->str.clear();
        }

        int n = board.size(), m = board[0].size();
        
        visited[i][j] = true;
        for (auto &d : dirs) {
            int x = i+d[0], y = j+d[1];
            
            if (x<0 || x>=n || y<0 || y>=m) continue;
            if (visited[x][y]) continue;
            if (!cur->child[board[x][y]-'a']) continue;
            
            search(board, cur->child[board[x][y]-'a'], x, y, visited, ans);
        }
        visited[i][j] = false;
    }
};
// @lc code=end

