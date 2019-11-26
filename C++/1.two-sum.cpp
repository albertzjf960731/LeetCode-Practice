/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] Two Sum
 */

#include<iostream>  
#include<vector>
#include<unordered_map>
using namespace std;  

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash_map;
        for (int i=0; i<nums.size(); i++) {
            if (hash_map.find(target-nums[i]) != hash_map.end()) {
                return {hash_map[target-nums[i]], i};
            }
            hash_map[nums[i]] = i;
        }
        return {};
    }
};
// @lc code=end

int main(){
    Solution sol;
    vector<int> nums = {2, 7, 11, 17};
    int target = 9;
    vector<int> ans = sol.twoSum(nums, target);
    cout << ans[0] << ' ' << ans[1] << endl;
}

