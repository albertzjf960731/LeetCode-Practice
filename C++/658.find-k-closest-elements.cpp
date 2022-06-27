/*
 * @lc app=leetcode id=658 lang=cpp
 *
 * [658] Find K Closest Elements
 *
 * https://leetcode.com/problems/find-k-closest-elements/description/
 *
 * algorithms
 * Medium (39.50%)
 * Likes:    940
 * Dislikes: 196
 * Total Accepted:    77.1K
 * Total Submissions: 195.1K
 * Testcase Example:  '[1,2,3,4,5]\n4\n3'
 *
 * 
 * Given a sorted array, two integers k and x, find the k closest elements to x
 * in the array.  The result should also be sorted in ascending order.
 * If there is a tie,  the smaller elements are always preferred.
 * 
 * 
 * Example 1:
 * 
 * Input: [1,2,3,4,5], k=4, x=3
 * Output: [1,2,3,4]
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: [1,2,3,4,5], k=4, x=-1
 * Output: [1,2,3,4]
 * 
 * 
 * 
 * Note:
 * 
 * The value k is positive and will always be smaller than the length of the
 * sorted array.
 * ⁠Length of the given array is positive and will not exceed 10^4
 * ⁠Absolute value of elements in the array and x will not exceed 10^4
 * 
 * 
 * 
 * 
 * 
 * 
 * UPDATE (2017/9/19):
 * The arr parameter had been changed to an array of integers (instead of a
 * list of integers). Please reload the code definition to get the latest
 * changes.
 * 
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> findClosestElements(vector<int>& nums, int k, int x) {
        // vector<int> dist;
        // for (int num: nums) 
        //     dist.push_back(abs(num-x));
        
        // int sum = 0;
        // for (int i=0; i<k; ++i)
        //     sum += dist[i];
        
        // int idx = 0;
        // int min_sum = sum;
        // for (int i=k; i<dist.size(); ++i) {
        //     sum += dist[i] - dist[i-k];
        //     if (sum < min_sum) {
        //         idx = i-k+1;
        //         min_sum = sum;
        //     }
        // }

        // vector<int> res;
        // while (k--) 
        //     res.push_back(nums[idx++]);
        // return res;  

        // vector<int> res = nums;
        // while (res.size() > k) {
        //     if (x - res.front() <= res.back() - x) {
        //         res.pop_back();
        //     } else {
        //         res.erase(res.begin());
        //     }
        // }
        // return res;

        int left=0, right=nums.size()-k, mid;
        while (left < right) {
            mid = left + (right-left)/2;
            if (x-nums[mid] > nums[mid+k]-x) 
                left = mid+1;
            else 
                right = mid;
        }
        return vector<int>(nums.begin()+left, nums.begin()+left+k);
    }
};
// @lc code=end

