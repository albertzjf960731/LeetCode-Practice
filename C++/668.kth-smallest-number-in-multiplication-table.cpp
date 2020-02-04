/*
 * @lc app=leetcode id=668 lang=cpp
 *
 * [668] Kth Smallest Number in Multiplication Table
 *
 * https://leetcode.com/problems/kth-smallest-number-in-multiplication-table/description/
 *
 * algorithms
 * Hard (44.03%)
 * Likes:    436
 * Dislikes: 18
 * Total Accepted:    17.2K
 * Total Submissions: 38.9K
 * Testcase Example:  '3\n3\n5'
 *
 * 
 * Nearly every one have used the Multiplication Table. But could you find out
 * the k-th smallest number quickly from the multiplication table?
 * 
 * 
 * 
 * Given the height m and the length n of a m * n Multiplication Table, and a
 * positive integer k, you need to return the k-th smallest number in this
 * table.
 * 
 * 
 * Example 1:
 * 
 * Input: m = 3, n = 3, k = 5
 * Output: 
 * Explanation: 
 * The Multiplication Table:
 * 1    2    3
 * 2    4    6
 * 3    6    9
 * 
 * The 5-th smallest number is 3 (1, 2, 2, 3, 3).
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: m = 2, n = 3, k = 6
 * Output: 
 * Explanation: 
 * The Multiplication Table:
 * 1    2    3
 * 2    4    6
 * 
 * The 6-th smallest number is 6 (1, 2, 2, 3, 4, 6).
 * 
 * 
 * 
 * 
 * Note:
 * 
 * The m and n will be in the range [1, 30000].
 * The k will be in the range [1, m * n]
 * 
 * 
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    // int findKthNumber(int m, int n, int k) {
    //     vector<vector<int>> matrix(m, vector<int>(n));
    //     for (int i=0; i<m; i++)
    //         matrix[i][0] = i+1;
    //     for (int j=0; j<n; j++)
    //         matrix[0][j] = j+1;
    //     for (int i=1; i<m; i++) {
    //         for (int j=1; j<n; j++) {
    //             matrix[i][j] = matrix[i][0] * matrix[0][j];
    //         }
    //     }
        
    //     return kthSmallest(matrix, k);
    // }
    
    // int kthSmallest(vector<vector<int>>& matrix, int k) {
    //     int m=matrix.size(), n=matrix[0].size();
        
    //     int left = matrix[0][0], right = matrix[m-1][n-1];
    //     while (left < right) {
    //         int mid = left + (right-left)/2;
            

    //         int count = 0;
    //         int j = n-1;
    //         for (int i=0; i<m; ++i) {
    //             while (j>=0 && matrix[i][j]>mid) 
    //                 j--;
    //             count += j+1;
    //         }
    
    //         if (count < k)
    //             left = mid+1;
    //         else 
    //             right = mid;
    //     }
    //     return left;
    // }

    int findKthNumber(int m, int n, int k) {        
        int left = 1, right = m*n;

        while (left < right) {
            int mid = left + (right-left)/2;
            
            int count = 0;
            for (int i=1; i<=m; i++) {
                count += (mid/i<=n) ? (mid/i) : n;
            }
            if (count < k)
                left = mid+1;
            else 
                right = mid;
        }
        return left;
    }
};
// @lc code=end

