#
# @lc app=leetcode id=168 lang=python
#
# [168] Excel Sheet Column Title
#
# https://leetcode.com/problems/excel-sheet-column-title/description/
#
# algorithms
# Easy (29.78%)
# Likes:    875
# Dislikes: 180
# Total Accepted:    191.1K
# Total Submissions: 640.3K
# Testcase Example:  '1'
#
# Given a positive integer, return its corresponding column title as appear in
# an Excel sheet.
# 
# For example:
# 
# 
# ⁠   1 -> A
# ⁠   2 -> B
# ⁠   3 -> C
# ⁠   ...
# ⁠   26 -> Z
# ⁠   27 -> AA
# ⁠   28 -> AB 
# ⁠   ...
# 
# 
# Example 1:
# 
# 
# Input: 1
# Output: "A"
# 
# 
# Example 2:
# 
# 
# Input: 28
# Output: "AB"
# 
# 
# Example 3:
# 
# 
# Input: 701
# Output: "ZY"
# 
#

# @lc code=start
class Solution(object):
    def convertToTitle(self, num):
        """
        :type n: int
        :rtype: str
        """
        
        char = ['A', 'B', 'C', 'D', 
                'E', 'F', 'G', 'H',
                'I', 'J', 'K', 'L',
                'M', 'N', 'O', 'P',
                'Q', 'R', 'S', 'T', 
                'U', 'V', 'W', 'X',
                'Y', 'Z']
        # char = dict(zip(range(1, 27), char))
        # if num == 0:
        #     return '0'
        # elif num<0:
        #     num = 0xffffffff + 1 + num

        res = ''
        while num:
            res += char[(num-1) % 26]
            num = (num-1) // 26
        return res[::-1]

# @lc code=end

sol = Solution()
num = 27
print(sol.convertToTitle(num))