#
# @lc app=leetcode id=605 lang=python
#
# [605] Can Place Flowers
#
# https://leetcode.com/problems/can-place-flowers/description/
#
# algorithms
# Easy (31.44%)
# Likes:    574
# Dislikes: 300
# Total Accepted:    77.2K
# Total Submissions: 245.3K
# Testcase Example:  '[1,0,0,0,1]\n1'
#
# Suppose you have a long flowerbed in which some of the plots are planted and
# some are not. However, flowers cannot be planted in adjacent plots - they
# would compete for water and both would die.
# 
# Given a flowerbed (represented as an array containing 0 and 1, where 0 means
# empty and 1 means not empty), and a number n, return if n new flowers can be
# planted in it without violating the no-adjacent-flowers rule.
# 
# Example 1:
# 
# Input: flowerbed = [1,0,0,0,1], n = 1
# Output: True
# 
# 
# 
# Example 2:
# 
# Input: flowerbed = [1,0,0,0,1], n = 2
# Output: False
# 
# 
# 
# Note:
# 
# The input array won't violate no-adjacent-flowers rule.
# The input array size is in the range of [1, 20000].
# n is a non-negative integer which won't exceed the input array size.
# 
# 
#

# @lc code=start
class Solution(object):
    def canPlaceFlowers(self, flowerbed, n):
        """
        :type flowerbed: List[int]
        :type n: int
        :rtype: bool
        """
        # ans = 0
        # i, j = 0, 0
        # flowerbed.insert(0, 0)
        # flowerbed.append(0)
        # while i < len(flowerbed) and j < len(flowerbed):
        #     while i < len(flowerbed) and flowerbed[i] != 0:
        #         i += 1
        #     j = i
        #     while j < len(flowerbed) and flowerbed[j] == 0:
        #         j += 1
            
        #     if i < len(flowerbed) and j <= len(flowerbed):
        #         ans += (j-i-1) // 2
        #     i = j
        # return ans >= n

        # 不要双指针， 用计数器
        ans = 0
        zero = 1 # initial has no left limit
        for slot in flowerbed:
            if slot == 0:
                zero += 1
            else:
                ans += (zero-1)//2
                zero = 0
        ans += zero // 2 
        return ans >= n

# @lc code=end

sol = Solution()
flowerbed = [1,0,0,0,1]
n = 2
print(sol.canPlaceFlowers(flowerbed, n))