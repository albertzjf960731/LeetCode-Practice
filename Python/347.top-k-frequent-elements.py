#
# @lc app=leetcode id=347 lang=python
#
# [347] Top K Frequent Elements
#
# https://leetcode.com/problems/top-k-frequent-elements/description/
#
# algorithms
# Medium (57.27%)
# Likes:    2036
# Dislikes: 132
# Total Accepted:    270.9K
# Total Submissions: 471.1K
# Testcase Example:  '[1,1,1,2,2,3]\n2'
#
# Given a non-empty array of integers, return the k most frequent elements.
# 
# Example 1:
# 
# 
# Input: nums = [1,1,1,2,2,3], k = 2
# Output: [1,2]
# 
# 
# 
# Example 2:
# 
# 
# Input: nums = [1], k = 1
# Output: [1]
# 
# 
# Note: 
# 
# 
# You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
# Your algorithm's time complexity must be better than O(n log n), where n is
# the array's size.
# 
# 
#

# @lc code=start
class Solution(object):
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        # count_dict = dict()
        # for num in nums:
        #     if num not in count_dict:
        #         count_dict[num] = 1
        #     else:
        #         count_dict[num] += 1
        
        # temp = sorted(count_dict.items(), key=lambda item:item[1], reverse=True)
         
        # return [item[0] for item in temp[:k]]


        count_dict = dict()
        for num in nums:
            if num not in count_dict:
                count_dict[num] = 1
            else:
                count_dict[num] += 1
        
        buckets = dict()
        for num, count in count_dict.items():
            if count not in buckets:
                buckets[count] = []
            buckets[count].append(num)
            
        res = []
        for count in range(len(nums), -1, -1):
            if count in buckets:
                for num in buckets[count]:
                    res.append(num)
            if len(res) >= k:
                return res
        





# @lc code=end

sol = Solution()
# nums = [1,1,1,2,2,3]
nums = [1]
k = 1
print(sol.topKFrequent(nums, k))