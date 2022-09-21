/*
 * @lc app=leetcode id=211 lang=cpp
 *
 * [211] Design Add and Search Words Data Structure
 *
 * https://leetcode.com/problems/design-add-and-search-words-data-structure/description/
 *
 * algorithms
 * Medium (43.50%)
 * Likes:    5451
 * Dislikes: 287
 * Total Accepted:    440.1K
 * Total Submissions: 1M
 * Testcase Example:  '["WordDictionary","addWord","addWord","addWord","search","search","search","search"]\n' +
  '[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]'
 *
 * Design a data structure that supports adding new words and finding if a
 * string matches any previously added string.
 * 
 * Implement the WordDictionary class:
 * 
 * 
 * WordDictionary() Initializes the object.
 * void addWord(word) Adds word to the data structure, it can be matched
 * later.
 * bool search(word) Returns true if there is any string in the data structure
 * that matches word or false otherwise. word may contain dots '.' where dots
 * can be matched with any letter.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input
 * 
 * ["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
 * [[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
 * Output
 * [null,null,null,null,false,true,true,true]
 * 
 * Explanation
 * WordDictionary wordDictionary = new WordDictionary();
 * wordDictionary.addWord("bad");
 * wordDictionary.addWord("dad");
 * wordDictionary.addWord("mad");
 * wordDictionary.search("pad"); // return False
 * wordDictionary.search("bad"); // return True
 * wordDictionary.search(".ad"); // return True
 * wordDictionary.search("b.."); // return True
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= word.length <= 25
 * word in addWord consists of lowercase English letters.
 * word in search consist of '.' or lowercase English letters.
 * There will be at most 3 dots in word for search queries.
 * At most 10^4 calls will be made to addWord and search.
 * 
 * 
 */

// @lc code=start
class WordDictionary {
public:
    struct TrieNode {
        TrieNode *child[26];
        bool isWord;
        TrieNode() : isWord(false) {
            for (auto &x: child) x = nullptr;
        }
    };
    
    TrieNode* root;
    
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* cur = root;
        for (char ch: word) {
            if (!cur->child[ch-'a']) cur->child[ch-'a'] = new TrieNode;
            cur = cur->child[ch-'a'];
        }
        cur->isWord = true;
    }
    
    bool search(string word) {
        return DFS(word, 0, root);
    }
    
    bool DFS(string& word, int i, TrieNode* cur) {
        if (i == word.size()) return cur->isWord;
        
        char ch = word[i];
        if (ch == '.') {
            for (auto& x: cur->child) {
                if (x && DFS(word, i+1, x)) return true;
            }
            return false;
        }
        else {
            return cur->child[ch-'a'] && DFS(word, i+1, cur->child[ch-'a']);
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end

