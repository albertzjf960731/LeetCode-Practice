/*
 * @lc app=leetcode id=485 lang=cpp
 *
 * [485] Max Consecutive Ones
 *
 * https://leetcode.com/problems/max-consecutive-ones/description/
 *
 * algorithms
 * Easy (56.07%)
 * Likes:    493
 * Dislikes: 346
 * Total Accepted:    171.7K
 * Total Submissions: 306.2K
 * Testcase Example:  '[1,0,1,1,0,1]'
 *
 * Given a binary array, find the maximum number of consecutive 1s in this
 * array.
 * 
 * Example 1:
 * 
 * Input: [1,1,0,1,1,1]
 * Output: 3
 * Explanation: The first two digits or the last three digits are consecutive
 * 1s.
 * ⁠   The maximum number of consecutive 1s is 3.
 * 
 * 
 * 
 * Note:
 * 
 * The input array will only contain 0 and 1.
 * The length of input array is a positive integer and will not exceed 10,000
 * 
 * 
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        // int ans = 0;
        // for (int i=0, last=-1; i<nums.size(); i++) {
        //     if (nums[i]==0)
        //         last = i;
        //     else
        //         ans = max(ans, i-last);
        // }   
        // return ans;
        
        int ans = 0, cnt = 0;
        for (int num: nums) {
            if (num==1) {
                cnt ++;
                ans = max(ans, cnt);
            }
            else 
                cnt = 0;
        }
        return ans;
    }
};
// @lc code=end

