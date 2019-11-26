#
# @lc app=leetcode.cn id=12 lang=python
#
# [12] Integer to Roman
#

# @lc code=start
class Solution(object):
    def intToRoman(self, num):
        """
        :type num: int
        :rtype: str
        """
        roman_symbol = {1000: 'M', 900: 'CM', 500: 'D', 400: 'CD', 100: 'C', 90: 'XC', 50: 'L', 40: 'XL', 10: 'X', 9: 'IX', 5: 'V', 4: 'IV', 1: 'I'}
            
        ans = ''
        for n in roman_symbol:
            while num >= n:
                num -= n 
                ans += roman_symbol[n]
        return ans

        
# @lc code=end

sol = Solution()
num = 4
print(sol.intToRoman(num))