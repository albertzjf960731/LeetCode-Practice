#
# @lc app=leetcode id=2640 lang=python3
#
# [2640] Find the Score of All Prefixes of an Array
#
# https://leetcode.com/problems/find-the-score-of-all-prefixes-of-an-array/description/
#
# algorithms
# Medium (70.68%)
# Likes:    288
# Dislikes: 35
# Total Accepted:    30.5K
# Total Submissions: 43.1K
# Testcase Example:  '[2,3,7,5,10]'
#
# We define the conversion array conver of an array arr as follows:
# 
# 
# conver[i] = arr[i] + max(arr[0..i]) where max(arr[0..i]) is the maximum value
# of arr[j] over 0 <= j <= i.
# 
# 
# We also define the score of an array arr as the sum of the values of the
# conversion array of arr.
# 
# Given a 0-indexed integer array nums of length n, return an array ans of
# length n where ans[i] is the score of the prefix nums[0..i].
# 
# 
# Example 1:
# 
# 
# Input: nums = [2,3,7,5,10]
# Output: [4,10,24,36,56]
# Explanation: 
# For the prefix [2], the conversion array is [4] hence the score is 4
# For the prefix [2, 3], the conversion array is [4, 6] hence the score is 10
# For the prefix [2, 3, 7], the conversion array is [4, 6, 14] hence the score
# is 24
# For the prefix [2, 3, 7, 5], the conversion array is [4, 6, 14, 12] hence the
# score is 36
# For the prefix [2, 3, 7, 5, 10], the conversion array is [4, 6, 14, 12, 20]
# hence the score is 56
# 
# 
# Example 2:
# 
# 
# Input: nums = [1,1,2,4,8,16]
# Output: [2,4,8,16,32,64]
# Explanation: 
# For the prefix [1], the conversion array is [2] hence the score is 2
# For the prefix [1, 1], the conversion array is [2, 2] hence the score is 4
# For the prefix [1, 1, 2], the conversion array is [2, 2, 4] hence the score
# is 8
# For the prefix [1, 1, 2, 4], the conversion array is [2, 2, 4, 8] hence the
# score is 16
# For the prefix [1, 1, 2, 4, 8], the conversion array is [2, 2, 4, 8, 16]
# hence the score is 32
# For the prefix [1, 1, 2, 4, 8, 16], the conversion array is [2, 2, 4, 8, 16,
# 32] hence the score is 64
# 
# 
# 
# Constraints:
# 
# 
# 1 <= nums.length <= 10^5
# 1 <= nums[i] <= 10^9
# 
# 
#

# @lc code=start
class Solution:
    def findPrefixScore(self, nums: List[int]) -> List[int]:
        conver = []
        max_val = 0
        for i in range(len(nums)):
            max_val = max(max_val, nums[i])
            conver.append(nums[i] + max_val)

        ans = [conver[0]]
        for i in range(1, len(conver)):
            ans.append(conver[i] + ans[i-1])
        return ans
        
# @lc code=end

