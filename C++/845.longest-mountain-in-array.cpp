/*
 * @lc app=leetcode id=845 lang=cpp
 *
 * [845] Longest Mountain in Array
 *
 * https://leetcode.com/problems/longest-mountain-in-array/description/
 *
 * algorithms
 * Medium (37.34%)
 * Likes:    658
 * Dislikes: 27
 * Total Accepted:    37.1K
 * Total Submissions: 99.3K
 * Testcase Example:  '[2,1,4,7,3,2,5]'
 *
 * Let's call any (contiguous) subarray B (of A) a mountain if the following
 * properties hold:
 * 
 * 
 * B.length >= 3
 * There exists some 0 < i < B.length - 1 such that B[0] < B[1] < ... B[i-1] <
 * B[i] > B[i+1] > ... > B[B.length - 1]
 * 
 * 
 * (Note that B could be any subarray of A, including the entire array A.)
 * 
 * Given an array A of integers, return the length of the longest mountain. 
 * 
 * Return 0 if there is no mountain.
 * 
 * Example 1:
 * 
 * 
 * Input: [2,1,4,7,3,2,5]
 * Output: 5
 * Explanation: The largest mountain is [1,4,7,3,2] which has length 5.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [2,2,2]
 * Output: 0
 * Explanation: There is no mountain.
 * 
 * 
 * Note:
 * 
 * 
 * 0 <= A.length <= 10000
 * 0 <= A[i] <= 10000
 * 
 * 
 * Follow up:
 * 
 * 
 * Can you solve it using only one pass?
 * Can you solve it in O(1) space?
 * 
 * 
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int longestMountain(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n), right(n);
        for (int i=n-2; i>=0; --i) 
            if (nums[i]>nums[i+1]) 
                right[i] = right[i+1] + 1;
        for (int i=1; i<n; ++i) 
            if (nums[i]>nums[i-1]) 
                left[i] = left[i-1] + 1;
        
        int ans = 0;
        for (int i=1; i<n; ++i)
            if (left[i]>0 && right[i]>0) 
                ans = max(ans, left[i]+right[i]+1);
        return ans;
    }
};
// @lc code=end

