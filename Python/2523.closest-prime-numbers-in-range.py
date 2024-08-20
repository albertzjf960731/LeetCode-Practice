#
# @lc app=leetcode id=2523 lang=python3
#
# [2523] Closest Prime Numbers in Range
#
# https://leetcode.com/problems/closest-prime-numbers-in-range/description/
#
# algorithms
# Medium (37.55%)
# Likes:    363
# Dislikes: 29
# Total Accepted:    23.6K
# Total Submissions: 62.8K
# Testcase Example:  '10\n19'
#
# Given two positive integers left and right, find the two integers num1 and
# num2 such that:
# 
# 
# left <= num1 < num2 <= right .
# num1 and num2 are both prime numbers.
# num2 - num1 is the minimum amongst all other pairs satisfying the above
# conditions.
# 
# 
# Return the positive integer array ans = [num1, num2]. If there are multiple
# pairs satisfying these conditions, return the one with the minimum num1 value
# or [-1, -1] if such numbers do not exist.
# 
# A number greater than 1 is called prime if it is only divisible by 1 and
# itself.
# 
# 
# Example 1:
# 
# 
# Input: left = 10, right = 19
# Output: [11,13]
# Explanation: The prime numbers between 10 and 19 are 11, 13, 17, and 19.
# The closest gap between any pair is 2, which can be achieved by [11,13] or
# [17,19].
# Since 11 is smaller than 17, we return the first pair.
# 
# 
# Example 2:
# 
# 
# Input: left = 4, right = 6
# Output: [-1,-1]
# Explanation: There exists only one prime number in the given range, so the
# conditions cannot be satisfied.
# 
# 
# 
# Constraints:
# 
# 
# 1 <= left <= right <= 10^6
# 
# 
# 
# .spoilerbutton {display:block; border:dashed; padding: 0px 0px; margin:10px
# 0px; font-size:150%; font-weight: bold; color:#000000; background-color:cyan;
# outline:0; 
# }
# .spoiler {overflow:hidden;}
# .spoiler > div {-webkit-transition: all 0s ease;-moz-transition: margin 0s
# ease;-o-transition: all 0s ease;transition: margin 0s ease;}
# .spoilerbutton[value="Show Message"] + .spoiler > div {margin-top:-500%;}
# .spoilerbutton[value="Hide Message"] + .spoiler {padding:5px;}
# 
# 
#

# @lc code=start
class Solution:
    def closestPrimes(self, left: int, right: int) -> List[int]:
        def is_prime(n):
            if n < 2:
                return False
            for i in range(2, int(n ** 0.5) + 1):
                if n % i == 0:
                    return False
            return True

        primes = []
        for i in range(left, right + 1):
            if not is_prime(i):
                continue
            if primes and i <= primes[-1] + 2: # twin primes or consecutive primes
                return [primes[-1], i]
            primes.append(i)

        min_diff = float('inf')
        ans = [-1, -1]
        for i in range(1, len(primes)):
            diff = primes[i] - primes[i-1]
            if diff < min_diff:
                min_diff = diff
                ans = [primes[i-1], primes[i]]
        return ans
    
# @lc code=end

