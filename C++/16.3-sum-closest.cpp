/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 3Sum Closest
 */

#include<vector>
#include<algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if (nums.size() < 3)
            return 0;
        
        sort(nums.begin(), nums.end());

        int ans = nums[0] + nums[1] + nums[2];
        int min_d = abs(ans-target);

        for (int i=0; i<nums.size()-2; i++) {
            int l = i+1, r = nums.size()-1;
            while (l<r) {
                int s = nums[i] + nums[l] + nums[r];
                int d = abs(s-target);

                if (d<min_d) {
                    min_d = d;
                    ans = s;
                }

                if (s==target) 
                    return s;
                else if (s<target)
                    l++;
                else 
                    r--;
            }
        }
    return ans;
    }
};
// @lc code=end

