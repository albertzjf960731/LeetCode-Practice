#
# @lc app=leetcode id=93 lang=python
#
# [93] Restore IP Addresses
#
# https://leetcode.com/problems/restore-ip-addresses/description/
#
# algorithms
# Medium (32.79%)
# Likes:    841
# Dislikes: 359
# Total Accepted:    158K
# Total Submissions: 481.3K
# Testcase Example:  '"25525511135"'
#
# Given a string containing only digits, restore it by returning all possible
# valid IP address combinations.
# 
# Example:
# 
# 
# Input: "25525511135"
# Output: ["255.255.11.135", "255.255.111.35"]
# 
# 
#

# @lc code=start
class Solution(object):
    def restoreIpAddresses(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        # === 回溯 ===
        res = []
        self.dfs(s, res, [])
        return ['.'.join(ip) for ip in res]
   
    def dfs(self, s, res, path):
        if len(path) == 4:
            if not s and path not in res:
                res.append(path)
            return 

        for i in range(1, 4):
            if i <= len(s):
                if i == 1:
                    self.dfs(s[i:], res, path+[s[:i]])
                if i == 2 and s[0] != '0':
                    self.dfs(s[i:], res, path+[s[:i]])
                if i == 3 and s[0] != '0' and int(s[:3]) <= 255: 
                    self.dfs(s[i:], res, path+[s[:i]])
        
    #     # 迭代暴力
    #     res = []
    #     i = 1
    #     while i < 4 and i < len(s)-2:
    #         j = i+1
    #         while j<i+4 and j<len(s)-1:
    #             k = j+1
    #             while k < j+4 and k<len(s):
    #                 s1 = s[0:i]
    #                 s2 = s[i:j]
    #                 s3 = s[j:k]
    #                 s4 = s[k:]
    #                 if self.is_valid(s1) and self.is_valid(s2) and self.is_valid(s3) and self.is_valid(s4):
    #                     res.append(s1+'.'+s2+'.'+s3+'.'+s4)
    #                 k += 1
    #             j += 1
    #         i += 1
    #     return res 
    # def is_valid(self, s):
    #     if(len(s)>3 or len(s)==0 or (s[0]=='0' and len(s)>1) or int(s)>255):
    #         return False
    #     return True

# @lc code=end

sol = Solution()
s = "1111"
print(sol.restoreIpAddresses(s))