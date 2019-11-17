#
# @lc app=leetcode id=3 lang=python
#
# [3] Longest Substring Without Repeating Characters
#
# https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
#
# algorithms
# Medium (29.03%)
# Likes:    6759
# Dislikes: 398
# Total Accepted:    1.2M
# Total Submissions: 4M
# Testcase Example:  '"abcabcbb"'
#
# Given a string, find the length of the longest substring without repeating
# characters.
# 
# 
# Example 1:
# 
# 
# Input: "abcabcbb"
# Output: 3 
# Explanation: The answer is "abc", with the length of 3. 
# 
# 
# 
# Example 2:
# 
# 
# Input: "bbbbb"
# Output: 1
# Explanation: The answer is "b", with the length of 1.
# 
# 
# 
# Example 3:
# 
# 
# Input: "pwwkew"
# Output: 3
# Explanation: The answer is "wke", with the length of 3. 
# ⁠            Note that the answer must be a substring, "pwke" is a
# subsequence and not a substring.
# 
# 
# 
# 
# 
#

# @lc code=start
class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
    #     ans = 0
    #     for i in range(len(s)):
    #         for j in range(i+1, len(s)+1):
    #             if self.is_unique(s[i: j]):
    #                 ans = max(ans, j - i)
    #     return ans 
    
    # def is_unique(self, s):
    #     char_set = set()
    #     for char in s:
    #         if not char in char_set:
    #             char_set.add(char)
    #         else:
    #             return False 
    #     return True 

        # i, j = 0, 0
        # char_set = set()
        # ans = 0
        # while (i < len(s) and j < len(s)):
        #     if not s[j] in char_set:
        #         char_set.add(s[j])
        #         j += 1 
        #         ans = max(ans, j-i)
        #     else:
        #         char_set.remove(s[i])
        #         i += 1
        # return ans

        ans = 0
        i = 0
        char_dict = {}
        # while (i < len(s) and j < len(s)):
        for j in range(len(s)):
            if s[j] in char_dict:
                i = max(char_dict[s[j]], i)
            ans = max(ans, j - i + 1)
            char_dict[s[j]] = j + 1 # 修改
        return ans 

# @lc code=end

sol = Solution()
s = "tmmzuxt"
print(sol.lengthOfLongestSubstring(s))