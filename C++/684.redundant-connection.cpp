/*
 * @lc app=leetcode id=684 lang=cpp
 *
 * [684] Redundant Connection
 */
#include<vector>
using namespace std;


// @lc code=start
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> root(2000, -1);
        for (auto edge: edges) {
            int p1 = findRoot(root, edge[0]);
            int p2 = findRoot(root, edge[1]);
            if (p1 == p2) return edge;
            root[p1] = p2;
        }
        return {};
    }
    int findRoot(vector<int>& root, int i) {
        while (root[i] != -1) i = root[i];
        return i;
    }
};
// @lc code=end

