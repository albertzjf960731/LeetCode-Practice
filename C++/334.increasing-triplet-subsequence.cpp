/*
 * @lc app=leetcode id=334 lang=cpp
 *
 * [334] Increasing Triplet Subsequence
 *
 * https://leetcode.com/problems/increasing-triplet-subsequence/description/
 *
 * algorithms
 * Medium (39.80%)
 * Likes:    1217
 * Dislikes: 112
 * Total Accepted:    122.2K
 * Total Submissions: 307K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * Given an unsorted array return whether an increasing subsequence of length 3
 * exists or not in the array.
 * 
 * Formally the function should:
 * 
 * Return true if there exists i, j, k 
 * such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return
 * false.
 * 
 * Note: Your algorithm should run in O(n) time complexity and O(1) space
 * complexity.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,3,4,5]
 * Output: true
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [5,4,3,2,1]
 * Output: false
 * 
 * 
 * 
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        // int cur_min=INT_MAX, cur_mid=INT_MAX;

        // // 3, 1, 4, 5
        // // 2, 1, 5, 8, 7
        // // 8, 7, 1, 2, 3
        // // 3, 4 ,5 , 1
        // // 当前最小
        // for(int num : nums){
        //     if(num<=cur_min)
        //         cur_min = num;
        //     else if(num <= cur_mid)
        //         cur_mid = num;
        //     else
        //         return true;
        // }
        // return false;

        if (nums.size() < 3) return false;
        vector<int> cur_min(nums.size(), nums[0]), cur_max(nums.size(), nums.back());
        for (int i=1; i<nums.size(); ++i) 
            cur_min[i] = min(cur_min[i-1], nums[i]);
        for (int i=nums.size()-2; i>=0; --i) 
            cur_max[i] = max(cur_max[i+1], nums[i]);
        for (int i=0; i<nums.size(); ++i) {
            if (nums[i]>cur_min[i] && nums[i]<cur_max[i]) 
                return true;
        }
        return false;
    }
};
// @lc code=end

