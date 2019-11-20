#
# @lc app=leetcode id=127 lang=python
#
# [127] Word Ladder
#
# https://leetcode.com/problems/word-ladder/description/
#
# algorithms
# Medium (26.17%)
# Likes:    1988
# Dislikes: 933
# Total Accepted:    319.3K
# Total Submissions: 1.2M
# Testcase Example:  '"hit"\n"cog"\n["hot","dot","dog","lot","log","cog"]'
#
# Given two words (beginWord and endWord), and a dictionary's word list, find
# the length of shortest transformation sequence from beginWord to endWord,
# such that:
# 
# 
# Only one letter can be changed at a time.
# Each transformed word must exist in the word list. Note that beginWord is not
# a transformed word.
# 
# 
# Note:
# 
# 
# Return 0 if there is no such transformation sequence.
# All words have the same length.
# All words contain only lowercase alphabetic characters.
# You may assume no duplicates in the word list.
# You may assume beginWord and endWord are non-empty and are not the same.
# 
# 
# Example 1:
# 
# 
# Input:
# beginWord = "hit",
# endWord = "cog",
# wordList = ["hot","dot","dog","lot","log","cog"]
# 
# Output: 5
# 
# Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" ->
# "dog" -> "cog",
# return its length 5.
# 
# 
# Example 2:
# 
# 
# Input:
# beginWord = "hit"
# endWord = "cog"
# wordList = ["hot","dot","dog","lot","log"]
# 
# Output: 0
# 
# Explanation: The endWord "cog" is not in wordList, therefore no possible
# transformation.
# 
# 
# 
# 
# 
#

# @lc code=start
class Solution(object):
    def ladderLength(self, beginWord, endWord, wordList):
        """
        :type beginWord: str
        :type endWord: str
        :type wordList: List[str]
        :rtype: int
        """
    #     wordList.append(beginWord)
    #     n = len(wordList)

    #     start, end = n-1, 0
    #     for i in range(n):
    #         if wordList[i] == endWord:
    #             break
    #     end = i

    #     if end+1 == n:
    #         return 0 

    #     graph = self.build_graph(wordList)
    #     ans = self.get_shortest_path(graph, start, end) 
    #     return ans 
    
    # def build_graph(self, wordList):
    #     n = len(wordList)
    #     edge_list = []

    #     for i in range(n):
    #         edge_list.append([])
    #         for j in range(n):
    #             if self.is_connected(wordList[i], wordList[j]):
    #                 edge_list[i].append(j)
    #     return edge_list
    
    # def is_connected(self, word1, word2):
    #     count = 0 
    #     for i in range(len(word1)):
    #         if word1[i] != word2[i]:
    #             count+=1
    #     return count == 1

    # def get_shortest_path(self, edge_list, start, end):
    #     import collections 
    #     queue = collections.deque([start])
        
    #     visited = [False] * len(edge_list)
    #     visited[start] = True

    #     path_len = 1
    #     while queue:
    #         queue_size = len(queue)
    #         path_len += 1
    #         while queue_size > 0:
    #             cur = queue.popleft()
    #             for nex in edge_list[cur]:
    #                 if nex == end:
    #                     return path_len
    #                 elif visited[nex]:
    #                     continue
    #                 else:
    #                     visited[nex] = True
    #                     queue.append(nex)
    #             queue_size -= 1

    #     return 0 


        if endWord not in wordList or not endWord or not beginWord or not wordList:
            return 0

        n = len(beginWord)

        from collections import defaultdict, deque
        all_combo_dict = defaultdict(list)
        for word in wordList:
            for i in range(n):
                all_combo_dict[word[:i] + "*" + word[i+1:]].append(word)

        # Queue for BFS
        queue = deque([(beginWord, 1)])
        # Visited to make sure we don't repeat processing same word.
        visited = {beginWord: True}

        while queue:
            cur, level = queue.popleft()  

            for i in range(n):
                
                next_word = cur[:i] + "*" + cur[i+1:]
                for word in all_combo_dict[next_word]:
                    if word == endWord:
                        return level + 1
                    if word not in visited:
                        visited[word] = True
                        queue.append((word, level + 1))

                all_combo_dict[next_word] = []
        return 0
# @lc code=end

sol = Solution()
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log","cog"]
print(sol.ladderLength(beginWord, endWord, wordList))

