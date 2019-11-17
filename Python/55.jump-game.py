#
# @lc app=leetcode id=55 lang=python
#
# [55] Jump Game
#
# https://leetcode.com/problems/jump-game/description/
#
# algorithms
# Medium (32.76%)
# Likes:    2559
# Dislikes: 243
# Total Accepted:    322.8K
# Total Submissions: 984.8K
# Testcase Example:  '[2,3,1,1,4]'
#
# Given an array of non-negative integers, you are initially positioned at the
# first index of the array.
# 
# Each element in the array represents your maximum jump length at that
# position.
# 
# Determine if you are able to reach the last index.
# 
# Example 1:
# 
# 
# Input: [2,3,1,1,4]
# Output: true
# Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
# 
# 
# Example 2:
# 
# 
# Input: [3,2,1,0,4]
# Output: false
# Explanation: You will always arrive at index 3 no matter what. Its
# maximum
# jump length is 0, which makes it impossible to reach the last index.
# 
# 
#

# @lc code=start
class Solution(object):
    def canJump(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        # last_pos = 0
        # max_pos = 0

        # for i in range(len(nums)-1):
        #     if i > last_pos:
        #         return False
        #     max_pos = max(max_pos, nums[i] + i)
        #     if i == last_pos:
        #         last_pos = max_pos
        # return max_pos >= len(nums)-1

        max_pos = 0
        # for i in range(len(nums)-1):
        for i in range(len(nums)):
            # if nums[i] == 0 and max_pos <= i:
            if max_pos < i:
                return False
            max_pos = max(max_pos, nums[i] + i)
        return True

# @lc code=end
sol = Solution()
nums = [0,2,3]
sol.canJump(nums)
