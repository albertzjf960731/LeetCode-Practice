/*
 * @lc app=leetcode id=229 lang=cpp
 *
 * [229] Majority Element II
 *
 * https://leetcode.com/problems/majority-element-ii/description/
 *
 * algorithms
 * Medium (34.12%)
 * Likes:    1239
 * Dislikes: 145
 * Total Accepted:    125.2K
 * Total Submissions: 366.7K
 * Testcase Example:  '[3,2,3]'
 *
 * Given an integer array of size n, find all elements that appear more than ⌊
 * n/3 ⌋ times.
 * 
 * Note: The algorithm should run in linear time and in O(1) space.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,2,3]
 * Output: [3]
 * 
 * Example 2:
 * 
 * 
 * Input: [1,1,1,3,3,2,2,2]
 * Output: [1,2]
 * 
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
         int cnt1 = 0, cnt2 = 0, ans1, ans2;
        for (int num : nums) {
            if (num==ans1) cnt1++;
            else if (num==ans2) cnt2++;
            else if (cnt1==0) {
                ans1 = num;
                cnt1++;
            } 
            else if (cnt2==0) {
                ans2 = num;
                cnt2++;
            } 
            else {
                cnt1--;
                cnt2--;
            }
        }
        
        cnt1 = 0, cnt2 = 0;
        for (int num : nums) {
            if (num==ans1) cnt1++;
            else if (num==ans2) cnt2++;
        }
        
        vector<int> res;
        if (cnt1 > nums.size()/3) res.push_back(ans1);
        if (cnt2 > nums.size()/3) res.push_back(ans2);
        
        return res;
    }
};
// @lc code=end

