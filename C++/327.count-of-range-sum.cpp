/*
 * @lc app=leetcode id=327 lang=cpp
 *
 * [327] Count of Range Sum
 *
 * https://leetcode.com/problems/count-of-range-sum/description/
 *
 * algorithms
 * Hard (34.27%)
 * Likes:    569
 * Dislikes: 73
 * Total Accepted:    38.1K
 * Total Submissions: 111.2K
 * Testcase Example:  '[-2,5,-1]\n-2\n2'
 *
 * Given an integer array nums, return the number of range sums that lie in
 * [lower, upper] inclusive.
 * Range sum S(i, j) is defined as the sum of the elements in nums between
 * indices i and j (i ≤ j), inclusive.
 * 
 * Note:
 * A naive algorithm of O(n^2) is trivial. You MUST do better than that.
 * 
 * Example:
 * 
 * 
 * Input: nums = [-2,5,-1], lower = -2, upper = 2,
 * Output: 3 
 * Explanation: The three ranges are : [0,0], [2,2], [0,2] and their respective
 * sums are: -2, -1, 2.
 * 
 */
#include<vector>
#include<map>
#include<set>
using namespace std;

// @lc code=start
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        // int ans = 0;

        // map<long, int> hash_map{{0, 1}};
        // long sum = 0;
        // for (int num: nums) {
        //     sum += num;

        //     auto it = hash_map.lower_bound(sum-upper);
        //     while (it!=hash_map.end() && sum-it->first>=lower) {
        //         ans += it->second;
        //         it++;
        //     }
        //     hash_map[sum] ++;
        // }
        // return ans;

        int ans = 0;

        multiset<long> sums{0};
        long cur_sum = 0;
        for (int num: nums) {
            cur_sum += num;
            ans += distance(sums.lower_bound(cur_sum-upper), sums.upper_bound(cur_sum-lower));
            sums.insert(cur_sum);
        }
        return ans;
    }
};
// @lc code=end

