/*
 * @lc app=leetcode id=244 lang=cpp
 *
 * [244] Shortest Word distance II
 *
 * https://leetcode.com/problems/valid-anagram/description/
 *
 * algorithms
 * Easy (54.64%)
 * Likes:    1093
 * Dislikes: 128
 * Total Accepted:    464.4K
 * Total Submissions: 846K
 * Testcase Example:  '"anagram"\n"nagaram"'
 *
 * This is a follow up of Shortest Word Distance. The only difference is now you are given the list of words and your method will be called repeatedly many times with different parameters. How would you optimize it?
 * 
 * Design a class which receives a list of words in the constructor, and implements a method that takes two words word1 and word2 and return the shortest distance between these two words in the list.
 * 
 * For example,
 * Assume that words = ["practice", "makes", "perfect", "coding", "makes"].
 * 
 * Given word1 = “coding”, word2 = “practice”, return 3.
 * Given word1 = "makes", word2 = "coding", return 1.
 * 
 * Note:
 * You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.
 * 
 * 
 */
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

class WordDistance { 
private:
    unordered_map<string, vector<int> > hash_map;

public:
    WordDistance(vector<string>& words) {
        for (int i=0; i<words.size(); ++i) {
            hash_map[words[i]].push_back(i);
        }
    }

    int shortest(string word1, string word2) {
        int i = 0, j = 0, ans = INT_MAX;
        while (i<hash_map[word1].size() && j<hash_map[word2].size()) {
            ans = min(ans, abs(hash_map[word1][i]-hash_map[word2][j]));
            
            hash_map[word1][i] < hash_map[word2][j] ? ++i : ++j;
        }
        return ans;
    }

};