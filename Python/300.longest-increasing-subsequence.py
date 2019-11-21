#
# @lc app=leetcode id=300 lang=python
#
# [300] Longest Increasing Subsequence
#
# https://leetcode.com/problems/longest-increasing-subsequence/description/
#
# algorithms
# Medium (41.61%)
# Likes:    3250
# Dislikes: 74
# Total Accepted:    283.4K
# Total Submissions: 680K
# Testcase Example:  '[10,9,2,5,3,7,101,18]'
#
# Given an unsorted array of integers, find the length of longest increasing
# subsequence.
# 
# Example:
# 
# 
# Input: [10,9,2,5,3,7,101,18]
# Output: 4 
# Explanation: The longest increasing subsequence is [2,3,7,101], therefore the
# length is 4. 
# 
# Note: 
# 
# 
# There may be more than one LIS combination, it is only necessary for you to
# return the length.
# Your algorithm should run in O(n^2) complexity.
# 
# 
# Follow up: Could you improve it to O(n log n) time complexity?
# 
#

# @lc code=start
class Solution(object):
    def lengthOfLIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # if not nums:
        #     return 0 

        # dp = [1 for i in range(len(nums))]

        # for i in range(1, len(nums)):
        #     for j in range(i-1, -1, -1):
        #         if nums[i] > nums[j]:
        #             dp[i] = max(dp[i], dp[j]+1)
        # return max(dp)


        # tails is an array storing the smallest tail of all increasing subsequences with length i+1 in tails[i].

        # (1) if x is larger than all tails, append it, increase the size by 1
        # (2) if tails[i-1] < x <= tails[i], update tails[i]

        tails = [0] * len(nums)
        
        size = 0
        for num in nums:
            l, r = 0, size
        
            while l < r:
                m = (l + r) // 2
                if tails[m] < num:
                    l = m + 1
                else:
                    r = m
            # l 指向比 num 小的位置
            # 替换tail 内元素，在队尾增加元素
            tails[l] = num
            if l == size:
                size += 1
            # size = max(l + 1, size)
        return size
 
        # stack = []
        # for num in nums:
        #     while stack and stack[-1] >= num:
        #         stack.pop()
        #     stack.append(num)
        # return len(stack)

# @lc code=end

sol = Solution()
# nums = [10,9,2,5,3,7,101,18]
nums = [1,3,6,7,9,4,10,5,6]
print(sol.lengthOfLIS(nums))