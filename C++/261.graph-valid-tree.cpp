/*
 * @lc app=leetcode id=261 lang=cpp
 *
 * [261] Graph Valid Tree
 *
 * Given n nodes labeled from 0 to n-1 and a list of undirected edges (each edge is a pair of nodes), write a function to check whether these edges make up a valid tree.
 * 
 * Example 1:
 * Input: n = 5, and edges = [[0,1], [0,2], [0,3], [1,4]]
 * Output: true
 * 
 * Example 2:
 * Input: n = 5, and edges = [[0,1], [1,2], [2,3], [1,3], [1,4]]
 * Output: false
 * Note: you can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0,1] is the same as [1,0] and thus will not appear together in edges.
 * 
 * 
 * 
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        vector<int> roots(n, -1);
        for (auto edge: edges) {
            int p1 = find(roots, edge.first);
            int p2 = find(roots, edge.second);
            if (p1 == p2) return false;
            roots[p1] = p2; 
        }
        return edges.size() == n -1;
    }
    int find(vector<int>& roots, int i) {
        while (roots[i] != -1) i = roots[i];
        return i;
    }
};
// @lc code=end

