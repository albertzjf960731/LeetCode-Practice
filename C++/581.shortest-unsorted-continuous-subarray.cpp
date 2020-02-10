/*
 * @lc app=leetcode id=581 lang=cpp
 *
 * [581] Shortest Unsorted Continuous Subarray
 *
 * https://leetcode.com/problems/shortest-unsorted-continuous-subarray/description/
 *
 * algorithms
 * Easy (30.68%)
 * Likes:    2060
 * Dislikes: 106
 * Total Accepted:    97.5K
 * Total Submissions: 318K
 * Testcase Example:  '[2,6,4,8,10,9,15]'
 *
 * Given an integer array, you need to find one continuous subarray that if you
 * only sort this subarray in ascending order, then the whole array will be
 * sorted in ascending order, too.  
 * 
 * You need to find the shortest such subarray and output its length.
 * 
 * Example 1:
 * 
 * Input: [2, 6, 4, 8, 10, 9, 15]
 * Output: 5
 * Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make
 * the whole array sorted in ascending order.
 * 
 * 
 * 
 * Note:
 * 
 * Then length of the input array is in range [1, 10,000].
 * The input array may contain duplicates, so ascending order here means . 
 * 
 * 
 */
#include<vector>
using namespace std; 

// @lc code=start
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        // vector<int> sorted = nums;
        // sort(sorted.begin(), sorted.end());

        // int left=nums.size(), right=0;
        // bool flag = false;
        // for (int i=0; i<nums.size(); ++i){
        //     if (sorted[i]!=nums[i]){
        //         if (not flag){
        //             left = i;
        //             flag = true;
        //         }
        //         else
        //             right = max(right, i);
        //     }
        // }
        // if (flag)
        //     return right-left+1;
        // else
        //     return 0;   
        int n = nums.size();
        int left=-1, right=-2;
        int cur_min=nums[n-1], cur_max=nums[0];

        for (int i=1, j=n-2; i<n; i++, j--) {
            cur_max = max(cur_max, nums[i]);
            cur_min = min(cur_min, nums[j]);

            if (nums[i]<cur_max) 
                right = i;
            if (nums[j]>cur_min) 
                left = j; 
        }
        return right-left+1; 
    }
};
// @lc code=end

