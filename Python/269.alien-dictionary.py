#
# @lc app=leetcode id=269 lang=python3
#
# [269] Alien Dictionary
#
# https://leetcode.com/problems/alien-dictionary/description/
#
# algorithms
# Hard (35.92%)
# Likes:    4434
# Dislikes: 994
# Total Accepted:    391.9K
# Total Submissions: 1.1M
# Testcase Example:  '["wrt","wrf","er","ett","rftt"]'
#
# There is a new alien language that uses the English alphabet. However, the
# order of the letters is unknown to you.
# 
# You are given a list of strings words from the alien language's dictionary.
# Now it is claimed that the strings in words are sorted lexicographically by
# the rules of this new language.
# 
# If this claim is incorrect, and the given arrangement of string in words
# cannot correspond to any order of letters, return "".
# 
# Otherwise, return a string of the unique letters in the new alien language
# sorted in lexicographically increasing order by the new language's rules. If
# there are multiple solutions, return any of them.
# 
# 
# Example 1:
# 
# 
# Input: words = ["wrt","wrf","er","ett","rftt"]
# Output: "wertf"
# 
# 
# Example 2:
# 
# 
# Input: words = ["z","x"]
# Output: "zx"
# 
# 
# Example 3:
# 
# 
# Input: words = ["z","x","z"]
# Output: ""
# Explanation: The order is invalid, so return "".
# 
# 
# 
# Constraints:
# 
# 
# 1 <= words.length <= 100
# 1 <= words[i].length <= 100
# words[i] consists of only lowercase English letters.
# 
# 
#

# @lc code=start
class Solution:
    def alienOrder(self, words: List[str]) -> str:
        graph = defaultdict(set)
        indeg = {c: 0 for w in words for c in w}

        for pair in zip(words[:-1], words[1:]):
            for a, b in zip(*pair):
                if a != b:
                    if b not in graph[a]:
                        graph[a].add(b)
                        indeg[b] += 1
                    break
            # if all the characters in the first word are the same as the second word
            # then the first word should be shorter than the second word
            
            # The else keyword in a for loop specifies a block of code to be executed when the loop is finished.
            # The else block will NOT be executed if the loop is stopped by a break statement.
            else:
                if len(pair[0]) > len(pair[1]):
                    return ""
                
        
        ans = ""
        queue = collections.deque([c for c in indeg if indeg[c] == 0])
        while queue:
            cur = queue.popleft()
            ans += cur

            for nei in graph[cur]:
                indeg[nei] -= 1
                if indeg[nei] == 0:
                    queue.append(nei)

        return ans if len(ans) == len(indeg) else ""


# @lc code=end

