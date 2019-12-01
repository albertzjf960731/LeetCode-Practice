/*
 * @lc app=leetcode.cn id=137 lang=cpp
 *
 * [137] Single Number II
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int one=0, two=0;
        for (int num: nums) {
            one = (one ^ num) & ~two;
            two = (two ^ num) & ~one;
        }
        return one;
    }
};
// @lc code=end

