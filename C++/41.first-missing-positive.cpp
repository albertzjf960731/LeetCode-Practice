/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] First Missing Positive
 */

#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // for(int i=0; i<nums.size(); i++) {
        //     if (i+1==nums[i]) 
        //         continue;
        //     while(nums[i]>=1 && nums[i]<=nums.size() && nums[i]!=nums[nums[i]-1])
        //         swap(nums[i], nums[nums[i]-1]);
        // }


        // 时间复杂度分析：代码中第二层while循环，每循环一次，会将一个数放在正确的位置上，所以总共最多执行 n 次，所以总时间复杂度 O(n)。

        for(int i=0; i<nums.size(); ++ i)
            while(nums[i]>0 && nums[i]<=nums.size() && nums[nums[i]-1]!=nums[i])
                swap(nums[i], nums[nums[i]-1]);

        for (int i=0; i<nums.size(); i++) {
            if (i+1!=nums[i]) 
                return i+1;
        }
        return nums.size()+1;    



    }
};
// @lc code=end

