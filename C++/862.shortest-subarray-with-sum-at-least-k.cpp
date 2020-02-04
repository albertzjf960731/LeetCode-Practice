/*
 * @lc app=leetcode id=862 lang=cpp
 *
 * [862] Shortest Subarray with Sum at Least K
 *
 * https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/description/
 *
 * algorithms
 * Hard (23.10%)
 * Likes:    735
 * Dislikes: 20
 * Total Accepted:    20.8K
 * Total Submissions: 90.1K
 * Testcase Example:  '[1]\n1'
 *
 * Return the length of the shortest, non-empty, contiguous subarray of A with
 * sum at least K.
 * 
 * If there is no non-empty subarray with sum at least K, return -1.
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: A = [1], K = 1
 * Output: 1
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: A = [1,2], K = 4
 * Output: -1
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: A = [2,-1,2], K = 3
 * Output: 3
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= A.length <= 50000
 * -10 ^ 5 <= A[i] <= 10 ^ 5
 * 1 <= K <= 10 ^ 9
 * 
 * 
 * 
 * 
 * 
 */
#include<vector>
#include<numeric>
#include<deque>
using namespace std;

// @lc code=start
class Solution {
public:
    // int shortestSubarray(vector<int>& nums, int K) {
    //     int sum=0, len=INT_MAX;
    //     int left=0, right=0;

    //     while (right < nums.size()) {
    //         sum += nums[right++];
    //         while (sum>=K) { // 存在负数
    //             len = min(len, right-left);
    //             sum -= nums[left++];
    //         }
    //     }
    //     return len == INT_MAX ? -1 : len;
    // }


    int shortestSubarray(vector<int>& nums, int K) {
        int len=INT_MAX;
        deque<int> queue;

        for (int i=1; i<nums.size(); ++i) 
            nums[i] += nums[i-1];

        for (int i=0; i<nums.size(); ++i) {
            if (nums[i]>=K) len = min(len, i+1);

            while (!queue.empty() && nums[i]-nums[queue.front()]>=K) {
                len = min(len, i-queue.front());
                queue.pop_front();
            }
            
            // If x1 < x2 and P[x2] <= P[x1], then opt(y) can never be x1, as if P[x1] <= P[y] - K, then P[x2] <= P[x1] <= P[y] - K but y - x2 is smaller. This implies that our candidates x for opt(y) will have increasing values of P[x].
            while (!queue.empty() && nums[i]<nums[queue.back()])
                queue.pop_back();
            queue.push_back(i);
        }
        return len == INT_MAX ? -1 : len;
    }
    
};
// @lc code=end

