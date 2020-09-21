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
    // O(VE)
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<int> dists(N+1, INT_MAX);
        dists[K] = 0;

        for (int i=0; i<N; i++) {
            for (vector<int> edge: times) {
                int s=edge[0], e=edge[1], w=edge[2];
                if (dists[s]!=INT_MAX && dists[e]>dists[s]+w) {
                    dists[e] = dists[s] + w;
                }
            }
        }

        // for (vector<int> edge: times) {
        //     int s=edge[0], e=edge[1], w=edge[2]; 
        //     // 松弛完后还能再松弛即代表有负环
        //     if (dists[s]!=INT_MAX && dists[e]>dists[s]+w) 
        //         return true;
        // }
        // return false;

        
        int ans = 0;
        for (int i=1; i<=N; i++) {
            ans = max(ans, dists[i]);
        }
        return ans==INT_MAX? -1: ans;
    }

    // Dijkstra 
    // O(V2)
    // 权重必须为正
    // int networkDelayTime(vector<vector<int>>& times, int N, int K) {

    //     vector<vector<int>> edges(101, vector<int>(101, -1));
    //     for (auto edge : times) edges[edge[0]][edge[1]] = edge[2];

    //     queue<int> q;
    //     q.push(K);
        
    //     vector<int> dist(N+1, INT_MAX);
    //     dist[K] = 0;
        
    //     while (!q.empty()) {
    //         unordered_set<int> visited;
    //         int q_size = q.size();
    //         while (q_size--) {
    //             int u = q.front(); 
    //             q.pop();
    //             for (int v=1; v<=100; ++v) {
    //                 if (edges[u][v] != -1 && dist[u]+edges[u][v] < dist[v]) {
    //                     if (!visited.count(v)) {
    //                         visited.insert(v);
    //                         q.push(v);
    //                     }
    //                     dist[v] = dist[u] + edges[u][v];
    //                 }
    //             }
    //         }
    //     }
        
    //     int ans = 0;
    //     for (int i=1; i<=N; ++i) {
    //         ans = max(ans, dist[i]);
    //     }
    //     return ans == INT_MAX ? -1 : ans;
    
    // }
    // int networkDelayTime(vector<vector<int>>& times, int N, int K) {
    //     vector<pair<int, int>> adj[N+1];
    //     for (vector<int> edge: times) {
    //         adj[edge[0]].push_back(make_pair(edge[1], edge[2]));
    //     }

    //     vector<int> dists(N+1, INT_MAX);
    //     dists[K] = 0;

    //     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    //     pq.push(make_pair(0, K));

    //     int dist, node, v, w;
    //     vector<bool> visited(N+1, false);
    //     while(!pq.empty()) {
    //         pair<int, int> item = pq.top();
    //         dist = item.first, node = item.second;
    //         pq.pop();

    //         if (visited[node]) continue;
    //         for (pair<int, int> item: adj[node]) {
    //             v = item.first, w = item.second;
    //             if(dists[v] > dists[node] + w) {
    //                 dists[v] = dists[node] + w;
    //                 pq.push(make_pair(dists[v], v));
    //             }
    //         }
    //         visited[node] = true;

    //         // if(dist < dists[node]) {
    //         //     dists[node] = dist;
    //         //     for (pair<int, int> item: adj[node]) {
    //         //         v = item.first, w = item.second;
    //         //         pq.push(make_pair(dists[node]+w, v));
    //         //     }
    //         // }
    //     }
    //     int ans = *max_element(dists.begin()+1, dists.end());
    //     return ans==INT_MAX? -1: ans;
    // }

    // Floyd
    // O(V3)
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {

        vector<vector<long>> dp(N+1, vector<long>(N+1, INT_MAX));
        for (int i=1; i<=N; i++) dp[i][i] = 0;
        for (auto edge: times) dp[edge[0]][edge[1]] = edge[2];

        for (int k=1; k<=N; k++){
            for (int i=1; i<=N; i++){
                for (int j=1; j<=N; j++){
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                }
            }
        }
        
        long ans = 0;
        for (int i=1; i<=N; i++) ans = max(ans, dp[K][i]);
        return ans==INT_MAX? -1: ans;
    }
};
// @lc code=end

