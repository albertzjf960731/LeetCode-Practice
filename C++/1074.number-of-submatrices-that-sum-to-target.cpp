/*
 * @lc app=leetcode id=1074 lang=cpp
 *
 * [1074] Number of Submatrices That Sum to Target
 *
 * https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/description/
 *
 * algorithms
 * Hard (66.33%)
 * Likes:    2237
 * Dislikes: 55
 * Total Accepted:    65.1K
 * Total Submissions: 95.3K
 * Testcase Example:  '[[0,1,0],[1,1,1],[0,1,0]]\n0'
 *
 * Given a matrix and a target, return the number of non-empty submatrices that
 * sum to target.
 * 
 * A submatrix x1, y1, x2, y2 is the set of all cells matrix[x][y] with x1 <= x
 * <= x2 and y1 <= y <= y2.
 * 
 * Two submatrices (x1, y1, x2, y2) and (x1', y1', x2', y2') are different if
 * they have some coordinate that is different: for example, if x1 != x1'.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: matrix = [[0,1,0],[1,1,1],[0,1,0]], target = 0
 * Output: 4
 * Explanation: The four 1x1 submatrices that only contain 0.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: matrix = [[1,-1],[-1,1]], target = 0
 * Output: 5
 * Explanation: The two 1x2 submatrices, plus the two 2x1 submatrices, plus the
 * 2x2 submatrix.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: matrix = [[904]], target = 0
 * Output: 0
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= matrix.length <= 100
 * 1 <= matrix[0].length <= 100
 * -1000 <= matrix[i] <= 1000
 * -10^8 <= target <= 10^8
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& nums, int target) {
        int rows = nums.size(), cols = nums[0].size();
        int ans = 0;
        
        unordered_map<int, int> cnts;
        for (int i=0; i<cols; ++i) {
            
            vector<int> sums(rows, 0);
            for (int j=i; j<cols; ++j) {
                for (int k=0; k<rows; ++k)
                    sums[k] += nums[k][j];
                ans += numSubarraySumTarget(sums, target);
            }
        }
        return ans;
    }
    
    int numSubarraySumTarget(vector<int>& nums, int target) {
        unordered_map<int, int> cnts = {{0, 1}};
        int ans = 0, sum = 0;
        for (int num: nums) {
            sum += num;
            ans += cnts[sum-target];
            cnts[sum] += 1;
        }
        return ans;
    }
};
// @lc code=end

