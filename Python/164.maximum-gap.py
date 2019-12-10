#
# @lc app=leetcode id=164 lang=python3
#
# [164] Maximum Gap
#
# https://leetcode.com/problems/maximum-gap/description/
#
# algorithms
# Hard (33.63%)
# Likes:    614
# Dislikes: 146
# Total Accepted:    77.3K
# Total Submissions: 229.5K
# Testcase Example:  '[3,6,9,1]'
#
# Given an unsorted array, find the maximum difference between the successive
# elements in its sorted form.
# 
# Return 0 if the array contains less than 2 elements.
# 
# Example 1:
# 
# 
# Input: [3,6,9,1]
# Output: 3
# Explanation: The sorted form of the array is [1,3,6,9], either
# (3,6) or (6,9) has the maximum difference 3.
# 
# Example 2:
# 
# 
# Input: [10]
# Output: 0
# Explanation: The array contains less than 2 elements, therefore return 0.
# 
# Note:
# 
# 
# You may assume all elements in the array are non-negative integers and fit in
# the 32-bit signed integer range.
# Try to solve it in linear time/space.
# 
# 
#
# @lc code=start
import math 
class Solution(object):
    def maximumGap(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # 对于求最大Gap的题目，即使是大数据的题目，也可以使用分桶的方法来做
        # 桶的数量必须大于元素的数量，这样一来，将所有元素放入对应的桶中，必然存在至少一个桶为空
        # 最大的gap必然出现在连续的空桶两侧的两个桶内的元素之间，而不会出现在某个同内的元素之间（因为桶内元素间的Gap最大超不过桶宽，而桶间元素的差值可以超过这一值）
        # 随后我们遍历一遍所有的桶，若存在某一个区间内的桶均为空，则找到该区间左侧第一个非空桶的最大值，以及该区间右侧第一个非空桶的最小值，这两个值的差即是最大Gap的一个候选值

        ans = 0
        if not nums or len(nums)==1:
            return ans 

        num_size = len(nums)    
        max_num = max(nums)
        min_num = min(nums)

        #  MaxGap >= ⌈(max−min)/(n−2)⌉ > max(1, int(math.ceil((B - A) / (N - 1))))
        # 所以我们依据这个average_gap将乱序数组划分为n-2个桶, MaxGap便只可能在相邻的两个桶, 前一个桶的最大值与后一个桶的最小值的差值中产生.    

        bucket_size = max(1, int(math.ceil((max_num-min_num)/(num_size-1))))
        bucket_num = (max_num-min_num)//bucket_size + 1
        buckets = [None] * bucket_num

        for num in nums:
            idx = (num-min_num)//bucket_size
            if buckets[idx] is None:
                buckets[idx] = {'min': num, 'max': num}
            else:
                buckets[idx]['min'] = min(num, buckets[idx]['min'])
                buckets[idx]['max'] = max(num, buckets[idx]['max'])
        
        pre = min_num
        ans = 0
        for bucket in buckets:
            if bucket:
                ans = max(ans, bucket['min']-pre)
                pre = bucket['max']
        return max(ans, max_num-pre)
        
        # ans = 0
        # if not nums or len(nums)==1:
        #     return ans

        # sorted(nums)
        # for i in range(1, len(nums)):
        #     ans = max(ans, nums[i]-nums[i-1])
        # return ans 

    #     # radix sort
    #     if not nums or len(nums)==1:
    #         return 0
        
    #     self.radix_sort(nums)
       
    #     ans = 0
    #     for i in range(1, len(nums)):
    #         ans = max(ans, nums[i]-nums[i-1])
    #     return ans 

    # def radix_sort(self, nums):
        
    #     radix = 10
    #     buckets = [[] for i in range(radix)]
    #     exp = 1

    #     max_num = max(nums)
    #     while max_num/exp > 0:
    #         for num in nums:
    #             buckets[(num//exp)%radix].append(num)
            
    #         nums = []
    #         for bucket in buckets:
    #             nums.extend(bucket) 
    #         buckets = [[] for i in range(radix)]
    #         exp *= 10

        
# @lc code=end

sol = Solution()
# nums =[100,3,2,1]
nums = [1, 1000000]
print(sol.maximumGap(nums))