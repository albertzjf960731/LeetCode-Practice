/*
 * @lc app=leetcode id=1004 lang=cpp
 *
 * [1004] Max Consecutive Ones III
 *
 * https://leetcode.com/problems/max-consecutive-ones-iii/description/
 *
 * algorithms
 * Medium (56.54%)
 * Likes:    634
 * Dislikes: 15
 * Total Accepted:    33.9K
 * Total Submissions: 60K
 * Testcase Example:  '[1,1,1,0,0,0,1,1,1,1,0]\n2'
 *
 * Given an array A of 0s and 1s, we may change up to K values from 0 to 1.
 * 
 * Return the length of the longest (contiguous) subarray that contains only
 * 1s. 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: A = [1,1,1,0,0,0,1,1,1,1,0], K = 2
 * Output: 6
 * Explanation: 
 * [1,1,1,0,0,1,1,1,1,1,1]
 * Bolded numbers were flipped from 0 to 1.  The longest subarray is
 * underlined.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: A = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], K = 3
 * Output: 10
 * Explanation: 
 * [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
 * Bolded numbers were flipped from 0 to 1.  The longest subarray is
 * underlined.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= A.length <= 20000
 * 0 <= K <= A.length
 * A[i] is 0 or 1 
 * 
 * 
 * 
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans = 0;
        for (int left=0, right=0, cnt_zero=0; right<nums.size(); right++) {
            if (nums[right]==0)
                cnt_zero++;
            
            while (cnt_zero>k) {
                if (nums[left]==0) 
                    cnt_zero--;
                left ++;
            }
            // cout << "cnt=" << cnt_zero;
            // cout << " left=" << left << " right="<<right<<endl;
            ans = max(ans, right-left+1);
        }
        return ans;
    }
};
// @lc code=end

