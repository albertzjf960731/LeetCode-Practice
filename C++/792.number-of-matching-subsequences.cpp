/*
 * @lc app=leetcode id=792 lang=cpp
 *
 * [792] Number of Matching Subsequences
 *
 * https://leetcode.com/problems/number-of-matching-subsequences/description/
 *
 * algorithms
 * Medium (47.47%)
 * Likes:    1002
 * Dislikes: 74
 * Total Accepted:    43.6K
 * Total Submissions: 91.7K
 * Testcase Example:  '"abcde"\n["a","bb","acd","ace"]'
 *
 * Given string S and a dictionary of words words, find the number of words[i]
 * that is a subsequence of S.
 * 
 * 
 * Example :
 * Input: 
 * S = "abcde"
 * words = ["a", "bb", "acd", "ace"]
 * Output: 3
 * Explanation: There are three words in words that are a subsequence of S:
 * "a", "acd", "ace".
 * 
 * 
 * Note:
 * 
 * 
 * All words in words and S will only consists of lowercase letters.
 * The length of S will be in the range of [1, 50000].
 * The length of words will be in the range of [1, 5000].
 * The length of words[i] will be in the range of [1, 50].
 * 
 * 
 */
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        unordered_map<char, vector<int>> char2pos;
        for (int i=0; i<S.size(); ++i) char2pos[S[i]].push_back(i);
        
        int ans = 0;
        for (string word: words) {
            if (isSubsequence(word, S, char2pos)) 
                ans ++;
        }
        return ans;
        
    }

    bool isSubsequence(string s, string t, 
                       unordered_map<char, vector<int>>& char2pos) {
        int pre = -1;
        for (char ch: s) {
            auto it = upper_bound(char2pos[ch].begin(), char2pos[ch].end(), pre);
            if (it == char2pos[ch].end()) return false;
            pre = *it;
        }
        return true;
    }
};
// @lc code=end

