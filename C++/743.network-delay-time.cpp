/*
 * @lc app=leetcode id=743 lang=cpp
 *
 * [743] Network Delay Time
 *
 * https://leetcode.com/problems/network-delay-time/description/
 *
 * algorithms
 * Medium (44.95%)
 * Likes:    938
 * Dislikes: 194
 * Total Accepted:    60.6K
 * Total Submissions: 134.7K
 * Testcase Example:  '[[2,1,1],[2,3,1],[3,4,1]]\n4\n2'
 *
 * There are N network nodes, labelled 1 to N.
 * 
 * Given times, a list of travel times as directed edges times[i] = (u, v, w),
 * where u is the source node, v is the target node, and w is the time it takes
 * for a signal to travel from source to target.
 * 
 * Now, we send a signal from a certain node K. How long will it take for all
 * nodes to receive the signal? If it is impossible, return -1.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: times = [[2,1,1],[2,3,1],[3,4,1]], N = 4, K = 2
 * Output: 2
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * N will be in the range [1, 100].
 * K will be in the range [1, N].
 * The length of times will be in the range [1, 6000].
 * All edges times[i] = (u, v, w) will have 1 <= u, v <= N and 0 <= w <= 100.
 * 
 * 
 */
#include<vector>
#include<queue>
using namespace std; 

// @lc code=start
class Solution {
public:
    // Bellman Ford
    // int networkDelayTime(vector<vector<int>>& times, int N, int K) {
    //     vector<int> dists(N+1, INT_MAX);
    //     dists[K] = 0;

    //     for (int i=0; i<N; i++) {
    //         for (vector<int> edge: times) {
    //             int s=edge[0], e=edge[1], w=edge[2];
    //             if (dists[s]!=INT_MAX && dists[e]>dists[s]+w) {
    //                 dists[e] = dists[s] + w;
    //             }
    //         }
    //     }
        
    //     int ans = 0;
    //     for (int i=1; i<=N; i++) {
    //         ans = max(ans, dists[i]);
    //     }
    //     return ans==INT_MAX? -1: ans;
    // }

    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<vector<pair<int, int>>> adj[N+1];
        for (vector<int> edge: times) {
            adj[edge[0]].push_back(make_pair(edge[1], edge[2]));
        }

        vector<int> dists(N+1, INT_MAX);
        dists[K] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push(make_pair(0, K));

        int dist, node, v, w;
        vector<bool> visited(N+1, false);
        while(!pq.empty()) {
            pair<int, int> item = pq.top();
            dist = item.first, node = item.second;
            pq.pop();

            if (visited[node]) continue;
            for (pair<int, int> item: adj[node]) {
                v = item.first, w = item.second;
                if(dists[v] > dists[node] + w) {
                    dists[v] = dists[node] + w;
                    pq.push(make_pair(dists[v], v));
                }
            }
            visited[node] = true;

            // if(dist < dists[node]) {
            //     dists[node] = dist;
            //     for (pair<int, int> item: adj[node]) {
            //         v = item.first, w = item.second;
            //         pq.push(make_pair(dists[node]+w, v));
            //     }
            // }
        }
        int ans = *max_element(dists.begin()+1, dists.end());
        return ans==INT_MAX? -1: ans;
    }
};
// @lc code=end

