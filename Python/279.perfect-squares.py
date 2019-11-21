#
# @lc app=leetcode id=279 lang=python
#
# [279] Perfect Squares
#
# https://leetcode.com/problems/perfect-squares/description/
#
# algorithms
# Medium (43.36%)
# Likes:    1856
# Dislikes: 156
# Total Accepted:    222.3K
# Total Submissions: 511.4K
# Testcase Example:  '12'
#
# Given a positive integer n, find the least number of perfect square numbers
# (for example, 1, 4, 9, 16, ...) which sum to n.
# 
# Example 1:
# 
# 
# Input: n = 12
# Output: 3 
# Explanation: 12 = 4 + 4 + 4.
# 
# Example 2:
# 
# 
# Input: n = 13
# Output: 2
# Explanation: 13 = 4 + 9.
#

# @lc code=start
class Solution(object):
    def numSquares(self, n):
        """
        :type n: int
        :rtype: int
        """
        # sum_set = []
        # for i in range(1, int(n**0.5)+1):
        #     sum_set.append(i*i)

        # ans = 1
        # for item1 in sum_set:
        #     ans += 1
        #     for item2 in sum_set:
        #         sum_set.append(item1+item2)
        #         if n in sum_set:
        #             return ans 

        # dp[n] = Min{ dp[n - i*i] + 1 },  n - i*i >=0 && i >= 1
        dp = [0] * (n+1)
        for i in range(1, n+1):
            cur_min = n
            j = 1
            while j*j <= i:
                cur_min = min(cur_min, dp[i-j*j] + 1)
                j += 1
            dp[i] = cur_min
        return dp[-1]


        # temp 暂存 方便计数
        # if n < 2:
        #     return n 
        
        # square_set = []
        # i = 1
        # while i*i<=n:
        #     square_set.append(i*i)
        #     i += 1
        
        # ans = 0
        # to_check = {n}
        # while to_check:
        #     ans += 1
        #     temp = set()
        #     for i in to_check:
        #         for j in square_set:
        #             if i == j:
        #                 return ans 
        #             elif i<j:
        #                 break
        #             else:
        #                 temp.add(i-j)
        #     to_check = temp
        
        # return ans 


        if n < 2:
            return n 
        
        square_set = []
        i = 1
        while i*i<=n:
            square_set.append(i*i)
            i += 1
        
        import collections
        queue = collections.deque([n])

        visited = [False] * (n+1)
        visited[n] = True

        ans = 0
        while queue:
            queue_size = len(queue)
            ans += 1
            
            while queue_size>0:

                cur = queue.popleft()
                for square in square_set:
                    left = cur -square
                    if left<0:
                        break
                    elif left == 0:
                        return ans 
                    elif visited[left]:
                        continue
                    else:
                        visited[left] = True
                        queue.append(left)
 
                queue_size -= 1
        return n 



# @lc code=end
sol = Solution()
n = 12
print(sol.numSquares(n))
