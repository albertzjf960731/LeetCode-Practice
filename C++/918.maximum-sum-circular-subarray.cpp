/*
 * @lc app=leetcode id=918 lang=cpp
 *
 * [918] Maximum Sum Circular Subarray
 *
 * https://leetcode.com/problems/maximum-sum-circular-subarray/description/
 *
 * algorithms
 * Medium (33.80%)
 * Likes:    485
 * Dislikes: 24
 * Total Accepted:    16.3K
 * Total Submissions: 48.1K
 * Testcase Example:  '[1,-2,3,-2]'
 *
 * Given a circular array C of integers represented by A, find the maximum
 * possible sum of a non-empty subarray of C.
 * 
 * Here, a circular array means the end of the array connects to the beginning
 * of the array.  (Formally, C[i] = A[i] when 0 <= i < A.length, and
 * C[i+A.length] = C[i] when i >= 0.)
 * 
 * Also, a subarray may only include each element of the fixed buffer A at most
 * once.  (Formally, for a subarray C[i], C[i+1], ..., C[j], there does not
 * exist i <= k1, k2 <= j with k1 % A.length = k2 % A.length.)
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [1,-2,3,-2]
 * Output: 3
 * Explanation: Subarray [3] has maximum sum 3
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [5,-3,5]
 * Output: 10
 * Explanation: Subarray [5,5] has maximum sum 5 + 5 = 10
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: [3,-1,2,-1]
 * Output: 4
 * Explanation: Subarray [2,-1,3] has maximum sum 2 + (-1) + 3 = 4
 * 
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: [3,-2,2,-3]
 * Output: 3
 * Explanation: Subarray [3] and [3,-2,2] both have maximum sum 3
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: [-2,-3,-1]
 * Output: -1
 * Explanation: Subarray [-1] has maximum sum -1
 * 
 * 
 * 
 * 
 * Note: 
 * 
 * 
 * -30000 <= A[i] <= 30000
 * 1 <= A.length <= 30000
 * 
 * 
 * 
 * 
 * 
 * 
 */
#include<vector>
#include<deque>
using namespace std;

// @lc code=start
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        // int total_sum = 0;
        // int cur_max = 0, max_sum = INT_MIN;
        // int cur_min = 0, min_sum = INT_MAX;

        // for (int num: nums) {
        //     cur_max = max(cur_max+num, num);
        //     max_sum = max(max_sum, cur_max);

        //     cur_min = min(cur_min+num, num);
        //     min_sum = min(min_sum, cur_min);

        //     total_sum += num;
        // }      

        // return max_sum>0 ? max(max_sum, total_sum-min_sum) : max_sum;

        int n = nums.size();
        vector<int> sums(n*2, 0);
        for (int i=1; i<n*2; i++) 
            sums[i] = sums[i-1] + nums[(i-1)%n];
            
        // 单调队列来快速求解。维护一个单调递增的队列，队头元素为最小值，每次循环时首先将不满足长度的队头出队，然后更新当前的答案
        
        int ans = nums[0];
        deque<int> queue{0};

        for (int i=1; i<sums.size(); ++i) {

            while (!queue.empty() && i-queue.front()>n) 
                queue.pop_front();
            
            ans = max(ans, sums[i]-sums[queue.front()]);

            while (!queue.empty() && sums[i]<sums[queue.back()])
                queue.pop_back();

            queue.push_back(i);
        }
        return ans;
    }
};
// @lc code=end

