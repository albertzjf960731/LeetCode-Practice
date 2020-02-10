/*
 * @lc app=leetcode id=556 lang=cpp
 *
 * [556] Next Greater Element III
 *
 * https://leetcode.com/problems/next-greater-element-iii/description/
 *
 * algorithms
 * Medium (30.96%)
 * Likes:    486
 * Dislikes: 150
 * Total Accepted:    34.2K
 * Total Submissions: 110.5K
 * Testcase Example:  '12'
 *
 * Given a positive 32-bit integer n, you need to find the smallest 32-bit
 * integer which has exactly the same digits existing in the integer n and is
 * greater in value than n. If no such positive 32-bit integer exists, you need
 * to return -1.
 * 
 * Example 1:
 * 
 * 
 * Input: 12
 * Output: 21
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 21
 * Output: -1
 * 
 * 
 * 
 * 
 */
#include<vector>
#include<string>
using namespace std;
// @lc code=start
class Solution {
public:
    int nextGreaterElement(int n) {
        string digits = to_string(n);
        // next_permutation(begin(digits), end(digits));
        nextPermutation(digits);
        long res = stol(digits);
        return (res>INT_MAX || res<=n) ? -1 : res;
    }

    bool nextPermutation(string& nums) {
        if(nums.empty()) 
            return false;
        int i=nums.size()-1;
        while(i>=1 && nums[i]<=nums[i-1]) 
            i--;
        if(i==0) 
            return false; // no next permutation, i.e. already largest
        
        int j=nums.size()-1;
        while(nums[j]<=nums[i-1]) 
            j--;
        swap(nums[i-1],nums[j]);
        reverse(nums.begin()+i, nums.end());
        return true;
    }
};
// @lc code=end

