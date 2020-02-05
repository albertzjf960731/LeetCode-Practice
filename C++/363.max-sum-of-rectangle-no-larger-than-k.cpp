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
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        if (matrix.empty()) 
            return 0;
        
        int ans = INT_MIN;
        int rows=matrix.size(), cols=matrix[0].size();
        for (int l=0; l<cols; l++) {

            vector<int> sums(rows, 0);
            for (int r=l; r<cols; r++) {
                for (int i=0; i<rows; i++) 
                    sums[i] += matrix[i][r];
                ans = max(ans, maxSubarray(sums, k));
            }
        }
        return ans;
    }

    int maxSubarray(vector<int>& nums, int k) {
        int ans = INT_MIN;

        set<int> sums;
        sums.insert(0);

        for (int i=0, sum=0; i<nums.size(); i++) {
            sum += nums[i];
            auto it = sums.lower_bound(sum-k);
            if (it != sums.end())
                ans = max(ans, sum-*it);
            sums.insert(sum);
        }
        return ans;
    }
};
// @lc code=end

