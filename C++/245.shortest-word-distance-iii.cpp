/*
 * @lc app=leetcode id=245 lang=cpp
 *
 * [245] Shortest Word distance III
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
 * Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.
 * 
 * word1 and word2 may be the same and they represent two individual words in the list.
 * 
 * Example:
 * Assume that words = ["practice", "makes", "perfect", "coding", "makes"].
 * 
 * Input: word1 = “makes”, word2 = “coding”
 * Output: 1
 * Input: word1 = "makes", word2 = "makes"
 * Output: 3
 * 
 * Note:
 * You may assume word1 and word2 are both in the list.
 * 
 * 
 */
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        int p1 = words.size(), p2 = -words.size(), ans = INT_MAX;
        for (int i=0; i<words.size(); ++i) {
            if (words[i]==word1) 
                p1 = word1==word2 ? p2 : i;
            if (words[i] == word2) 
                p2 = i;
            ans = min(ans, abs(p1-p2));
        }
        return ans;
    }
};