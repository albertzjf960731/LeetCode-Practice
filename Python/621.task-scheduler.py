#
# @lc app=leetcode id=621 lang=python3
#
# [621] Task Scheduler
#
# https://leetcode.com/problems/task-scheduler/description/
#
# algorithms
# Medium (59.94%)
# Likes:    10436
# Dislikes: 2066
# Total Accepted:    646.1K
# Total Submissions: 1.1M
# Testcase Example:  '["A","A","A","B","B","B"]\n2'
#
# You are given an array of CPU tasks, each represented by letters A to Z, and
# a cooling time, n. Each cycle or interval allows the completion of one task.
# Tasks can be completed in any order, but there's a constraint: identical
# tasks must be separated by at least n intervals due to cooling time.
# 
# ​Return the minimum number of intervals required to complete all tasks.
# 
# 
# Example 1:
# 
# 
# Input: tasks = ["A","A","A","B","B","B"], n = 2
# 
# Output: 8
# 
# Explanation: A possible sequence is: A -> B -> idle -> A -> B -> idle -> A ->
# B.
# 
# After completing task A, you must wait two cycles before doing A again. The
# same applies to task B. In the 3^rd interval, neither A nor B can be done, so
# you idle. By the 4^th cycle, you can do A again as 2 intervals have passed.
# 
# 
# Example 2:
# 
# 
# Input: tasks = ["A","C","A","B","D","B"], n = 1
# 
# Output: 6
# 
# Explanation: A possible sequence is: A -> B -> C -> D -> A -> B.
# 
# With a cooling interval of 1, you can repeat a task after just one other
# task.
# 
# 
# Example 3:
# 
# 
# Input: tasks = ["A","A","A", "B","B","B"], n = 3
# 
# Output: 10
# 
# Explanation: A possible sequence is: A -> B -> idle -> idle -> A -> B -> idle
# -> idle -> A -> B.
# 
# There are only two types of tasks, A and B, which need to be separated by 3
# intervals. This leads to idling twice between repetitions of these tasks.
# 
# 
# 
# Constraints:
# 
# 
# 1 <= tasks.length <= 10^4
# tasks[i] is an uppercase English letter.
# 0 <= n <= 100
# 
# 
#

# @lc code=start
class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        # # focus on the most frequent task
        # cnts = collections.Counter(tasks)
        # max_cnt = max(cnts.values())
        # ans = (max_cnt - 1) * (n + 1)
        # for cnt in cnts.values():
        #     if cnt == max_cnt:
        #         ans += 1
        # return max(ans, len(tasks))
        
        # priority queue solution
        pq = []
        for cnt in collections.Counter(tasks).values():
            heapq.heappush(pq, -cnt)
        
        ans = 0
        while pq:
            cnt = 0
            tmp = []
            for i in range(n + 1):
                if not pq:
                    break
                val = heapq.heappop(pq)
                cnt += 1
                if val < -1:
                    tmp.append(val + 1)
            for val in tmp:
                heapq.heappush(pq, val)  
            ans += n + 1 if pq else cnt
        return ans
# @lc code=end

