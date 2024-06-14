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
        # 思路1：
        # 后指针向后滑动以添加新的元素，前指针向后滑动保证滑动窗口内无重复字符
        # 思路2：
        # 维护每个字符最后一次出现的位置，后指针发现一个前面出现过的字符时，前指针可以直接跳到该字符最后出现的位置后面，i = max(i, lastpos[s[j]])，效率更高一些

        # 暴力
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

        # 双指针
        ans = 0
        left, right = 0, 0
        last_seen = {}
        while right < len(s):
            if s[right] in last_seen:
                left = max(left, last_seen[s[right]] + 1)
            ans = max(ans, right - left + 1)
            last_seen[s[right]] = right
            right += 1
        return ans


# @lc code=end

sol = Solution()
# s = "tmmzuxt"
# s = 'pwwkew'
# s = 'abba'
s = ' '
print(sol.lengthOfLongestSubstring(s))