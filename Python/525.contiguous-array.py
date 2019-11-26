#
# @lc app=leetcode id=525 lang=python
#
# [525] Contiguous Array
#
# https://leetcode.com/problems/contiguous-array/description/
#
# algorithms
# Medium (43.94%)
# Likes:    901
# Dislikes: 46
# Total Accepted:    48.9K
# Total Submissions: 110.8K
# Testcase Example:  '[0,1]'
#
# Given a binary array, find the maximum length of a contiguous subarray with
# equal number of 0 and 1. 
# 
# 
# Example 1:
# 
# Input: [0,1]
# Output: 2
# Explanation: [0, 1] is the longest contiguous subarray with equal number of 0
# and 1.
# 
# 
# 
# Example 2:
# 
# Input: [0,1,0]
# Output: 2
# Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal
# number of 0 and 1.
# 
# 
# 
# Note:
# The length of the given binary array will not exceed 50,000.
# 
#

# @lc code=start
class Solution(object):
    def findMaxLength(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        count = 0
        ans = 0
        hash_dict = {0: -1}
        # 第一次得到的一个count, 到现在的count 中间的数一定是符合要求的
        # for i, num in enumerate(nums, 1): # i 从1 开始计数
        for i in range(len(nums)): # i 从1 开始计数
            num = nums[i]
            if num == 0:
                count -= 1
            else:
                count += 1
                

            if count in hash_dict:
                ans = max(ans, i - hash_dict[count])
            else:
                hash_dict[count] = i
        
        return ans
# @lc code=end

sol = Solution()
nums = [0, 0, 1, 0, 1]
print(sol.findMaxLength(nums))