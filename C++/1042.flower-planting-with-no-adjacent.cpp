/*
 * @lc app=leetcode id=1042 lang=cpp
 *
 * [1042] Flower Planting With No Adjacent
 *
 * https://leetcode.com/problems/flower-planting-with-no-adjacent/description/
 *
 * algorithms
 * Easy (48.30%)
 * Likes:    204
 * Dislikes: 247
 * Total Accepted:    17.6K
 * Total Submissions: 36.4K
 * Testcase Example:  '3\n[[1,2],[2,3],[3,1]]'
 *
 * You have N gardens, labelled 1 to N.  In each garden, you want to plant one
 * of 4 types of flowers.
 * 
 * paths[i] = [x, y] describes the existence of a bidirectional path from
 * garden x to garden y.
 * 
 * Also, there is no garden that has more than 3 paths coming into or leaving
 * it.
 * 
 * Your task is to choose a flower type for each garden such that, for any two
 * gardens connected by a path, they have different types of flowers.
 * 
 * Return any such a choice as an array answer, where answer[i] is the type of
 * flower planted in the (i+1)-th garden.  The flower types are denoted 1, 2,
 * 3, or 4.  It is guaranteed an answer exists.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: N = 3, paths = [[1,2],[2,3],[3,1]]
 * Output: [1,2,3]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: N = 4, paths = [[1,2],[3,4]]
 * Output: [1,2,1,2]
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: N = 4, paths = [[1,2],[2,3],[3,4],[4,1],[1,3],[2,4]]
 * Output: [1,2,3,4]
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= N <= 10000
 * 0 <= paths.size <= 20000
 * No garden has 4 or more paths coming into or leaving it.
 * It is guaranteed an answer exists.
 * 
 * 
 * 
 * 
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        vector<vector<int>> adjs(N, vector<int>());
        for (auto path: paths) {
            adjs[path[0]-1].push_back(path[1]-1);
            adjs[path[1]-1].push_back(path[0]-1);
        }
        
        vector<int> ans(N, 0);
        for (int i=0; i<N; i++) {
            
            vector<int> neighs(5, 0);
            for (int j: adjs[i]) neighs[ans[j]] = 1;

            int flower = 1;
            while (neighs[flower])
                flower ++;
            ans[i] = flower;
        }
        return ans; 


        vector<vector<int>> graph(n, vector<int>());
        for (vector<int>& p: paths) {
            graph[p[0]-1].push_back(p[1]-1);
            graph[p[1]-1].push_back(p[0]-1);
        }

        vector<int> path(n, 0);
        DFS(graph, path, 0);
        return path;
    }

    bool DFS(vector<vector<int>>& graph, vector<int>& path, int i) {
        if (i == path.size()) {
            return true;
        }

        for (int c=1; c<=4; ++c) {
            if (check(graph, path, i, c)) {
                path[i] = c;
                if (DFS(graph, path, i+1)) return true;;
            }
        }
        return false;
    }

    bool check(vector<vector<int>>& graph, vector<int>& path, int i, int c) {
        for (int j: graph[i]) {
            if (path[j] == 0) continue;
            if (path[j] == c) return false;
        }
        return true;
    }
};
// @lc code=end

