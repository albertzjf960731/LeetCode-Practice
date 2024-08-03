#
# @lc app=leetcode id=211 lang=python3
#
# [211] Design Add and Search Words Data Structure
#
# https://leetcode.com/problems/design-add-and-search-words-data-structure/description/
#
# algorithms
# Medium (45.61%)
# Likes:    7589
# Dislikes: 452
# Total Accepted:    660.1K
# Total Submissions: 1.4M
# Testcase Example:  '["WordDictionary","addWord","addWord","addWord","search","search","search","search"]\n' +
#   '[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]'
#
# Design a data structure that supports adding new words and finding if a
# string matches any previously added string.
# 
# Implement the WordDictionary class:
# 
# 
# WordDictionary() Initializes the object.
# void addWord(word) Adds word to the data structure, it can be matched
# later.
# bool search(word) Returns true if there is any string in the data structure
# that matches word or false otherwise. word may contain dots '.' where dots
# can be matched with any letter.
# 
# 
# 
# Example:
# 
# 
# Input
# 
# ["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
# [[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
# Output
# [null,null,null,null,false,true,true,true]
# 
# Explanation
# WordDictionary wordDictionary = new WordDictionary();
# wordDictionary.addWord("bad");
# wordDictionary.addWord("dad");
# wordDictionary.addWord("mad");
# wordDictionary.search("pad"); // return False
# wordDictionary.search("bad"); // return True
# wordDictionary.search(".ad"); // return True
# wordDictionary.search("b.."); // return True
# 
# 
# 
# Constraints:
# 
# 
# 1 <= word.length <= 25
# word in addWord consists of lowercase English letters.
# word in search consist of '.' or lowercase English letters.
# There will be at most 2 dots in word for search queries.
# At most 10^4 calls will be made to addWord and search.
# 
# 
#

# @lc code=start
class TrieNode:
    def __init__(self):
        self.children = {} # ch: TrieNode
        self.isWord = False

class WordDictionary:

    def __init__(self):
        self.root = TrieNode()
        
    def addWord(self, word: str) -> None:
        cur = self.root
        for ch in word:
            if ch not in cur.children:
                cur.children[ch] = TrieNode()
            cur = cur.children[ch]
        cur.isWord = True

    def search(self, word: str) -> bool:
        return self.dfs(word, 0, self.root)
    
    def dfs(self, word, idx, cur):
        if idx == len(word):
            return cur.isWord

        ch = word[idx]
        if ch == '.':
            for node in cur.children.values():
                if self.dfs(word, idx+1, node):
                    return True
            return False
        if ch not in cur.children:
            return False
        return self.dfs(word, idx+1, cur.children[ch])


# Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary()
# obj.addWord(word)
# param_2 = obj.search(word)
# @lc code=end

