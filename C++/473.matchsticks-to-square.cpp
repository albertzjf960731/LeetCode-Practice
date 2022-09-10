/*
 * @lc app=leetcode id=473 lang=cpp
 *
 * [473] Matchsticks to Square
 *
 * https://leetcode.com/problems/matchsticks-to-square/description/
 *
 * algorithms
 * Medium (40.67%)
 * Likes:    3180
 * Dislikes: 250
 * Total Accepted:    129.5K
 * Total Submissions: 318.7K
 * Testcase Example:  '[1,1,2,2,2]'
 *
 * You are given an integer array matchsticks where matchsticks[i] is the
 * length of the i^th matchstick. You want to use all the matchsticks to make
 * one square. You should not break any stick, but you can link them up, and
 * each matchstick must be used exactly one time.
 * 
 * Return true if you can make this square and false otherwise.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: matchsticks = [1,1,2,2,2]
 * Output: true
 * Explanation: You can form a square with length 2, one side of the square
 * came two sticks with length 1.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: matchsticks = [3,3,3,3,4]
 * Output: false
 * Explanation: You cannot find a way to form a square with all the
 * matchsticks.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= matchsticks.length <= 15
 * 1 <= matchsticks[i] <= 10^8
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 4 != 0) return false;
        int len = sum / 4;
        
        vector<bool> visited(nums.size(), false);
        return DFS(nums, visited, 0, len, 4, 0);
    }
    
    bool DFS(vector<int>& nums, vector<bool>& visited, int start, int target, int k, int path) {
        if (k==1) return true;
        if (path > target) return false;
        if (path == target) return DFS(nums, visited, 0, target, k-1, 0);
        
        for (int i=start; i<nums.size(); ++i) {
            if (visited[i]) continue;
            
            visited[i] = true;
            if (DFS(nums, visited, i+1, target, k, path+nums[i]))
                return true;
            visited[i] = false;
        }
        return false;
    }
};
// @lc code=end

