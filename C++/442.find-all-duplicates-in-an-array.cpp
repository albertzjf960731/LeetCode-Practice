/*
 * @lc app=leetcode id=442 lang=cpp
 *
 * [442] Find All Duplicates in an Array
 *
 * https://leetcode.com/problems/find-all-duplicates-in-an-array/description/
 *
 * algorithms
 * Medium (63.68%)
 * Likes:    1561
 * Dislikes: 132
 * Total Accepted:    132.1K
 * Total Submissions: 207.4K
 * Testcase Example:  '[4,3,2,7,8,2,3,1]'
 *
 * Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements
 * appear twice and others appear once.
 * 
 * Find all the elements that appear twice in this array.
 * 
 * Could you do it without extra space and in O(n) runtime?
 * 
 * Example:
 * 
 * Input:
 * [4,3,2,7,8,2,3,1]
 * 
 * Output:
 * [2,3]
 * 
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;

        for (int i=0; i<nums.size(); i++) {
            int p = abs(nums[i])-1;
            nums[p] *= -1;
            if(nums[p]>0)
                res.push_back(p+1);
        }
        return res;


        // for (int i=0; i<nums.size(); i++) {
        //     while(true) {
        //         if (i+1==nums[i])
        //             break;
        //         if (nums[i]==nums[nums[i]-1])
        //             break;
        //         swap(nums[i], nums[nums[i]-1]);
        //     }
        // }
        for(int i=0; i<nums.size(); ++ i)
            while(nums[nums[i]-1]!=nums[i])
                swap(nums[i], nums[nums[i]-1]);

        vector<int> res;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i]!=(i+1)) {
                res.push_back(nums[i]);
            }
        }
        return res;
    }
};
// @lc code=end

