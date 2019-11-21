#
# @lc app=leetcode id=376 lang=python
#
# [376] Wiggle Subsequence
#
# https://leetcode.com/problems/wiggle-subsequence/description/
#
# algorithms
# Medium (38.42%)
# Likes:    679
# Dislikes: 52
# Total Accepted:    55.7K
# Total Submissions: 144.7K
# Testcase Example:  '[1,7,4,9,2,5]'
#
# A sequence of numbers is called a wiggle sequence if the differences between
# successive numbers strictly alternate between positive and negative. The
# first difference (if one exists) may be either positive or negative. A
# sequence with fewer than two elements is trivially a wiggle sequence.
# 
# For example, [1,7,4,9,2,5] is a wiggle sequence because the differences
# (6,-3,5,-7,3) are alternately positive and negative. In contrast, [1,4,7,2,5]
# and [1,7,4,5,5] are not wiggle sequences, the first because its first two
# differences are positive and the second because its last difference is zero.
# 
# Given a sequence of integers, return the length of the longest subsequence
# that is a wiggle sequence. A subsequence is obtained by deleting some number
# of elements (eventually, also zero) from the original sequence, leaving the
# remaining elements in their original order.
# 
# Example 1:
# 
# 
# Input: [1,7,4,9,2,5]
# Output: 6
# Explanation: The entire sequence is a wiggle sequence.
# 
# 
# Example 2:
# 
# 
# Input: [1,17,5,10,13,15,10,5,16,8]
# Output: 7
# Explanation: There are several subsequences that achieve this length. One is
# [1,17,10,13,10,16,8].
# 
# 
# Example 3:
# 
# 
# Input: [1,2,3,4,5,6,7,8,9]
# Output: 2
# 
# Follow up:
# Can you do it in O(n) time?
# 
# 
# 
#

# @lc code=start
class Solution(object):
    def wiggleMaxLength(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # if len(nums) <= 1:
        #     return len(nums)
        # if len(nums) == 2:
        #     if nums[0] == nums[1]:
        #         return 1
        #     else:
        #         return 2


        # increased = True if nums[0]<nums[1] else False

        # ans = 1 if nums[0] != nums[1] else 0
        # for i in range(len(nums)-1):
        #     # if nums[i] == nums[i+1]:
        #     #     continue
        #     if increased and nums[i] > nums[i+1]:
        #         ans += 1
        #         increased = False
        #         print(nums[i])
        #     if not increased and nums[i]<nums[i+1]:
        #         ans += 1
        #         increased = True
        #         print(nums[i])
        # if increased and nums[i] < nums[i+1]:
        #     ans += 1
        # if not increased and nums[i] > nums[i+1]:
        #     ans += 1
        # return ans 
                
        if not nums:
            return 0 
        up, down = 1, 1
        for i in range(1, len(nums)):
            if nums[i] > nums[i-1]:
                up = down + 1
            elif nums[i] < nums[i-1]:
                down = up + 1
        return max(up, down)


# @lc code=end

sol = Solution()
# nums = [1,17,5,10,13,15,10,5,16,8]
nums =[1,1,7,4,9,2,5]

print(sol.wiggleMaxLength(nums))