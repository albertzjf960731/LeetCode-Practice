#
# @lc app=leetcode id=97 lang=python
#
# [97] Interleaving String
#
# https://leetcode.com/problems/interleaving-string/description/
#
# algorithms
# Hard (29.29%)
# Likes:    981
# Dislikes: 55
# Total Accepted:    127.1K
# Total Submissions: 433.1K
# Testcase Example:  '"aabcc"\n"dbbca"\n"aadbbcbcac"'
#
# Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and
# s2.
# 
# Example 1:
# 
# 
# Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
# Output: true
# 
# 
# Example 2:
# 
# 
# Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
# Output: false
# 
# 
#

# @lc code=start
class Solution(object):
    def isInterleave(self, s1, s2, s3):
        """
        :type s1: str
        :type s2: str
        :type s3: str
        :rtype: bool
        """
        # hash_dict1 = dict()
        # for c in s1+s2:
        #     hash_dict1[c] = hash_dict1.get(c, 0)+1
        
        # hash_dict2 = dict()
        # for c in s3:
        #     hash_dict2[c] = hash_dict2.get(c, 0)+1
        
        # return hash_dict1 == hash_dict2
        

        # l1, l2, l3 = len(s1), len(s2), len(s3)
        # if l1+l2 != l3:
        #     return False
        
        # dp = [[False for _ in range(l2+1)] for _ in range(l1+1)]

        # dp[0][0] = True
        # for i in range(1, l1+1):
        #     dp[i][0] = dp[i-1][0] and s1[i-1] == s3[i-1]
        # for j in range(1, l2+1):
        #     dp[0][j] = dp[0][j-1] and s2[j-1] == s3[j-1]

        # for i in range(1, l1+1):
        #     for j in range(1, l2+1):
        #         dp[i][j] = (dp[i-1][j] and s1[i-1] == s3[i-1+j]) or \
        #                    (dp[i][j-1] and s2[j-1] == s3[i-1+j])
        # return dp[-1][-1]



        l1, l2, l3 = len(s1), len(s2), len(s3)
        if l1+l2 != l3:
            return False
        
        dp = [False for _ in range(l2+1)] 

        dp[0] = True
        for j in range(1, l2+1):
            dp[j] = dp[j-1] and s2[j-1] == s3[j-1]

        for i in range(1, l1+1):
            dp[0] = dp[0] and s1[i-1] == s3[i-1]

            for j in range(1, l2+1):
                dp[j] = (dp[j] and s1[i-1] == s3[i-1+j]) or \
                        (dp[j-1] and s2[j-1] == s3[i-1+j])

        return dp[-1]


        
# @lc code=end

sol = Solution()
s1 = "aabcc"
s2 = "dbbca"
s3 = "aadbbcbcac"
print(sol.isInterleave(s1, s2, s3))