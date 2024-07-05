#
# @lc app=leetcode id=718 lang=python3
#
# [718] Maximum Length of Repeated Subarray
#
# https://leetcode.com/problems/maximum-length-of-repeated-subarray/description/
#
# algorithms
# Medium (50.95%)
# Likes:    6771
# Dislikes: 167
# Total Accepted:    302.4K
# Total Submissions: 593.6K
# Testcase Example:  '[1,2,3,2,1]\n[3,2,1,4,7]'
#
# Given two integer arrays nums1 and nums2, return the maximum length of a
# subarray that appears in both arrays.
# 
# 
# Example 1:
# 
# 
# Input: nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]
# Output: 3
# Explanation: The repeated subarray with maximum length is [3,2,1].
# 
# 
# Example 2:
# 
# 
# Input: nums1 = [0,0,0,0,0], nums2 = [0,0,0,0,0]
# Output: 5
# Explanation: The repeated subarray with maximum length is [0,0,0,0,0].
# 
# 
# 
# Constraints:
# 
# 
# 1 <= nums1.length, nums2.length <= 1000
# 0 <= nums1[i], nums2[i] <= 100
# 
# 
#

# @lc code=start
class Solution:
    def findLength(self, nums1: List[int], nums2: List[int]) -> int:
        n1, n2 = len(nums1), len(nums2)
        dp = [[0 for j in range(n2+1)] for i in range(n1+1)]

        ans = 0
        for i in range(n1):
            for j in range(n2):
                if nums1[i] == nums2[j]:
                    dp[i+1][j+1] = dp[i][j] + 1
                    ans = max(ans, dp[i+1][j+1])
        return ans
# @lc code=end

