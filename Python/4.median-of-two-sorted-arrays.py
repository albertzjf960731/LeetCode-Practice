#
# @lc app=leetcode id=4 lang=python
#
# [4] Median of Two Sorted Arrays
#
# https://leetcode.com/problems/median-of-two-sorted-arrays/description/
#
# algorithms
# Hard (27.62%)
# Likes:    5275
# Dislikes: 770
# Total Accepted:    532.9K
# Total Submissions: 1.9M
# Testcase Example:  '[1,3]\n[2]'
#
# There are two sorted arrays nums1 and nums2 of size m and n respectively.
# 
# Find the median of the two sorted arrays. The overall run time complexity
# should be O(log (m+n)).
# 
# You may assume nums1 and nums2 cannot be both empty.
# 
# Example 1:
# 
# 
# nums1 = [1, 3]
# nums2 = [2]
# 
# The median is 2.0
# 
# 
# Example 2:
# 
# 
# nums1 = [1, 2]
# nums2 = [3, 4]
# 
# The median is (2 + 3)/2 = 2.5
# 
# 
#

# @lc code=start
class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        # 简单把两个数组归并后找中位数，但需要用到额外的空间

        # nums3 = nums1 + nums2
        # nums3.sort()

        # n = len(nums3)
        # if n % 2 == 0:
        #     return (nums3[n//2] + nums3[n//2-1]) / 2
        # else:
        #     return nums3[n//2]
        
        # n = len(nums1)
        # m = len(nums2)

        # left, right = -1, -1
        # i, j = 0, 0

        # for _ in range((n+m)//2+1):

        #     left = right
        #     if i < n and (j>=m or nums1[i]<nums2[j]):
        #         right = nums1[i]
        #         i += 1
        #     else:
        #         right = nums2[j]
        #         j += 1

        # if (n+m) & 1 == 0:
        #     return (left + right) / 2
        # else: 
        #     return right


        l = len(nums1) + len(nums2)
        if l & 1 == 0:
            return (self.kth(nums1, nums2, l//2) + self.kth(nums1, nums2, l//2-1))/2
        else:
            return self.kth(nums1, nums2, l//2)  
            
    def kth(self, nums1, nums2, k):
        if not nums1:
            return nums2[k]
        if not nums2:
            return nums1[k]
        
        i, j = len(nums1)//2, len(nums2)//2
        m1, m2 = nums1[i], nums2[j]

        if i+j <k:
            if m1>m2:
                return self.kth(nums1, nums2[j+1:], k-j-1)
            else:
                return self.kth(nums1[i+1:], nums2, k-i-1)
        else:
            if m1>m2:
                return self.kth(nums1[:i], nums2, k)
            else:
                return self.kth(nums1, nums2[:j], k) 

# @lc code=end

sol = Solution()
nums1 = [1, 2]  
nums2 = [3, 4]
print(sol.findMedianSortedArrays(nums1, nums2))