/*
 * @lc app=leetcode id=947 lang=cpp
 *
 * [947] Most Stones Removed with Same Row or Column
 *
 * https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/description/
 *
 * algorithms
 * Medium (55.26%)
 * Likes:    1069
 * Dislikes: 386
 * Total Accepted:    54.8K
 * Total Submissions: 99.2K
 * Testcase Example:  '[[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]'
 *
 * On a 2D plane, we place stones at some integer coordinate points.  Each
 * coordinate point may have at most one stone.
 * 
 * Now, a move consists of removing a stone that shares a column or row with
 * another stone on the grid.
 * 
 * What is the largest possible number of moves we can make?
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
 * Output: 5
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: stones = [[0,0],[0,2],[1,1],[2,0],[2,2]]
 * Output: 3
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: stones = [[0,0]]
 * Output: 0
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= stones.length <= 1000
 * 0 <= stones[i][j] < 10000
 * 
 * 
 * 
 * 
 * 
 */
#include<unordered_map>
#include<unordered_set>
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        unordered_map<int, vector<int>> rowMap, colMap;
        for (auto stone : stones) {
            rowMap[stone[0]].push_back(stone[1]);
            colMap[stone[1]].push_back(stone[0]);
        }
        
        int ans = 0;
        unordered_set<int> rowVisited;
        for (auto row2col : rowMap) {
            ans += max(0, DFS(rowMap, colMap, row2col.first, rowVisited) - 1);
        }
        return ans;


        int n = stones.size();
        
        vector<int> root(n, -1);
        // for (int i=0; i<n; ++i) root[i] = i;
        
        int ans = 0;
        for (int i=0; i<n; ++i) {
            for (int j = i+1; j<n; ++j) {
                if (stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1]) {
                    int p1 = findRoot(root, i);
                    int p2 = findRoot(root, j);
                    if (p1 != p2) {
                        root[p1] =  p2;
                        ans += 1;
                    }
                }
            }
        }
        return ans;
    }
    
    int findRoot(vector<int>& root, int i) {
        while (-1 != root[i]) i = root[i];
        return i;
    }
    
    int DFS(unordered_map<int, vector<int>>& rowMap, 
            unordered_map<int, vector<int>>& colMap, 
            int row, unordered_set<int>& rowVisited) {
        if (rowVisited.count(row)) return 0;
         
        rowVisited.insert(row);
        int ans = rowMap[row].size();
        
        for (int c : rowMap[row]) {
            for (int r : colMap[c]) {
                ans += DFS(rowMap, colMap, r, rowVisited);
            }
        }
        return ans;
    }
};
// @lc code=end

