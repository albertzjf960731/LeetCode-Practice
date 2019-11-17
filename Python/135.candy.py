#
# @lc app=leetcode id=135 lang=python
#
# [135] Candy
#
# https://leetcode.com/problems/candy/description/
#
# algorithms
# Hard (29.60%)
# Likes:    633
# Dislikes: 133
# Total Accepted:    113.4K
# Total Submissions: 382.8K
# Testcase Example:  '[1,0,2]'
#
# There are N children standing in a line. Each child is assigned a rating
# value.
# 
# You are giving candies to these children subjected to the following
# requirements:
# 
# 
# Each child must have at least one candy.
# Children with a higher rating get more candies than their neighbors.
# 
# 
# What is the minimum candies you must give?
# 
# Example 1:
# 
# 
# Input: [1,0,2]
# Output: 5
# Explanation: You can allocate to the first, second and third child with 2, 1,
# 2 candies respectively.
# 
# 
# Example 2:
# 
# 
# Input: [1,2,2]
# Output: 4
# Explanation: You can allocate to the first, second and third child with 1, 2,
# 1 candies respectively.
# ⁠            The third child gets 1 candy because it satisfies the above two
# conditions.
# 
# 
#

# @lc code=start
class Solution(object):
    def candy(self, ratings):
        """
        :type ratings: List[int]
        :rtype: int
        """
        
        candys = [1] * len(ratings)
        for i in range(1, len(ratings)):
            if ratings[i] == ratings[i-1]:
                pass 
            if ratings[i] > ratings[i-1] and candys[i] <= candys[i-1]:
                    candys[i] = candys[i-1] + 1
                    
        for i in range(len(ratings)-1, 0, -1):
            if ratings[i-1] > ratings[i] and candys[i-1] <= candys[i]:
                    candys[i-1] = candys[i] + 1
        
        # for i in range(len(ratings)-2, -1, -1):
        #     if ratings[i] == ratings[i-1]:
        #         pass 
        #     if ratings[i] > ratings[i+1]:
        #         while candys[i] <= candys[i+1]:
        #             candys[i] += 1
        #     if ratings[i+1] > ratings[i] :
        #         while candys[i+1] <= candys[i]:
        #             candys[i+1] += 1
        return sum(candys)



# @lc code=end

sol = Solution()
ratings = [1,0, 2]

print(sol.candy(ratings))