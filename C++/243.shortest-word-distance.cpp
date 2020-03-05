/*
 * @lc app=leetcode id=243 lang=cpp
 *
 * [243] Shortest Word distance
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
 * For example,
 * Assume that words = ["practice", "makes", "perfect", "coding", "makes"].
 * 
 * Given word1 = “coding”, word2 = “practice”, return 3.
 * Given word1 = "makes", word2 = "coding", return 1.
 * 
 * Note:
 * You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.
 * 
 */
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
  int shortestDistance(vector<string>& words, string word1, string word2) {
        vector<int> idx1, idx2;
        for (int i=0; i<words.size(); ++i) {
            if (words[i]==word1) idx1.push_back(i);
            else if (words[i]==word2) idx2.push_back(i);
        }

        int ans = INT_MAX;
        for (int i=0; i<idx1.size(); ++i) {
            for (int j=0; j<idx2.size(); ++j) {
                ans = min(ans, abs(idx1[i]-idx2[j]));
            }
        }
        return ans;

        int p1=-1, p2=-1, ans = INT_MAX;
        for (int i=0; i<words.size(); ++i) {
            if (words[i] == word1) p1 = i;
            else if (words[i] == word2) p2 = i;
            
            if (p1!=-1 && p2!=-1) 
                ans = min(ans, abs(p1 - p2));
        }
        return ans;
    }
};