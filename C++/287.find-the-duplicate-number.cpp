/*
 * @lc app=leetcode id=287 lang=cpp
 *
 * [287] Find the Duplicate Number
 *
 * https://leetcode.com/problems/find-the-duplicate-number/description/
 *
 * algorithms
 * Medium (52.03%)
 * Likes:    3386
 * Dislikes: 415
 * Total Accepted:    254.5K
 * Total Submissions: 486.6K
 * Testcase Example:  '[1,3,4,2,2]'
 *
 * Given an array nums containing n + 1 integers where each integer is between
 * 1 and n (inclusive), prove that at least one duplicate number must exist.
 * Assume that there is only one duplicate number, find the duplicate one.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,3,4,2,2]
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [3,1,3,4,2]
 * Output: 3
 * 
 * Note:
 * 
 * 
 * You must not modify the array (assume the array is read only).
 * You must use only constant, O(1) extra space.
 * Your runtime complexity should be less than O(n^2).
 * There is only one duplicate number in the array, but it could be repeated
 * more than once.
 * 
 * 
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[nums[0]];
        while (slow!=fast){
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        
        fast = 0;
        while (slow!=fast) {
            fast = nums[fast];
            slow = nums[slow];
        }
        return slow;


        for (int i=0; i<nums.size(); i++) {
            int p = abs(nums[i])-1;
            if(nums[p]>0)
                nums[p] *= -1;
            else
                return p+1;
        }
        return -1;


        int left=1, right=nums.size()-1;
        while (left<right) {
            int mid = left + (right-left)/2;
        
            int cnt = 0;
            for (int num: nums) {
                if (num<=mid)
                    cnt ++;
            }
            if(cnt<=mid)
                left = mid+1;
            else 
                right = mid;
        }
        return left;
    }
};
// @lc code=end

