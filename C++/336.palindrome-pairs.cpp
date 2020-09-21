/*
 * @lc app=leetcode id=336 lang=cpp
 *
 * [336] Palindrome Pairs
 *
 * https://leetcode.com/problems/palindrome-pairs/description/
 *
 * algorithms
 * Hard (32.48%)
 * Likes:    1089
 * Dislikes: 141
 * Total Accepted:    88.2K
 * Total Submissions: 270.4K
 * Testcase Example:  '["abcd","dcba","lls","s","sssll"]'
 *
 * Given a list of unique words, find all pairs of distinct indices (i, j) in
 * the given list, so that the concatenation of the two words, i.e. words[i] +
 * words[j] is a palindrome.
 * 
 * Example 1:
 * 
 * 
 * 
 * Input: ["abcd","dcba","lls","s","sssll"]
 * Output: [[0,1],[1,0],[3,2],[2,4]] 
 * Explanation: The palindromes are
 * ["dcbaabcd","abcddcba","slls","llssssll"]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ["bat","tab","cat"]
 * Output: [[0,1],[1,0]] 
 * Explanation: The palindromes are ["battab","tabbat"]
 * 
 * 
 * 
 * 
 */
#include<vector>
#include<string>
#include<unordered_map>
#include<iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    // vector<vector<int>> palindromePairs(vector<string>& words) {
    //     vector<vector<int>> res;

    //     for (int i=0; i<words.size()-1; ++i) {
    //         for (int j=i+1; j<words.size(); ++j){
    //             if(isPalindrome(words[i], words[j]))
    //                 res.push_back({i, j});
    //             if(isPalindrome(words[j], words[i]))
    //                 res.push_back({j, i});
    //         }
    //     }
    //     return res;
    // }

    // bool isPalindrome(string& s1, string& s2) {
    //     string s=s1+s2, t=s1+s2;
    //     reverse(s.begin(), s.end());
    //     return s==t;
    //     while (l<r) {
    //         if (s[l++]!=s[r--])
    //             return false;
    //     }
    //     return true;
    // }

    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> hash_map;
        vector<vector<int>> res;

        for(int i=0; i<words.size(); ++i) {
            string str = words[i];
            reverse(str.begin(), str.end());
            hash_map[str] = i;
        }

        if (hash_map.count("")) {
            for (int i=0; i<words.size(); ++i){
                if (words[i]!="" && isPalindrome(words[i]))
                    res.push_back({hash_map[""], i});
            }
        }
        for (int i=0; i<words.size(); ++i) {
            for (int j=0; j<words[i].size(); ++j) {
                string left = words[i].substr(0, j);
                string right = words[i].substr(j);
                
                if(hash_map.count(left) && hash_map[left]!=i && isPalindrome(right))
                    res.push_back({i, hash_map[left]});
                if(hash_map.count(right) && hash_map[right]!=i && isPalindrome(left)) 
                    res.push_back({hash_map[right], i});
            }
        }
        return res;
    }

private:
    bool isPalindrome(string str) {
        int i=0, j=str.size()-1;
        while (i<j) {
            if (str[i++]!=str[j--])
                return false;
        }
        return true;
    }
};
// @lc code=end


int main() {
    Solution sol;
    vector<string> words{"a",""};
    // vector<string> words{"abcd","dcba","lls","s","sssll"};
    vector<vector<int>> res = sol.palindromePairs(words);
    for (int i=0; i<res.size(); ++i){
        for (int j=0; j<res[i].size(); ++j)
            cout << res[i][j] << " ";
        cout << endl;
    }
    return 0;
}