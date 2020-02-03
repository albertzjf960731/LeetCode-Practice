/*
 * @lc app=leetcode id=852 lang=cpp
 *
 * [852] Peak Index in a Mountain Array
 *
 * https://leetcode.com/problems/peak-index-in-a-mountain-array/description/
 *
 * algorithms
 * Easy (70.78%)
 * Likes:    448
 * Dislikes: 941
 * Total Accepted:    123.6K
 * Total Submissions: 174.7K
 * Testcase Example:  '[0,1,0]'
 *
 * Let's call an array A a mountain if the following properties hold:
 * 
 * 
 * A.length >= 3
 * There exists some 0 < i < A.length - 1 such that A[0] < A[1] < ... A[i-1] <
 * A[i] > A[i+1] > ... > A[A.length - 1]
 * 
 * 
 * Given an array that is definitely a mountain, return any i such that A[0] <
 * A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1].
 * 
 * Example 1:
 * 
 * 
 * Input: [0,1,0]
 * Output: 1
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [0,2,1,0]
 * Output: 1
 * 
 * 
 * Note:
 * 
 * 
 * 3 <= A.length <= 10000
 * 0 <= A[i] <= 10^6
 * A is a mountain, as defined above.
 * 
 * 
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& nums) {

        // return max_element(nums.begin(), nums.end()) - nums.begin();

        int left=0, right=nums.size()-1;
        while (left<right) {
            int mid = left + (right-left)/2;
            if (nums[mid] < nums[mid+1]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};
// @lc code=end

