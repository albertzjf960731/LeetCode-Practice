/*
 * @lc app=leetcode id=1202 lang=cpp
 *
 * [1202] Smallest String With Swaps
 *
 * https://leetcode.com/problems/smallest-string-with-swaps/description/
 *
 * algorithms
 * Medium (57.62%)
 * Likes:    3212
 * Dislikes: 109
 * Total Accepted:    94.7K
 * Total Submissions: 164.4K
 * Testcase Example:  '"dcab"\n[[0,3],[1,2]]'
 *
 * You are given a string s, and an array of pairs of indices in the string
 * pairs where pairs[i] = [a, b] indicates 2 indices(0-indexed) of the string.
 * 
 * You can swap the characters at any pair of indices in the given pairs any
 * number of times.
 * 
 * Return the lexicographically smallest string that s can be changed to after
 * using the swaps.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "dcab", pairs = [[0,3],[1,2]]
 * Output: "bacd"
 * Explaination: 
 * Swap s[0] and s[3], s = "bcad"
 * Swap s[1] and s[2], s = "bacd"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "dcab", pairs = [[0,3],[1,2],[0,2]]
 * Output: "abcd"
 * Explaination: 
 * Swap s[0] and s[3], s = "bcad"
 * Swap s[0] and s[2], s = "acbd"
 * Swap s[1] and s[2], s = "abcd"
 * 
 * Example 3:
 * 
 * 
 * Input: s = "cba", pairs = [[0,1],[1,2]]
 * Output: "abc"
 * Explaination: 
 * Swap s[0] and s[1], s = "bca"
 * Swap s[1] and s[2], s = "bac"
 * Swap s[0] and s[1], s = "abc"
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 10^5
 * 0 <= pairs.length <= 10^5
 * 0 <= pairs[i][0], pairs[i][1] < s.length
 * s only contains lower case English letters.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        vector<int> root(n);
        for (int i=0; i<n; ++i) root[i] = i;
        
        for (auto& p: pairs) {
            int r1 = findRoot(p[0], root);
            int r2 = findRoot(p[1], root);
            if (r1 != r2) root[r1] = r2;
        }

        vector<vector<int>> groups(n);
        for (int i=0; i<n; ++i) {
            groups[findRoot(i, root)].push_back(i);
        }

        for (auto& g: groups) {
            if (g.size() == 0) continue;
            string tmp = "";
            for (int idx: g) tmp += s[idx];
            sort(tmp.begin(), tmp.end());

            for (int i=0; i<g.size(); ++i) s[g[i]] = tmp[i];
        }
        return s;
    }

    int findRoot(int i, vector<int>& root) {
        while (i != root[i]) {
            root[i] = root[root[i]];
            i = root[i];
        }
        return i;
    }
};
// @lc code=end

