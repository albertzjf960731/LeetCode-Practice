/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 */
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector <vector<int> >& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) {
            return false;
        }

        int rows = matrix.size(), cols = matrix[0].size();
        int left = 0, right = rows * cols - 1;

        while (left <= right) {
            int mid = (left + right) / 2;
            int num = matrix[mid/cols][mid%cols];
            if (target == num)
                return true;
            else if (target > num) 
                left = mid + 1;
            else 
                right = mid - 1;
        }
        return false;    
    }
};
// @lc code=end

