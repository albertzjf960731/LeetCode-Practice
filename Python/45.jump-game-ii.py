#
# @lc app=leetcode id=45 lang=python
#
# [45] Jump Game II
#
# https://leetcode.com/problems/jump-game-ii/description/
#
# algorithms
# Hard (29.11%)
# Likes:    1577
# Dislikes: 87
# Total Accepted:    202.8K
# Total Submissions: 696.2K
# Testcase Example:  '[2,3,1,1,4]'
#
# Given an array of non-negative integers, you are initially positioned at the
# first index of the array.
# 
# Each element in the array represents your maximum jump length at that
# position.
# 
# Your goal is to reach the last index in the minimum number of jumps.
# 
# Example:
# 
# 
# Input: [2,3,1,1,4]
# Output: 2
# Explanation: The minimum number of jumps to reach the last index is 2.
# ⁠   Jump 1 step from index 0 to 1, then 3 steps to the last index.
# 
# Note:
# 
# You can assume that you can always reach the last index.
# 
#

# @lc code=start
class Solution(object):
    def jump(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        last_pos = 0 # 当前能跳到的最远的
        max_pos = 0
        steps = 0

        for i in range(len(nums)-1):
            max_pos = max(max_pos, nums[i] + i)
            if i == last_pos:
                last_pos = max_pos
                steps += 1

        return steps

# @lc code=end
sol = Solution()
nums = [2,3,1,1,4]
sol.jump(nums)
