#
# @lc app=leetcode id=745 lang=python3
#
# [745] Prefix and Suffix Search
#
# https://leetcode.com/problems/prefix-and-suffix-search/description/
#
# algorithms
# Hard (41.14%)
# Likes:    2276
# Dislikes: 483
# Total Accepted:    97.6K
# Total Submissions: 237.2K
# Testcase Example:  '["WordFilter","f"]\n[[["apple"]],["a","e"]]'
#
# Design a special dictionary that searches the words in it by a prefix and a
# suffix.
# 
# Implement the WordFilter class:
# 
# 
# WordFilter(string[] words) Initializes the object with the words in the
# dictionary.
# f(string pref, string suff) Returns the index of the word in the dictionary,
# which has the prefix pref and the suffix suff. If there is more than one
# valid index, return the largest of them. If there is no such word in the
# dictionary, return -1.
# 
# 
# 
# Example 1:
# 
# 
# Input
# ["WordFilter", "f"]
# [[["apple"]], ["a", "e"]]
# Output
# [null, 0]
# Explanation
# WordFilter wordFilter = new WordFilter(["apple"]);
# wordFilter.f("a", "e"); // return 0, because the word at index 0 has prefix =
# "a" and suffix = "e".
# 
# 
# 
# Constraints:
# 
# 
# 1 <= words.length <= 10^4
# 1 <= words[i].length <= 7
# 1 <= pref.length, suff.length <= 7
# words[i], pref and suff consist of lowercase English letters only.
# At most 10^4 calls will be made to the function f.
# 
# 
#

# @lc code=start
class TrieNode:
    def __init__(self):
        self.children = {} # ch: TrieNode
        self.wordIdx = []

class Trie:
    def __init__(self):
        self.root = TrieNode()
    
    def insert(self, word, idx):
        cur = self.root
        for ch in word:
            if ch not in cur.children:
                cur.children[ch] = TrieNode()
            cur = cur.children[ch]
            cur.wordIdx.append(idx)

class WordFilter:

    def __init__(self, words: List[str]):
        hset = set()
        self.prefixTrie = Trie()
        self.suffixTrie = Trie()

        for i in range(len(words)-1, -1, -1):
            w = words[i]
            if w in hset:
                continue
            self.prefixTrie.insert(w, i)
            self.suffixTrie.insert(w[::-1], i)
            hset.add(w)

    def f(self, pref: str, suff: str) -> int:
        cur = self.prefixTrie.root
        for ch in pref:
            if ch not in cur.children:
                return -1
            cur = cur.children[ch]
        prefIdx = cur.wordIdx

        cur = self.suffixTrie.root
        for ch in suff[::-1]:
            if ch not in cur.children:
                return -1
            cur = cur.children[ch]
        suffIdx = cur.wordIdx

        union = set(prefIdx) & set(suffIdx)
        return max(union) if union else -1

# Your WordFilter object will be instantiated and called as such:
# obj = WordFilter(words)
# param_1 = obj.f(pref,suff)
# @lc code=end

