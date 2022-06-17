/*
 * @lc app=leetcode id=945 lang=cpp
 *
 * [945] Minimum Increment to Make Array Unique
 *
 * https://leetcode.com/problems/minimum-increment-to-make-array-unique/description/
 *
 * algorithms
 * Medium (46.46%)
 * Likes:    518
 * Dislikes: 26
 * Total Accepted:    30.1K
 * Total Submissions: 64.6K
 * Testcase Example:  '[1,2,2]'
 *
 * Given an array of integers A, a move consists of choosing any A[i], and
 * incrementing it by 1.
 * 
 * Return the least number of moves to make every value in A unique.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,2]
 * Output: 1
 * Explanation:  After 1 move, the array could be [1, 2, 3].
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [3,2,1,2,1,7]
 * Output: 6
 * Explanation:  After 6 moves, the array could be [3, 4, 1, 2, 5, 7].
 * It can be shown with 5 or less moves that it is impossible for the array to
 * have all unique values.
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 0 <= A.length <= 40000
 * 0 <= A[i] < 40000
 * 
 * 
 * 
 * 
 * 
 */

#include<vector>
#include<unordered_map>
using namespace std;

// @lc code=start
class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {

        int res = 0, need = 0;
        sort(nums.begin(), nums.end());
        for (int num : nums) {
        	res += max(need - num, 0);
        	need = max(num, need) + 1;
        }
        return res;


        // int res = 0, need = 0;
        // unordered_map<int, int> cnts;
        // for (int num : nums) ++cnts[num];
        // for (auto &cnt : cnts) {
        // 	res += cnt.second * max(need - cnt.first, 0) + cnt.second * (cnt.second - 1) / 2;
        // 	need = max(need, cnt.first) + cnt.second;
        // }
        // return res;

    }
};
// @lc code=end

