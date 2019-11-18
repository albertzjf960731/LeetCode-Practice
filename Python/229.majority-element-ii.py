#
# @lc app=leetcode id=229 lang=python
#
# [229] Majority Element II
#
# https://leetcode.com/problems/majority-element-ii/description/
#
# algorithms
# Medium (33.43%)
# Likes:    1106
# Dislikes: 126
# Total Accepted:    117.6K
# Total Submissions: 350.7K
# Testcase Example:  '[3,2,3]'
#
# Given an integer array of size n, find all elements that appear more than ⌊
# n/3 ⌋ times.
# 
# Note: The algorithm should run in linear time and in O(1) space.
# 
# Example 1:
# 
# 
# Input: [3,2,3]
# Output: [3]
# 
# Example 2:
# 
# 
# Input: [1,1,1,3,3,2,2,2]
# Output: [1,2]
# 
#

# @lc code=start
class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        # hash_map = dict()
        # res = []
        # for num in nums:
        #     if num not in hash_map:
        #         hash_map[num] = 0
        #     hash_map[num] += 1
        #     if hash_map[num] > len(nums)//3 and num not in res:
        #         res.append(num)
        # return res

        import collections
        count = collections.Counter()

        for num in nums:
            count[num] += 1
            if len(count) == 3:
                # 都减一
                count -= collections.Counter(set(count))

        # 再次检查
        return [num for num in count if nums.count(num) > len(nums) // 3]

# @lc code=end

sol = Solution()
nums = [1,1,1,3,3,2,2,2]
sol.majorityElement(nums)