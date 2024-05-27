/*
 * @lc app=leetcode id=2101 lang=cpp
 *
 * [2101] Detonate the Maximum Bombs
 *
 * https://leetcode.com/problems/detonate-the-maximum-bombs/description/
 *
 * algorithms
 * Medium (42.00%)
 * Likes:    1915
 * Dislikes: 106
 * Total Accepted:    57.6K
 * Total Submissions: 122K
 * Testcase Example:  '[[2,1,3],[6,1,4]]'
 *
 * You are given a list of bombs. The range of a bomb is defined as the area
 * where its effect can be felt. This area is in the shape of a circle with the
 * center as the location of the bomb.
 * 
 * The bombs are represented by a 0-indexed 2D integer array bombs where
 * bombs[i] = [xi, yi, ri]. xi and yi denote the X-coordinate and Y-coordinate
 * of the location of the i^th bomb, whereas ri denotes the radius of its
 * range.
 * 
 * You may choose to detonate a single bomb. When a bomb is detonated, it will
 * detonate all bombs that lie in its range. These bombs will further detonate
 * the bombs that lie in their ranges.
 * 
 * Given the list of bombs, return the maximum number of bombs that can be
 * detonated if you are allowed to detonate only one bomb.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: bombs = [[2,1,3],[6,1,4]]
 * Output: 2
 * Explanation:
 * The above figure shows the positions and ranges of the 2 bombs.
 * If we detonate the left bomb, the right bomb will not be affected.
 * But if we detonate the right bomb, both bombs will be detonated.
 * So the maximum bombs that can be detonated is max(1, 2) = 2.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: bombs = [[1,1,5],[10,10,5]]
 * Output: 1
 * Explanation:
 * Detonating either bomb will not detonate the other bomb, so the maximum
 * number of bombs that can be detonated is 1.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: bombs = [[1,2,3],[2,3,1],[3,4,2],[4,5,3],[5,6,4]]
 * Output: 5
 * Explanation:
 * The best bomb to detonate is bomb 0 because:
 * - Bomb 0 detonates bombs 1 and 2. The red circle denotes the range of bomb
 * 0.
 * - Bomb 2 detonates bomb 3. The blue circle denotes the range of bomb 2.
 * - Bomb 3 detonates bomb 4. The green circle denotes the range of bomb 3.
 * Thus all 5 bombs are detonated.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= bombs.length <= 100
 * bombs[i].length == 3
 * 1 <= xi, yi, ri <= 10^5
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();

        vector<vector<int>> graph(n, vector<int>());
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                if (j == i) continue;
                if (check(bombs[i], bombs[j])) {
                    graph[i].push_back(j);
                }
            }
        }

        int ans = 0;
        for (int i=0; i<n; ++i) {
            queue<int> q;            
            vector<bool> visited(n, false);
            
            q.push(i);
            visited[i] = true;

            int cnt = 0;
            while (!q.empty()) {
                int cur = q.front(); q.pop();
                cnt += 1;
                for (int nei : graph[cur]) {
                    if (visited[nei]) continue;
                    q.push(nei);
                    visited[nei] = true;
                }
            }
            ans = max(ans, cnt);
        }
        return ans;
    }

    bool check(vector<int>& a, vector<int>& b) {
        long dis = (long)(a[0]-b[0]) * (a[0]-b[0]) + (long)(a[1]-b[1]) * (a[1]-b[1]);
        long range = (long)a[2] * a[2];
        return range >= dis; 
    }
};
// @lc code=end

