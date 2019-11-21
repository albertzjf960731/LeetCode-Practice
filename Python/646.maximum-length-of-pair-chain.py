#
# @lc app=leetcode id=646 lang=python
#
# [646] Maximum Length of Pair Chain
#
# https://leetcode.com/problems/maximum-length-of-pair-chain/description/
#
# algorithms
# Medium (49.84%)
# Likes:    656
# Dislikes: 57
# Total Accepted:    43.9K
# Total Submissions: 87.8K
# Testcase Example:  '[[1,2], [2,3], [3,4]]'
#
# 
# You are given n pairs of numbers. In every pair, the first number is always
# smaller than the second number.
# 
# 
# 
# Now, we define a pair (c, d) can follow another pair (a, b) if and only if b
# < c. Chain of pairs can be formed in this fashion. 
# 
# 
# 
# Given a set of pairs, find the length longest chain which can be formed. You
# needn't use up all the given pairs. You can select pairs in any order.
# 
# 
# 
# Example 1:
# 
# Input: [[1,2], [2,3], [3,4]]
# Output: 2
# Explanation: The longest chain is [1,2] -> [3,4]
# 
# 
# 
# Note:
# 
# The number of given pairs will be in the range [1, 1000].
# 
# 
#

# @lc code=start
class Solution(object):
    def findLongestChain(self, pairs):
        """
        :type pairs: List[List[int]]
        :rtype: int
        """

        # tails = [[0, 0]] * len(pairs)
        
        # size = 0
        # for num in pairs:
        #     l, r = 0, size  
        #     while l < r:
        #         m = (l + r) // 2
        #         if tails[m][1] < num[0]:
        #             l = m + 1
        #         else:
        #             r = m
        #     tails[l] = num
        #     if l == size:
        #         size += 1
        # return size

        # if not pairs:
        #     return 0 

        # pairs.sort(key=lambda x:(x[0]))
        # dp = [1 for i in range(len(pairs))]

        # for i in range(1, len(pairs)):
        #     for j in range(i):
        #         if pairs[j][1] < pairs[i][0]:
        #             dp[i] = max(dp[i], dp[j]+1)
        # return max(dp)

        # 这道题是可以排序的
        if not pairs:
            return 0 

        pairs.sort(key=lambda x:(x[1]))
        count = 1
        # 多设置一个变量
        last_end = pairs[0][1]
        for i in range(1, len(pairs)):
            if pairs[i][0] <= last_end:
                continue
            last_end = pairs[i][1]  
            count += 1
        return count
        
# @lc code=end

sol = Solution()
pairs = [[1,2], [2,3], [3,4]]
print(sol.findLongestChain(pairs))