/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] Rotate Image
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>>& nums) {
        // int n = matrix.size();
        // for (int i=0; i<n; i++) {
        //     for (int j=0; j<i; j++) {
        //         swap(matrix[i][j], matrix[j][i]);
        //     }
        // }
        // for (int i=0; i<n; i++)
        //     reverse(matrix[i].begin(), matrix[i].end());
        
        reverse(nums.begin(), nums.end());
        for (int i=0; i<nums.size(); ++i) {
            for (int j=i+1; j<nums[0].size(); ++j)
                swap(nums[i][j], nums[j][i]);
        }

        // int n = matrix.size(), temp;
        // for (int i=0; i<n/2; i++) {
        //     for (int j=i; j<n-i-1; j++) {
        //         temp = matrix[i][j];
        //         matrix[i][j] = matrix[n-j-1][i];
        //         matrix[n-j-1][i] = matrix[n-i-1][n-j-1];
        //         matrix[n-i-1][n-j-1] = matrix[j][n-i-1];
        //         matrix[j][n-i-1] = temp;
        //     }
        // }
    }
};
// @lc code=end

