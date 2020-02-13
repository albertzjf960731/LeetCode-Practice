/*
 * @lc app=leetcode id=126 lang=cpp
 *
 * [126] Word Ladder II
 *
 * https://leetcode.com/problems/word-ladder-ii/description/
 *
 * algorithms
 * Hard (20.33%)
 * Likes:    1441
 * Dislikes: 219
 * Total Accepted:    158.7K
 * Total Submissions: 779.5K
 * Testcase Example:  '"hit"\n"cog"\n["hot","dot","dog","lot","log","cog"]'
 *
 * Given two words (beginWord and endWord), and a dictionary's word list, find
 * all shortest transformation sequence(s) from beginWord to endWord, such
 * that:
 * 
 * 
 * Only one letter can be changed at a time
 * Each transformed word must exist in the word list. Note that beginWord is
 * not a transformed word.
 * 
 * 
 * Note:
 * 
 * 
 * Return an empty list if there is no such transformation sequence.
 * All words have the same length.
 * All words contain only lowercase alphabetic characters.
 * You may assume no duplicates in the word list.
 * You may assume beginWord and endWord are non-empty and are not the same.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input:
 * beginWord = "hit",
 * endWord = "cog",
 * wordList = ["hot","dot","dog","lot","log","cog"]
 * 
 * Output:
 * [
 * ⁠ ["hit","hot","dot","dog","cog"],
 * ["hit","hot","lot","log","cog"]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * beginWord = "hit"
 * endWord = "cog"
 * wordList = ["hot","dot","dog","lot","log"]
 * 
 * Output: []
 * 
 * Explanation: The endWord "cog" is not in wordList, therefore no possible
 * transformation.
 * 
 * 
 * 
 * 
 * 
 */
#include<vector>
#include<queue>
#include<string>
#include<unordered_set>
#include<unordered_map>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        // The idea is to first use BFS to search from beginWord to endWord and generate the word-to-children mapping at the same time. Then, use DFS (backtracking) to generate the transformation sequences according to the mapping.
        
        vector<vector<string>> res;

        if (wordList.empty()) return res;
        unordered_set<string> word_set(wordList.begin(), wordList.end());
        if (!word_set.count(endWord)) return res;
        unordered_set<string> cur_words, next_words;

        unordered_map<string, vector<string>> trans_map;
        vector<string> path;

        cur_words.insert(beginWord);
        path.push_back(beginWord);
        while (true) {
            for (string word: cur_words)
                word_set.erase(word);

            for (string word: cur_words)
                transWord(word, next_words, word_set, trans_map);
            if (next_words.empty()) break;

            if (next_words.count(endWord)) {
                genLadders(beginWord, endWord, trans_map, path, res);
                break;
            }

            // 更高效
            cur_words.clear();
            swap(cur_words, next_words);
        }
        return res;
    }

    void transWord(string word, unordered_set<string>& next, unordered_set<string>& word_set, unordered_map<string, vector<string>>& trans_map) {
        string orig_word = word;

        for (int i=0; i<word.size(); i++) {
            char ch = word[i];
            for (int j='a'; j<='z'; j++) {
                word[i] = j;
                if (word_set.count(word)) {
                    next.insert(word);
                    trans_map[orig_word].push_back(word);
                }
            }
            word[i] = ch;
        }
    }

    void genLadders(string word, string endWord, unordered_map<string, vector<string>>& trans_map, vector<string>& path, vector<vector<string>>& res) {
        if (word==endWord) {
            res.push_back(path);
            return;
        }
        for (string next_word : trans_map[word]) {
            path.push_back(next_word);
            genLadders(next_word, endWord, trans_map, path, res);
            path.pop_back();
        }
    }
};
// @lc code=end

