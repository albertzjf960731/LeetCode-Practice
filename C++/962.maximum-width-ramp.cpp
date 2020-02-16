/*
 * @lc app=leetcode id=962 lang=cpp
 *
 * [962] Maximum Width Ramp
 *
 * https://leetcode.com/problems/maximum-width-ramp/description/
 *
 * algorithms
 * Medium (43.73%)
 * Likes:    421
 * Dislikes: 10
 * Total Accepted:    14.3K
 * Total Submissions: 32.7K
 * Testcase Example:  '[6,0,8,2,1,5]'
 *
 * Given an array A of integers, a ramp is a tuple (i, j) for which i < j and
 * A[i] <= A[j].  The width of such a ramp is j - i.
 * 
 * Find the maximum width of a ramp in A.  If one doesn't exist, return 0.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [6,0,8,2,1,5]
 * Output: 4
 * Explanation: 
 * The maximum width ramp is achieved at (i, j) = (1, 5): A[1] = 0 and A[5] =
 * 5.
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [9,8,1,0,1,9,4,0,4,1]
 * Output: 7
 * Explanation: 
 * The maximum width ramp is achieved at (i, j) = (2, 9): A[2] = 1 and A[9] =
 * 1.
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 2 <= A.length <= 50000
 * 0 <= A[i] <= 50000
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int ans = 0;
        vector<int> stack;
        for (int i=0; i<nums.size(); i++) {
            if (stack.empty() || nums[i]<nums[stack.back()])
                stack.push_back(i);
            // else {
            //     int left=0, right=stack.size()-1;
            //     while (left<right) {
            //         int mid = left + (right-left)/2;
            //         if (nums[stack[mid]]>nums[i])
            //             left = mid+1;
            //         else 
            //             right = mid;
            //     }
            //     ans = max(ans, i-stack[left]);
            // }
        }
        for (int i=nums.size()-1; i>=0; --i)
            while (!stack.empty() && nums[stack.back()] <= nums[i]){
                ans = max(ans, i-stack.back());
                stack.pop_back();
            } 
        return ans;
    }
};
// @lc code=end

