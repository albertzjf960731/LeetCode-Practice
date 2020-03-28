/*
 * @lc app=leetcode id=787 lang=cpp
 *
 * [787] Cheapest Flights Within K Stops
 *
 * https://leetcode.com/problems/cheapest-flights-within-k-stops/description/
 *
 * algorithms
 * Medium (36.94%)
 * Likes:    1140
 * Dislikes: 41
 * Total Accepted:    63K
 * Total Submissions: 170.3K
 * Testcase Example:  '3\n[[0,1,100],[1,2,100],[0,2,500]]\n0\n2\n1'
 *
 * There are n cities connected by m flights. Each fight starts from city u and
 * arrives at v with a price w.
 * 
 * Now given all the cities and flights, together with starting city src and
 * the destination dst, your task is to find the cheapest price from src to dst
 * with up to k stops. If there is no such route, output -1.
 * 
 * 
 * Example 1:
 * Input: 
 * n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
 * src = 0, dst = 2, k = 1
 * Output: 200
 * Explanation: 
 * The graph looks like this:
 * 
 * 
 * The cheapest price from city 0 to city 2 with at most 1 stop costs 200, as
 * marked red in the picture.
 * 
 * 
 * Example 2:
 * Input: 
 * n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
 * src = 0, dst = 2, k = 0
 * Output: 500
 * Explanation: 
 * The graph looks like this:
 * 
 * 
 * The cheapest price from city 0 to city 2 with at most 0 stop costs 500, as
 * marked blue in the picture.
 * 
 * Note:
 * 
 * 
 * The number of nodes n will be in range [1, 100], with nodes labeled from 0
 * to n - 1.
 * The size of flights will be in range [0, n * (n - 1) / 2].
 * The format of each flight will be (src, dst, price).
 * The price of each flight will be in the range [1, 10000].
 * k is in the range of [0, n - 1].
 * There will not be any duplicated flights or self cycles.
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
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<int> dists(n, 1e8);
        dists[src] = 0;

        vector<int> temp;
        for (int i=0; i<=K; i++) {
            temp = dists;
            for (vector<int> edge: flights) {
                int s=edge[0], e=edge[1], w=edge[2];
                if(dists[s]!=INT_MAX & temp[e]>dists[s]+w) {
                    temp[e] = dists[s] + w;
                }
            }
            dists = temp;
        }
        int ans = dists[dst];
        return ans==1e8? -1: ans;


        vector<vector<pair<int,int>>> adj(n, vector<pair<int,int>>());
        for (vector<int> edge : flights)
            adj[edge[0]].push_back(make_pair(edge[1], edge[2]));  
        
        int ans = INT_MAX;
        queue<pair<int, int>> q;
        q.push({src, 0});
        
        int stops = 0; 
        while(!q.empty()){
            stops++;

            int q_size = q.size();
            for(int i=0; i<q_size; ++i){
                auto curr = q.front();
                q.pop();
                
                if(curr.first==dst) 
                    ans = min(ans, curr.second);   
                for(auto node:  adj[curr.first]){
                    if(curr.second + node.second < ans) {
                        q.push({node.first, curr.second+node.second});
                    }
                 }  
            }
            if(stops==K+2) break;
        }  
        return ans == INT_MAX ? - 1 : ans;
    }
};

class Solution {
typedef tuple<int,int,int> ti;

public:
    // Bellman Ford
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto f: flights)   
            adj[f[0]].push_back({f[1], f[2]});
        
        priority_queue<ti, vector<ti>, greater<ti>> pq;
        pq.push({0, src, K+1});
        
        while(!pq.empty()){
            auto [cost, u, stops] = pq.top();
            pq.pop();
            
            if(u==dst)  return cost;
            if(stops==0)  break;
            for(auto to: adj[u]){
                auto [v, w] = to;
                pq.push({cost+w, v, stops-1});
            }
        }
        return -1;
    }
        
};
// @lc code=end

