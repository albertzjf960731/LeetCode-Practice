/*
 * @lc app=leetcode id=140 lang=cpp
 *
 * [140] Word Break II
 *
 * https://leetcode.com/problems/word-break-ii/description/
 *
 * algorithms
 * Hard (29.53%)
 * Likes:    1447
 * Dislikes: 319
 * Total Accepted:    197.6K
 * Total Submissions: 669.1K
 * Testcase Example:  '"catsanddog"\n["cat","cats","and","sand","dog"]'
 *
 * Given a non-empty string s and a dictionary wordDict containing a list of
 * non-empty words, add spaces in s to construct a sentence where each word is
 * a valid dictionary word. Return all such possible sentences.
 * 
 * Note:
 * 
 * 
 * The same word in the dictionary may be reused multiple times in the
 * segmentation.
 * You may assume the dictionary does not contain duplicate words.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input:
 * s = "catsanddog"
 * wordDict = ["cat", "cats", "and", "sand", "dog"]
 * Output:
 * [
 * "cats and dog",
 * "cat sand dog"
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * s = "pineapplepenapple"
 * wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
 * Output:
 * [
 * "pine apple pen apple",
 * "pineapple pen apple",
 * "pine applepen apple"
 * ]
 * Explanation: Note that you are allowed to reuse a dictionary word.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input:
 * s = "catsandog"
 * wordDict = ["cats", "dog", "sand", "and", "cat"]
 * Output:
 * []
 * 
 */
#include<vector>
#include<string>
#include<unordered_set>
#include<unordered_map>
using namespace std;

// @lc code=start
class Solution {
public:
     vector<string> wordBreak(string str, vector<string>& wordDict) {
        unordered_map<string, vector<string>> cache;
        unordered_set<string> word_set(wordDict.begin(), wordDict.end());
        
        return DFS(str, word_set, cache);
    }
    
    vector<string> combine(string word, vector<string> prev){
        for(int i=0;i<prev.size();++i){
            prev[i]+=" "+word;
        }
        return prev;
    }

    vector<string> DFS(string str, unordered_set<string>& word_set, unordered_map<string, vector<string>>& cache) {
        if (cache.count(str))
            return cache[str];
        
        vector<string> res;
        if (word_set.count(str)) {
            res.push_back(str);
        }
        
        for (int len=1; len<=str.size(); ++len) {
            string word = str.substr(0, len);
            if (word_set.count(word)) {
                vector<string> tails = DFS(str.substr(word.size()), word_set, cache);
                for(string tail: tails) {
                    tail = word + " " + tail;
                    res.push_back(tail);
                }
            }
        }
        cache[str] = res;
        return res;
    }
    // void DFS(string str, unordered_set<string>& dicts, int start, string path, vector<string>& res) {
    //     if (start == str.size()){
    //         path.erase(path.begin());
    //         res.push_back(path);
    //     }
        
    //     for (int i=start; i<str.size(); i++) {
    //         string sub_str = str.substr(start, i-start+1);
    //         if (dicts.count(sub_str))
    //             DFS(str, dicts, i+1, path+" "+sub_str, res);
    //     }


     vector<string> wordBreak(string str, vector<string>& wordDict) {
        unordered_set<string> dicts(wordDict.begin(), wordDict.end());
        unordered_map<int, vector<string>> cache {{str.size(), {""}}};
        
        function<vector<string>(int)> DFS = [&](int i) {
            if (cache.count(i))
                return cache[i];
            for (int j=i+1; j<=str.size(); j++) {
                string sub = str.substr(i, j-i);
                if (dicts.count(sub)) {
                    vector<string> tails = DFS(j);
                    for (string tail: tails) {
                        if (tail.empty())
                            cache[i].push_back(sub);
                        else
                            cache[i].push_back(sub + " " + tail);
                    }
                }
            }
            return cache[i];
        };
        return DFS(0);
     }
};
// @lc code=end

