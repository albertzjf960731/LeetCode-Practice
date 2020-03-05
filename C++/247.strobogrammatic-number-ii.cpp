/*
 * @lc app=leetcode id=247 lang=cpp
 *
 * [247] Strobogrammatic Number II
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
 * A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).
 * 
 * Find all strobogrammatic numbers that are of length = n.
 * 
 * For example,
 * Given n = 2, return ["11","69","88","96"].
 * 
 * Hint:
 * Try to use recursion and notice that it should recurse with n - 2 instead of n - 1.
 * 
 */
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        return DFS(n, n);
    }
    vector<string> DFS(int m, int n) {
        if (m==0) return {""};
        if (m==1) return {"0", "1", "8"};
        vector<string> tmp = DFS(m-2, n), res;
        for (auto a : tmp) {
            if (m != n) 
                res.push_back("0" + a + "0");
            res.push_back("1" + a + "1");
            res.push_back("6" + a + "9");
            res.push_back("8" + a + "8");
            res.push_back("9" + a + "6");
        }
        return res;
    }
};