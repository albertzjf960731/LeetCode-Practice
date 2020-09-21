/*
 * @lc app=leetcode id=453 lang=cpp
 *
 * [453] Minimum Moves to Equal Array Elements
 *
 * https://leetcode.com/problems/minimum-moves-to-equal-array-elements/description/
 *
 * algorithms
 * Easy (50.23%)
 * Likes:    592
 * Dislikes: 867
 * Total Accepted:    76.3K
 * Total Submissions: 151.8K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a non-empty integer array of size n, find the minimum number of moves
 * required to make all array elements equal, where a move is incrementing n -
 * 1 elements by 1.
 * 
 * Example:
 * 
 * Input:
 * [1,2,3]
 * 
 * Output:
 * 3
 * 
 * Explanation:
 * Only three moves are needed (remember each move increments two elements):
 * 
 * [1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]
 * 
 * 
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int min_num = INT_MAX;
        for (int num : nums) min_num = min(min_num, num);
        
        int ans = 0;
        for (int num : nums) ans += num - min_num;
        return ans;
    }
};
// @lc code=end

