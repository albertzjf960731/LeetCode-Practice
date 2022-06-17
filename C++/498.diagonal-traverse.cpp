/*
 * @lc app=leetcode id=498 lang=cpp
 *
 * [498] Diagonal Traverse
 *
 * https://leetcode.com/problems/diagonal-traverse/description/
 *
 * algorithms
 * Medium (48.31%)
 * Likes:    836
 * Dislikes: 348
 * Total Accepted:    90.1K
 * Total Submissions: 186.1K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * Given a matrix of M x N elements (M rows, N columns), return all elements of
 * the matrix in diagonal order as shown in the below image.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 4, 5, 6 ],
 * ⁠[ 7, 8, 9 ]
 * ]
 * 
 * Output:  [1,2,4,7,5,3,6,8,9]
 * 
 * Explanation:
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * The total number of elements of the given matrix will not exceed 10,000.
 * 
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        
        // multiset<int> cnts;
        // int ans = 0;
        // for (int i=0, j=0; i<nums.size(); ++i) {
        //     cnts.insert(nums[i]);
        //     while (*cnts.rbegin()-*cnts.begin() > limit) {
        //         cnts.erase(cnts.find(nums[j]));
        //         j++;
        //     }
        //     ans = max(ans, i-j+1);
        // }
        // return ans;

        if (matrix.empty()) return {};
        
        vector<int> res;
        int n = matrix.size(), m = matrix[0].size();
        
        // i++, j--;
        for (int i = 0; i< m+n-1; ++i) {
            if (i & 1) {
                for (int j=min(m-1, i); j>=max(0, i-n+1); --j)
                    res.push_back(matrix[i-j][j]);
            }
            else {
                for (int j = max(0, i-n+1); j <= min(m-1, i); ++j)
                    res.push_back(matrix[i-j][j]);
            }
        }
        return res;
    }
};
// @lc code=end

