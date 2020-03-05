/*
 * @lc app=leetcode id=247 lang=cpp
 *
 * [248] Strobogrammatic Number III
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
 * Write a function to count the total strobogrammatic numbers that exist in the range of low <= num <= high.
 * 
 * Example:
 * 
 * Input: low = "50", high = "100"
 * Output: 3 
 * Explanation: 69, 88, and 96 are three strobogrammatic numbers.
 * Note:
 * Because the range might be a large number, the lowand high numbers are represented as string.
 * 
 */
#include<vector>
#include<string>
#include<iostream>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int strobogrammaticInRange(string low, string high) {
        int ans=0;
        for (int i=low.size(); i<=high.size(); ++i) {
            DFS(low, high, i, "", ans);
            DFS(low, high, i, "0", ans);
            DFS(low, high, i, "1", ans);
            DFS(low, high, i, "8", ans);
        }
        return ans;
    }
    void DFS(string& low, string& high, int len, string path, int& ans) {
        if (path.size()>len) return;

        if (path.size()==len) {
            if (len!=1 && path[0]=='0')
                return;
            // if ((len==low.size() && path.compare(low)<0) || (len==high.size() && path.compare(high)>0)) {
            // if ((len==low.size() && path.compare(low)<0) || (len==high.size() && path.compare(high)>0)) {
            if (len==low.size() && path<low || (len==high.size() && path>high)) {
                return;
            }
            ++ans;
        }
        DFS(low, high, len, "0"+path+"0", ans);
        DFS(low, high, len, "1"+path+"1", ans);
        DFS(low, high, len, "6"+path+"9", ans);
        DFS(low, high, len, "8"+path+"8", ans);
        DFS(low, high, len, "9"+path+"6", ans);
    }
};

int main() {
    Solution sol;
    string low = "50", high = "100";
    cout << sol.strobogrammaticInRange(low, high) << endl;
}