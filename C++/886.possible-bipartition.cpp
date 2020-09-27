/*
 * @lc app=leetcode id=886 lang=cpp
 *
 * [886] Possible Bipartition
 *
 * https://leetcode.com/problems/possible-bipartition/description/
 *
 * algorithms
 * Medium (44.26%)
 * Likes:    1047
 * Dislikes: 29
 * Total Accepted:    60.6K
 * Total Submissions: 136.7K
 * Testcase Example:  '4\n[[1,2],[1,3],[2,4]]'
 *
 * Given a set of N people (numbered 1, 2, ..., N), we would like to split
 * everyone into two groups of any size.
 * 
 * Each person may dislike some other people, and they should not go into the
 * same group. 
 * 
 * Formally, if dislikes[i] = [a, b], it means it is not allowed to put the
 * people numbered a and b into the same group.
 * 
 * Return true if and only if it is possible to split everyone into two groups
 * in this way.
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: N = 4, dislikes = [[1,2],[1,3],[2,4]]
 * Output: true
 * Explanation: group1 [1,4], group2 [2,3]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: N = 3, dislikes = [[1,2],[1,3],[2,3]]
 * Output: false
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: N = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
 * Output: false
 * 
 * 
 * 
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= N <= 2000
 * 0 <= dislikes.length <= 10000
 * dislikes[i].length == 2
 * 1 <= dislikes[i][j] <= N
 * dislikes[i][0] < dislikes[i][1]
 * There does not exist i != j for which dislikes[i] == dislikes[j].
 * 
 */
#include<vector>
#include<queue>
using namespace std;

// @lc code=start
class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(N + 1);
        for (auto dislike : dislikes) {
            graph[dislike[0]].push_back(dislike[1]);
            graph[dislike[1]].push_back(dislike[0]);
        }
        
        vector<int> colors(N + 1);
        for (int i=1; i<=N; ++i) {
            if (colors[i] != 0) continue;
            colors[i] = 1;
            queue<int> q{{i}};
            
            while (!q.empty()) {
                int node = q.front(); 
                q.pop();
                for (int nei : graph[node]) {
                    if (colors[nei] == colors[node]) 
                        return false;
                    if (colors[nei] == 0) {
                        colors[nei] = -colors[node];
                        q.push(nei);
                    }
                }
            }
        }
        return true;
    }
};
// @lc code=end

