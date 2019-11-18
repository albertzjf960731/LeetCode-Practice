#
# @lc app=leetcode id=187 lang=python
#
# [187] Repeated DNA Sequences
#
# https://leetcode.com/problems/repeated-dna-sequences/description/
#
# algorithms
# Medium (37.20%)
# Likes:    542
# Dislikes: 214
# Total Accepted:    140.6K
# Total Submissions: 377K
# Testcase Example:  '"AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"'
#
# All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T,
# for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to
# identify repeated sequences within the DNA.
# 
# Write a function to find all the 10-letter-long sequences (substrings) that
# occur more than once in a DNA molecule.
# 
# Example:
# 
# 
# Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
# 
# Output: ["AAAAACCCCC", "CCCCCAAAAA"]
# 
# 
#

# @lc code=start
class Solution(object):
    def findRepeatedDnaSequences(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        
        hash_set = set()
        res = []
        for i in range(len(s)-9):
            substr = s[i:i+10]
            if substr not in hash_set:
                hash_set.add(substr)
            else:
                if substr not in res:
                    res.append(substr)  
        return res
        
# @lc code=end

sol = Solution()
s = "AAAAAAAAAAAA"
sol.findRepeatedDnaSequences(s)