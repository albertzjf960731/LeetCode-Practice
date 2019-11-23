#
# @lc app=leetcode id=128 lang=python
#
# [128] Longest Consecutive Sequence
#
# https://leetcode.com/problems/longest-consecutive-sequence/description/
#
# algorithms
# Hard (43.05%)
# Likes:    2322
# Dislikes: 133
# Total Accepted:    241.1K
# Total Submissions: 559.5K
# Testcase Example:  '[100,4,200,1,3,2]'
#
# Given an unsorted array of integers, find the length of the longest
# consecutive elements sequence.
# 
# Your algorithm should run in O(n) complexity.
# 
# Example:
# 
# 
# Input: [100, 4, 200, 1, 3, 2]
# Output: 4
# Explanation: The longest consecutive elements sequence is [1, 2, 3, 4].
# Therefore its length is 4.
# 
# 
#

# @lc code=start
class Solution(object):
    def longestConsecutive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # if not nums:
        #     return 0

        # nums.sort()
        # ans = 1
        # temp = 1
        # for i in range(1, len(nums)):
        #     if nums[i] == nums[i-1]:
        #         continue
        #     if nums[i]-1 == nums[i-1]:
        #         temp += 1
        #     else:
        #         ans = max(ans, temp)
        #         temp = 1
        # ans = max(ans, temp)
        # return ans 


        if not nums:
            return 0

        hash_set = set(nums)

        ans = 1
        for num in nums:
            if num-1 not in hash_set:
                count = 0
                while num in hash_set:
                    count += 1
                    num += 1
                ans = max(ans, count)
            # hash_set.remove(num)
        return ans 
        
# @lc code=end

sol = Solution()
nums = [0, -1]
print(sol.longestConsecutive(nums))