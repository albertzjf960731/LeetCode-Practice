#
# @lc app=leetcode id=1442 lang=python3
#
# [1442] Count Triplets That Can Form Two Arrays of Equal XOR
#
# https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/description/
#
# algorithms
# Medium (77.07%)
# Likes:    1416
# Dislikes: 73
# Total Accepted:    46K
# Total Submissions: 58.4K
# Testcase Example:  '[2,3,1,6,7]'
#
# Given an array of integers arr.
# 
# We want to select three indices i, j and k where (0 <= i < j <= k <
# arr.length).
# 
# Let's define a and b as follows:
# 
# 
# a = arr[i] ^ arr[i + 1] ^ ... ^ arr[j - 1]
# b = arr[j] ^ arr[j + 1] ^ ... ^ arr[k]
# 
# 
# Note that ^ denotes the bitwise-xor operation.
# 
# Return the number of triplets (i, j and k) Where a == b.
# 
# 
# Example 1:
# 
# 
# Input: arr = [2,3,1,6,7]
# Output: 4
# Explanation: The triplets are (0,1,2), (0,2,2), (2,3,4) and (2,4,4)
# 
# 
# Example 2:
# 
# 
# Input: arr = [1,1,1,1,1]
# Output: 10
# 
# 
# 
# Constraints:
# 
# 
# 1 <= arr.length <= 300
# 1 <= arr[i] <= 10^8
# 
# 
#

# @lc code=start
class Solution:
    def countTriplets(self, arr: List[int]) -> int:
        n = len(arr)
        ans = 0
        for i in range(n):
            xor = arr[i]
            for k in range(i+1, n):
                xor ^= arr[k]
                if xor == 0:
                    ans += k - i
        return ans
    
        cur = 0
        hmap = {0: [-1]}
        ans = 0
        for i in range(len(arr)):
            cur ^= arr[i]
            for j in hmap.get(cur, []):
                ans += i - j - 1
            tmp = hmap.get(cur, [])
            tmp.append(i)
            hmap[cur] = tmp
        return ans

# @lc code=end

