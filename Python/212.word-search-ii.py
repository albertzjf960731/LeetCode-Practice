#
# @lc app=leetcode id=212 lang=python
#
# [212] Word Search II
#
# https://leetcode.com/problems/word-search-ii/description/
#
# algorithms
# Hard (30.68%)
# Likes:    1548
# Dislikes: 84
# Total Accepted:    144K
# Total Submissions: 466.3K
# Testcase Example:  '[["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]]\n' +
#   '["oath","pea","eat","rain"]'
#
# Given a 2D board and a list of words from the dictionary, find all words in
# the board.
# 
# Each word must be constructed from letters of sequentially adjacent cell,
# where "adjacent" cells are those horizontally or vertically neighboring. The
# same letter cell may not be used more than once in a word.
# 
# 
# 
# Example:
# 
# 
# Input: 
# board = [
# ⁠ ['o','a','a','n'],
# ⁠ ['e','t','a','e'],
# ⁠ ['i','h','k','r'],
# ⁠ ['i','f','l','v']
# ]
# words = ["oath","pea","eat","rain"]
# 
# Output: ["eat","oath"]
# 
# 
# 
# 
# Note:
# 
# 
# All inputs are consist of lowercase letters a-z.
# The values of words are distinct.
# 
# 
#

# @lc code=start
class TrieNode:
    def __init__(self):
        self.children = {}
        self.isWord = False

class Trie():
    def __init__(self):
        self.root = TrieNode()
    def insert(self, word):
        cur = self.root
        for ch in word:
            if ch not in cur.children:
                cur.children[ch] = TrieNode()
            cur = cur.children[ch]
        cur.isWord = True
    def search(self, word):
        cur = self.root
        for ch in word:
            if ch not in cur.children:
                return False
            cur = cur.chidren[ch]
        return cur.isWord

class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        trie = Trie()
        for w in words:
            trie.insert(w)
        
        ans = []
        for i in range(len(board)):
            for j in range(len(board[0])):
                self.dfs(board, i, j, trie.root, "", ans)
        return ans

    def dfs(self, board, i, j, node, path, ans):
        if node.isWord:
            ans.append(path)
            node.isWord = False
        
        if i < 0 or i >= len(board) or j < 0 or j >= len(board[0]):
            return 
        
        ch = board[i][j]
        if ch not in node.children:
            return
        node = node.children[ch]
        board[i][j] = '#'
        self.dfs(board, i+1, j, node, path+ch, ans)
        self.dfs(board, i-1, j, node, path+ch, ans)
        self.dfs(board, i, j+1, node, path+ch, ans)
        self.dfs(board, i, j-1, node, path+ch, ans)
        board[i][j] = ch 
# @lc code=end

