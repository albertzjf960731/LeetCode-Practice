/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 3Sum
 */

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        
        if (nums.size()<3)
            return vector<vector<int> >();

        sort(nums.begin(), nums.end());
        vector<vector<int> > res;

        for (int i=0; i<nums.size()-2; i++) {
            if (i==0 or (i>0 and nums[i]!=nums[i-1])) {
                int l=i+1, r=nums.size()-1;
                int s=0-nums[i];
                
                while (l<r) {
                    if (nums[l]+nums[r] == s) {
                        res.push_back({nums[i], nums[l], nums[r]});
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
        return res;
    }
};
// @lc code=end

int main() {
    Solution sol;

    vector<int> nums = {-1,0,1,2,-1,-4};
    vector<vector<int> > res = sol.threeSum(nums);
    for (int i=0; i<res.size(); i++) {
        vector<int> triplet = res[i];
        for (int j=0; j<3; j++) {
            cout << triplet[j];
        }
        cout << endl;
    }
}