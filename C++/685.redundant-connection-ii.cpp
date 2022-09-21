/*
 * @lc app=leetcode id=685 lang=cpp
 *
 * [685] Redundant Connection II
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> root(n + 1, 0), first, second;
        for (auto& edge : edges) {
            if (root[edge[1]] == 0) {
                root[edge[1]] = edge[0];
            } else {
                first = {root[edge[1]], edge[1]};
                second = edge;
                edge[1] = 0;
            }
        }
        for (int i = 0; i <= n; ++i) root[i] = -1;
        for (auto& edge : edges) {
            if (edge[1] == 0) continue;
            int x = findRoot(root, edge[0]), y = findRoot(root, edge[1]);
            if (x == y) return first.empty() ? edge : first;
            root[x] = y;
        }
        return second;
    }
    int findRoot(vector<int>& root, int i) {
        while (-1 != root[i]) i = root[i];
        return i;
    }
};
// @lc code=end

