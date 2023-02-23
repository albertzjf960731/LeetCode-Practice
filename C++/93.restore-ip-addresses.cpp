/*
 * @lc app=leetcode id=93 lang=cpp
 *
 * [93] Restore IP Addresses
 *
 * https://leetcode.com/problems/restore-ip-addresses/description/
 *
 * algorithms
 * Medium (33.03%)
 * Likes:    892
 * Dislikes: 386
 * Total Accepted:    162.4K
 * Total Submissions: 490K
 * Testcase Example:  '"25525511135"'
 *
 * Given a string containing only digits, restore it by returning all possible
 * valid IP address combinations.
 * 
 * Example:
 * 
 * 
 * Input: "25525511135"
 * Output: ["255.255.11.135", "255.255.111.35"]
 * 
 * 
 */
#include<string>
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        vector<int> path;
        DFS(s, 0, path, ans);
        return ans;
    }

    void DFS(string s, int idx, vector<int>& path, vector<string>& ans) {
        if (path.size()==4) {
            if (idx < s.size()) return;

            string tmp = "";
            for (int num: path) tmp = tmp + to_string(num) + ".";
            tmp.pop_back();
            ans.push_back(tmp);
            return;
        }

        int num = 0;
        for (int i=idx; i<s.size(); ++i) {
            num = num * 10 + (s[i]-'0');
            if (num > 255) break;

            path.push_back(num);
            DFS(s, i+1, path, ans);
            path.pop_back();
            if (num == 0) break;
        }
        return;
    }
};
// @lc code=end

