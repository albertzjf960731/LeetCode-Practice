/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 4Sum
 */

#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;

        if(nums.size()<4) return res;

        sort(nums.begin(), nums.end());

        for (int i=0; i<nums.size()-3; i++) {
            if (i==0 || (i>0 && nums[i]!=nums[i-1])) {

                for (int j=i+1; j<nums.size()-2; j++) {
                    if (j==i+1 || (nums[j]!=nums[j-1])) {
                        int l=j+1, r=nums.size()-1;
                        int s=target-nums[i]-nums[j];
                        
                        while (l<r) {
                            if (nums[l]+nums[r] == s) {
                                res.push_back({nums[i], nums[j], nums[l], nums[r]});
                                while (l<r and nums[l]==nums[l+1])
                                    l+=1;
                                while (l<r and nums[r] == nums[r-1])
                                    r -=1;
                                l += 1;
                                r -= 1;
                            }
                            else if (nums[l]+nums[r] < s) {
                                l += 1;
                            }
                            else 
                                r -= 1;
                        }
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end

int main() {
    vector<int> nums = {1,0,-1,0,-2,2};
    int target = 0;
    Solution sol;   
    vector<vector<int>> res = sol.fourSum(nums, target);
    return 0;
}