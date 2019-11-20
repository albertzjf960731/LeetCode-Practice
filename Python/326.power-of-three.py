#
# @lc app=leetcode id=326 lang=python
#
# [326] Power of Three
#
# https://leetcode.com/problems/power-of-three/description/
#
# algorithms
# Easy (41.88%)
# Likes:    353
# Dislikes: 1225
# Total Accepted:    213K
# Total Submissions: 508.7K
# Testcase Example:  '27'
#
# Given an integer, write a function to determine if it is a power of three.
# 
# Example 1:
# 
# 
# Input: 27
# Output: true
# 
# 
# Example 2:
# 
# 
# Input: 0
# Output: false
# 
# Example 3:
# 
# 
# Input: 9
# Output: true
# 
# Example 4:
# 
# 
# Input: 45
# Output: false
# 
# Follow up:
# Could you do it without using any loop / recursion?
#

# @lc code=start
class Solution(object):
    def isPowerOfThree(self, n):
        """
        :type n: int
        :rtype: bool
        """
        # if n <= 0:
        #     return False
        # while n > 1:
        #     if n % 3 != 0:
        #         return False
        #     n //= 3
        # return True
        
        # # power_list: 3^0, 3^1, ..., 3^19
        # power_list = [1, 3, 9, 27, 81, 243, 729, 2187, 6561, 19683, 59049, 177147, 531441, 1594323, 4782969, 14348907, 43046721, 129140163, 387420489, 1162261467]
        # return n in power_list

        return n > 0 and 1162261467 % n == 0

        
# @lc code=end
sol = Solution()
num = 27
print(sol.isPowerOfThree(27))
