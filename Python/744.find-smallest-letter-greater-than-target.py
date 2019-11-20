#
# @lc app=leetcode id=744 lang=python
#
# [744] Find Smallest Letter Greater Than Target
#
# https://leetcode.com/problems/find-smallest-letter-greater-than-target/description/
#
# algorithms
# Easy (44.60%)
# Likes:    279
# Dislikes: 404
# Total Accepted:    53.2K
# Total Submissions: 119.3K
# Testcase Example:  '["c","f","j"]\n"a"'
#
# 
# Given a list of sorted characters letters containing only lowercase letters,
# and given a target letter target, find the smallest element in the list that
# is larger than the given target.
# 
# Letters also wrap around.  For example, if the target is target = 'z' and
# letters = ['a', 'b'], the answer is 'a'.
# 
# 
# Examples:
# 
# Input:
# letters = ["c", "f", "j"]
# target = "a"
# Output: "c"
# 
# Input:
# letters = ["c", "f", "j"]
# target = "c"
# Output: "f"
# 
# Input:
# letters = ["c", "f", "j"]
# target = "d"
# Output: "f"
# 
# Input:
# letters = ["c", "f", "j"]
# target = "g"
# Output: "j"
# 
# Input:
# letters = ["c", "f", "j"]
# target = "j"
# Output: "c"
# 
# Input:
# letters = ["c", "f", "j"]
# target = "k"
# Output: "c"
# 
# 
# 
# Note:
# 
# letters has a length in range [2, 10000].
# letters consists of lowercase letters, and contains at least 2 unique
# letters.
# target is a lowercase letter.
# 
# 
#

# @lc code=start
class Solution(object):
    def nextGreatestLetter(self, letters, target):
        """
        :type letters: List[str]
        :type target: str
        :rtype: str
        """

        # letters = list(set(letters))
        # l, r = 0, len(letters)-1
        # while l<=r:
        #     mid = (l+r) // 2
        #     if letters[mid] == target:
        #         return letters[(mid+1)%len(letters)]
        #     elif letters[mid] > target:
        #         if mid>=1 and letters[mid-1] <= target:
        #             return letters[mid]
        #         if mid == 0:
        #             return letters[mid]
        #         else:
        #             r = mid-1
        #     else:
        #         if mid<len(letters)-1 and letters[mid+1] > target:
        #             return letters[mid+1]
        #         # elif letters[mid+1] == target:
        #         #     return letters[(mid+2)%len(letters)]
        #         else:
        #             l = mid + 1
            
        # return letters[l%len(letters)]

        # for ch in letters:
        #     if ch > target:
        #         return ch 
        # return letters[0]

        n = len(letters)
        l, r = 0, n-1
        while l<=r:
            m = (l+r) // 2
            if letters[m] <= target:
                l = m+1 
            else:
                r = m-1
        return letters[l] if l<n else letters[0]

# @lc code=end

sol = Solution()
letters =["c","f","j"]
target = 'a'
print(sol.nextGreatestLetter(letters, target))