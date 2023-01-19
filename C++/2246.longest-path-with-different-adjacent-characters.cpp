/*
 * @lc app=leetcode id=2246 lang=cpp
 *
 * [2246] Longest Path With Different Adjacent Characters
 *
 * https://leetcode.com/problems/longest-path-with-different-adjacent-characters/description/
 *
 * algorithms
 * Hard (44.48%)
 * Likes:    1861
 * Dislikes: 48
 * Total Accepted:    52.4K
 * Total Submissions: 94.6K
 * Testcase Example:  '[-1,0,0,1,1,2]\n"abacbe"'
 *
 * You are given a tree (i.e. a connected, undirected graph that has no cycles)
 * rooted at node 0 consisting of n nodes numbered from 0 to n - 1. The tree is
 * represented by a 0-indexed array parent of size n, where parent[i] is the
 * parent of node i. Since node 0 is the root, parent[0] == -1.
 * 
 * You are also given a string s of length n, where s[i] is the character
 * assigned to node i.
 * 
 * Return the length of the longest path in the tree such that no pair of
 * adjacent nodes on the path have the same character assigned to them.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: parent = [-1,0,0,1,1,2], s = "abacbe"
 * Output: 3
 * Explanation: The longest path where each two adjacent nodes have different
 * characters in the tree is the path: 0 -> 1 -> 3. The length of this path is
 * 3, so 3 is returned.
 * It can be proven that there is no longer path that satisfies the
 * conditions. 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: parent = [-1,0,0,0], s = "aabc"
 * Output: 3
 * Explanation: The longest path where each two adjacent nodes have different
 * characters is the path: 2 -> 0 -> 3. The length of this path is 3, so 3 is
 * returned.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == parent.length == s.length
 * 1 <= n <= 10^5
 * 0 <= parent[i] <= n - 1 for all i >= 1
 * parent[0] == -1
 * parent represents a valid tree.
 * s consists of only lowercase English letters.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int longestPath(vector<int>& parent, string s) {
        int n = s.size();
        if (n == 1) return 1;

        vector<vector<int>> child(n, vector<int>());
        for (int i=1; i<n; ++i) child[parent[i]].push_back(i);

        int ans = 0;
        DFS(0, child, s, ans);
        return ans;
    }

    int DFS(int node, vector<vector<int>>& child, string& s, int& ans) {
        if (child[node].size() == 0) return 1;

        int len1 = 0, len2 = 0;
        for (int c: child[node]) {
            int tmp = DFS(c, child, s, ans);
            
            if (s[node] == s[c]) continue;
            if (tmp > len1) len2 = len1, len1 = tmp;
            else if (tmp > len2) len2 = tmp;
            
        }
        ans = max(ans, len1 + len2 + 1);
        return len1 + 1;
    }
};
// @lc code=end

