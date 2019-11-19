#
# @lc app=leetcode id=594 lang=python
#
# [594] Longest Harmonious Subsequence
#
# https://leetcode.com/problems/longest-harmonious-subsequence/description/
#
# algorithms
# Easy (44.79%)
# Likes:    487
# Dislikes: 69
# Total Accepted:    43.6K
# Total Submissions: 97.4K
# Testcase Example:  '[1,3,2,2,5,2,3,7]'
#
# We define a harmounious array as an array where the difference between its
# maximum value and its minimum value is exactly 1.
# 
# Now, given an integer array, you need to find the length of its longest
# harmonious subsequence among all its possible subsequences.
# 
# Example 1:
# 
# 
# Input: [1,3,2,2,5,2,3,7]
# Output: 5
# Explanation: The longest harmonious subsequence is [3,2,2,2,3].
# 
# 
# 
# 
# Note: The length of the input array will not exceed 20,000.
# 
#

# @lc code=start
class Solution(object):
    def findLHS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        hash_dict = {}

        # import collections 
        # count = collections.Counter(nums)
        for num in nums:
            hash_dict[num] = hash_dict.get(num, 0) + 1
        
        ans = 0
        for num in hash_dict:
            if num+1 in hash_dict:
                ans = max(ans, hash_dict[num] + hash_dict[num+1])
        return ans

        
# @lc code=end

sol = Solution()
nums =[1,1,1,1]
print(sol.findLHS(nums))