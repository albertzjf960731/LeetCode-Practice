/*
 * @lc app=leetcode id=1608 lang=cpp
 *
 * [1608] Special Array With X Elements Greater Than or Equal X
 *
 * https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/description/
 *
 * algorithms
 * Easy (60.30%)
 * Likes:    1039
 * Dislikes: 166
 * Total Accepted:    51.1K
 * Total Submissions: 84.9K
 * Testcase Example:  '[3,5]'
 *
 * You are given an array nums of non-negative integers. nums is considered
 * special if there exists a number x such that there are exactly x numbers in
 * nums that are greater than or equal to x.
 * 
 * Notice that x does not have to be an element in nums.
 * 
 * Return x if the array is special, otherwise, return -1. It can be proven
 * that if nums is special, the value for x is unique.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [3,5]
 * Output: 2
 * Explanation: There are 2 values (3 and 5) that are greater than or equal to
 * 2.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [0,0]
 * Output: -1
 * Explanation: No numbers fit the criteria for x.
 * If x = 0, there should be 0 numbers >= x, but there are 2.
 * If x = 1, there should be 1 number >= x, but there are 0.
 * If x = 2, there should be 2 numbers >= x, but there are 0.
 * x cannot be greater since there are only 2 numbers in nums.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [0,4,3,0,4]
 * Output: 3
 * Explanation: There are 3 values that are greater than or equal to 3.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 100
 * 0 <= nums[i] <= 1000
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int left = -1, right = nums.back()+1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            int cnt = 0;
            for (int num: nums) cnt += num >= mid ? 1 : 0;
            
            if (cnt == mid) return mid;
            if (cnt > mid) left = mid + 1;
            else right = mid - 1;
        }
        return -1;

        vector<int> cnts(102, 0);
        for (int num: nums) {
            if (num >100) cnts[100] += 1;
            else cnts[num] += 1;
        }
        
        for (int i=100; i>0; --i) {
            cnts[i] += cnts[i+1];
            if (cnts[i] == i) return i;
        }
        return -1;

        sort(nums.begin(), nums.end());
        int n = nums.size();
        if (nums[0] >= n) return n;
        
        int left = 0, right = n-1;
        while (left <= right) {
            int mid =  left + (right - left) / 2;
            
            int cnt = nums.size() - mid;
            
            // reality: cnt >= nums[mid];
            // expect: cnt >= cnt;
            if (nums[mid] >= cnt && nums[mid-1] < cnt) return cnt ;
            if (nums[mid] < cnt) left = mid + 1;
            else right = mid - 1;
        }
        return -1;
    }
};
// @lc code=end

