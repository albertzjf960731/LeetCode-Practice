/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 *
 * https://leetcode.com/problems/palindrome-partitioning/description/
 *
 * algorithms
 * Medium (44.63%)
 * Likes:    1388
 * Dislikes: 54
 * Total Accepted:    201.4K
 * Total Submissions: 451.1K
 * Testcase Example:  '"aab"'
 *
 * Given a string s, partition s such that every substring of the partition is
 * a palindrome.
 * 
 * Return all possible palindrome partitioning of s.
 * 
 * Example:
 * 
 * 
 * Input: "aab"
 * Output:
 * [
 * ⁠ ["aa","b"],
 * ⁠ ["a","a","b"]
 * ]
 * 
 * 
 */
#include<vector>
#include<string>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        DFS(s, 0, path, res);
        return res;
    }
    void DFS(string& s, int idx, vector<string>& path, vector<vector<string>>& res) {
        if (idx==s.size()) {
            res.push_back(path);
            return;
        }

        for (int i=idx; i<s.size(); i++) {
            if (isPalindrome(s, idx, i)) {
                path.push_back(s.substr(idx, i-idx+1));
                DFS(s, i+1, path, res);
                path.pop_back();
            }
        }
    }

    bool isPalindrome(string& s, int l, int r) {
        while (l<r) {
            if (s[l++]!=s[r--])
                return false;
        }
        return true;
    }
};
// @lc code=end

