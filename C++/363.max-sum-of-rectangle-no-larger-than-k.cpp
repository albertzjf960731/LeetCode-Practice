/*
 * @lc app=leetcode id=363 lang=cpp
 *
 * [363] Max Sum of Rectangle No Larger Than K
 *
 * https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/description/
 *
 * algorithms
 * Hard (36.17%)
 * Likes:    594
 * Dislikes: 41
 * Total Accepted:    35.2K
 * Total Submissions: 97.2K
 * Testcase Example:  '[[1,0,1],[0,-2,3]]\n2'
 *
 * Given a non-empty 2D matrix matrix and an integer k, find the max sum of a
 * rectangle in the matrix such that its sum is no larger than k.
 * 
 * Example:
 * 
 * 
 * Input: matrix = [[1,0,1],[0,-2,3]], k = 2
 * Output: 2 
 * Explanation: Because the sum of rectangle [[0, 1], [-2, 3]] is
 * 2,
 * and 2 is the max number no larger than k (k = 2).
 * 
 * Note:
 * 
 * 
 * The rectangle inside the matrix must have an area > 0.
 * What if the number of rows is much larger than the number of columns?
 * 
 */
#include<vector>
#include<set>
using namespace std; 

// @lc code=start
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& nums, int k) {
        int rows = nums.size(), cols = nums[0].size();
        int ans = INT_MIN;
        
        vector<int> sums(rows, 0);
        for (int i=0; i<cols; ++i) {
            fill(sums.begin(), sums.end(), 0);
            
            for (int j=i; j<cols; ++j) {
                for (int k=0; k<rows; ++k)
                    sums[k] += nums[k][j];
                ans = max(ans, maxSubarray(sums, k));
            }
        }
        return ans;
    }
    
    int maxSubarray(vector<int>& nums, int k) {
        int ans = INT_MIN, sum = 0;
        set<int> hset{0};
        for (int num: nums) {
            sum += num;
            
            // num >= sum - k
            auto it = hset.lower_bound(sum - k);
            if (it != hset.end())
                ans = max(ans, sum-*it);
            
            hset.insert(sum);
        }
        return ans;
    }
};
// @lc code=end

