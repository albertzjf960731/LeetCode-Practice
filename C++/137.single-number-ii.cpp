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


        int ans = 0;
        //考虑每一位
        for (int i=0; i<32; i++) {
            int cnt = 0;
            for (int j=0; j<nums.size(); j++) {
                if ((nums[j]>>i & 1) == 1) {
                    cnt++;
                }
            }
            //1 的个数是否是 3 的倍数
            if (cnt%3 != 0) {
                ans = ans | (1<<i);
            }
        }
        return ans;
    }
};
// @lc code=end

