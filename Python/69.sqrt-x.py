#
# @lc app=leetcode id=69 lang=python
#
# [69] Sqrt(x)
#
# https://leetcode.com/problems/sqrtx/description/
#
# algorithms
# Easy (32.34%)
# Likes:    932
# Dislikes: 1571
# Total Accepted:    435.4K
# Total Submissions: 1.3M
# Testcase Example:  '4'
#
# Implement int sqrt(int x).
# 
# Compute and return the square root of x, where x is guaranteed to be a
# non-negative integer.
# 
# Since the return type is an integer, the decimal digits are truncated and
# only the integer part of the result is returned.
# 
# Example 1:
# 
# 
# Input: 4
# Output: 2
# 
# 
# Example 2:
# 
# 
# Input: 8
# Output: 2
# Explanation: The square root of 8 is 2.82842..., and since 
# the decimal part is truncated, 2 is returned.
# 
# 
#

# @lc code=start
class Solution(object):
    def mySqrt(self, x):
        """
        :type x: int
        :rtype: int
        """
        # num = x // 2
        # if num * num <= x and x < (num+1)*(num+1):
        #     return num 
        # else:
        #     num += 1
        
        # 在循环条件为 l <= h 并且循环退出时，h 总是比 l 小 1，也就是说 h = 2，l = 3，因此最后的返回值应该为 h 而不是 l
        low, high = 1, x
        while low <= high:
            mid = (low + high) // 2
            div = x // mid 

            if div == mid:
                return mid
            elif mid < div:
                low = mid + 1
            else:
                high = mid - 1
        return high
# @lc code=end

sol = Solution()
print(sol.mySqrt(8))