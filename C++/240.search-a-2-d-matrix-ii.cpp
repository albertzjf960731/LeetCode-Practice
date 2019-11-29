/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] Search a 2D Matrix II
 */

#include<iostream>
#include<vector>

using namespace std;

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector< vector<int> >& matrix, int target) {
        if (matrix.empty() || matrix[0].empty())
            return false;

        int rows = matrix.size(), cols = matrix[0].size();

        int i = 0, j = cols-1;
        while (i<rows && j>-1) {
            if (target == matrix[i][j])
                return true;
            else if (target > matrix[i][j])
                i++;
            else 
                j--;
        }
        return false;
    }
};
// @lc code=end

