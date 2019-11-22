#
# @lc app=leetcode id=697 lang=python
#
# [697] Degree of an Array
#
# https://leetcode.com/problems/degree-of-an-array/description/
#
# algorithms
# Easy (51.94%)
# Likes:    629
# Dislikes: 563
# Total Accepted:    64.3K
# Total Submissions: 123.3K
# Testcase Example:  '[1,2,2,3,1]'
#
# Given a non-empty array of non-negative integers nums, the degree of this
# array is defined as the maximum frequency of any one of its elements.
# Your task is to find the smallest possible length of a (contiguous) subarray
# of nums, that has the same degree as nums.
# 
# Example 1:
# 
# Input: [1, 2, 2, 3, 1]
# Output: 2
# Explanation: 
# The input array has a degree of 2 because both elements 1 and 2 appear twice.
# Of the subarrays that have the same degree:
# [1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
# The shortest length is 2. So return 2.
# 
# 
# 
# 
# Example 2:
# 
# Input: [1,2,2,3,1,4,2]
# Output: 6
# 
# 
# 
# Note:
# nums.length will be between 1 and 50,000.
# nums[i] will be an integer between 0 and 49,999.
# 
#

# @lc code=start
class Solution(object):
    def findShortestSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # hash_dict = {}
        # for num in nums:
        #     hash_dict[num] = hash_dict.get(num, 0) + 1

        # hash_dict = {v:k for k, v in hash_dict.items()}            
        # mode = hash_dict[max(hash_dict)]

        # res = []
        # for i in range(len(nums)):
        #     if nums[i] == mode:
        #         res.append(i)
        # return res[-1] - res[0] + 1

        first, count = {}, {}
        degree = 0
        res = 0
        for i in range(len(nums)):
            num = nums[i]
            # first[num] = i 
            first.setdefault(num, i)
            count[num] = count.get(num, 0) + 1

            if count[num] > degree:
                degree = count[num]
                ans = i - first[num] + 1
            elif count[num] == degree:
                ans = min(ans, i-first[num]+1)  
        return ans

# @lc code=end

sol = Solution()
# nums = [1,2,2,3,1,4,2]
nums =[1,3,2,2,3,1]

print(sol.findShortestSubArray(nums))