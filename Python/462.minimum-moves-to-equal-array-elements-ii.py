#
# @lc app=leetcode id=462 lang=python
#
# [462] Minimum Moves to Equal Array Elements II
#
# https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/description/
#
# algorithms
# Medium (52.84%)
# Likes:    402
# Dislikes: 35
# Total Accepted:    39.6K
# Total Submissions: 74.8K
# Testcase Example:  '[1,2,3]'
#
# Given a non-empty integer array, find the minimum number of moves required to
# make all array elements equal, where a move is incrementing a selected
# element by 1 or decrementing a selected element by 1.
# 
# You may assume the array's length is at most 10,000.
# 
# Example:
# 
# Input:
# [1,2,3]
# 
# Output:
# 2
# 
# Explanation:
# Only two moves are needed (remember each move increments or decrements one
# element):
# 
# [1,2,3]  =>  [2,2,3]  =>  [2,2,2]
# 
# 
#

# @lc code=start
class Solution(object):
    def minMoves2(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        # 这是个典型的相遇问题，移动距离最小的方式是所有元素都移动到中位数。理由如下：

        # 设 m 为中位数。a 和 b 是 m 两边的两个元素，且 b > a。要使 a 和 b 相等，它们总共移动的次数为 b - a，这个值等于 (b - m) + (m - a)，也就是把这两个数移动到中位数的移动次数。

        # 设数组长度为 N，则可以找到 N/2 对 a 和 b 的组合，使它们都移动到 m 的位置。


        nums.sort()

        # m = nums[len(nums) // 2]
    
        # ans = 0
        # for nums in nums:
        #     ans += abs(nums-m)
        # return ans 

        ans = 0
        l, r = 0, len(nums)-1
        while l<=r:
            ans += nums[r] -nums[l]
            l+=1
            r-=1
        return ans 
        
    #     meidan = self.findKthSmallest(nums, len(nums)//2+1) 
    #     ans = 0  
    #     for num in nums:
    #         ans += abs(num-meidan)
    #     return ans 

    # def findKthSmallest(self, nums, k):
    #     l, r = 0, len(nums)-1

    #     while l<=r:
    #         pos = self.partition(nums, l, r)

    #         if pos+1==k:
    #             return nums[pos]
    #         elif pos+1<k:
    #             l = pos+1
    #         else:
    #             r = pos-1
    
    # # choose the right-most element as pivot   
    # def partition(self, nums, l, r):
    #     pos = l

    #     while l<r:
    #         if nums[l] < nums[r]:
    #             nums[l], nums[pos] = nums[pos], nums[l]
    #             pos += 1
    #         l += 1

    #     nums[pos], nums[r] = nums[r], nums[pos]
    #     return pos


# @lc code=end

sol = Solution()
print(sol.findKthSmallest(nums, len(nums)//2+1))