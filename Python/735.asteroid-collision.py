#
# @lc app=leetcode id=735 lang=python3
#
# [735] Asteroid Collision
#
# https://leetcode.com/problems/asteroid-collision/description/
#
# algorithms
# Medium (44.48%)
# Likes:    7899
# Dislikes: 1068
# Total Accepted:    536K
# Total Submissions: 1.2M
# Testcase Example:  '[5,10,-5]'
#
# We are given an array asteroids of integers representing asteroids in a row.
# 
# For each asteroid, the absolute value represents its size, and the sign
# represents its direction (positive meaning right, negative meaning left).
# Each asteroid moves at the same speed.
# 
# Find out the state of the asteroids after all collisions. If two asteroids
# meet, the smaller one will explode. If both are the same size, both will
# explode. Two asteroids moving in the same direction will never meet.
# 
# 
# Example 1:
# 
# 
# Input: asteroids = [5,10,-5]
# Output: [5,10]
# Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never
# collide.
# 
# 
# Example 2:
# 
# 
# Input: asteroids = [8,-8]
# Output: []
# Explanation: The 8 and -8 collide exploding each other.
# 
# 
# Example 3:
# 
# 
# Input: asteroids = [10,2,-5]
# Output: [10]
# Explanation: The 2 and -5 collide resulting in -5. The 10 and -5 collide
# resulting in 10.
# 
# 
# 
# Constraints:
# 
# 
# 2 <= asteroids.length <= 10^4
# -1000 <= asteroids[i] <= 1000
# asteroids[i] != 0
# 
# 
#

# @lc code=start
class Solution:
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        stack = []
        for a in asteroids:
            while a < 0 and stack and stack[-1] > 0:
                b = stack.pop()
                if a + b == 0:
                    a = 0
                elif a + b > 0:
                    a = 0
                    stack.append(b)
            if a != 0:
                stack.append(a)
        return stack
# @lc code=end

