#
# @lc app=leetcode id=447 lang=python
#
# [447] Number of Boomerangs
#
# https://leetcode.com/problems/number-of-boomerangs/description/
#
# algorithms
# Easy (50.64%)
# Likes:    331
# Dislikes: 525
# Total Accepted:    60.2K
# Total Submissions: 118.7K
# Testcase Example:  '[[0,0],[1,0],[2,0]]'
#
# Given n points in the plane that are all pairwise distinct, a "boomerang" is
# a tuple of points (i, j, k) such that the distance between i and j equals the
# distance between i and k (the order of the tuple matters).
# 
# Find the number of boomerangs. You may assume that n will be at most 500 and
# coordinates of points are all in the range [-10000, 10000] (inclusive).
# 
# Example:
# 
# 
# Input:
# [[0,0],[1,0],[2,0]]
# 
# Output:
# 2
# 
# Explanation:
# The two boomerangs are [[1,0],[0,0],[2,0]] and [[1,0],[2,0],[0,0]]
# 
# 
# 
# 
#

# @lc code=start
class Solution(object):
    def numberOfBoomerangs(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        ans = 0
        for p in points:
            hash_dict = {}

            for q in points:
                d = (p[0]-q[0])**2 + (p[1]-q[1])**2
                hash_dict[d] = hash_dict.get(d, 0) + 1
            for d in hash_dict:
                ans += hash_dict[d] * (hash_dict[d]-1)

        return ans 

# @lc code=end

sol = Solution()
points = [[0,0],[1,0],[2,0]]
print(sol.numberOfBoomerangs(points))