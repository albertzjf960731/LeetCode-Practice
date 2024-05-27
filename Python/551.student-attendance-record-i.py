#
# @lc app=leetcode id=551 lang=python
#
# [551] Student Attendance Record I
#
# https://leetcode.com/problems/student-attendance-record-i/description/
#
# algorithms
# Easy (46.20%)
# Likes:    188
# Dislikes: 697
# Total Accepted:    65.5K
# Total Submissions: 141.8K
# Testcase Example:  '"PPALLP"'
#
# You are given a string representing an attendance record for a student. The
# record only contains the following three characters:
# 
# 
# 
# 'A' : Absent. 
# 'L' : Late.
# ⁠'P' : Present. 
# 
# 
# 
# 
# A student could be rewarded if his attendance record doesn't contain more
# than one 'A' (absent) or more than two continuous 'L' (late).    
# 
# You need to return whether the student could be rewarded according to his
# attendance record.
# 
# Example 1:
# 
# Input: "PPALLP"
# Output: True
# 
# 
# 
# Example 2:
# 
# Input: "PPALLL"
# Output: False
# 
# 
# 
# 
# 
#

# @lc code=start
class Solution(object):
    def checkRecord(self, s):
        """
        :type s: str
        :rtype: bool
        """
        # return s.count('A') <= 1 and 'LLL' not in s
        a, l = 0, 0
        for c in s:
            if c == 'A':
                a += 1
            if c == 'L':
                l += 1
            else:
                l = 0
            if a > 1 or l > 2:
                return False
        return True

# @lc code=end

