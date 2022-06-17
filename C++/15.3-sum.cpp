/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (27.20%)
 * Likes:    8695
 * Dislikes: 935
 * Total Accepted:    1.1M
 * Total Submissions: 4.1M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an array nums of n integers, are there elements a, b, c in nums such
 * that a + b + c = 0? Find all unique triplets in the array which gives the
 * sum of zero.
 * 
 * Notice that the solution set must not contain duplicate triplets.
 * 
 * 
 * Example 1:
 * Input: nums = [-1,0,1,2,-1,-4]
 * Output: [[-1,-1,2],[-1,0,1]]
 * Example 2:
 * Input: nums = []
 * Output: []
 * Example 3:
 * Input: nums = [0]
 * Output: []
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= nums.length <= 3000
 * -10^5 <= nums[i] <= 10^5
 * 
 * 
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
        // unorsered_set 不改变原数组
        
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