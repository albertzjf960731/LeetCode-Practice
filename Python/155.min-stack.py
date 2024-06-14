#
# @lc app=leetcode id=155 lang=python
#
# [155] Min Stack
#
# https://leetcode.com/problems/min-stack/description/
#
# algorithms
# Easy (39.35%)
# Likes:    2225
# Dislikes: 243
# Total Accepted:    365.5K
# Total Submissions: 927.3K
# Testcase Example:  '["MinStack","push","push","push","getMin","pop","top","getMin"]\n' +
#   '[[],[-2],[0],[-3],[],[],[],[]]'
#
# Design a stack that supports push, pop, top, and retrieving the minimum
# element in constant time.
# 
# 
# push(x) -- Push element x onto stack.
# pop() -- Removes the element on top of the stack.
# top() -- Get the top element.
# getMin() -- Retrieve the minimum element in the stack.
# 
# 
# 
# 
# Example:
# 
# 
# MinStack minStack = new MinStack();
# minStack.push(-2);
# minStack.push(0);
# minStack.push(-3);
# minStack.getMin();   --> Returns -3.
# minStack.pop();
# minStack.top();      --> Returns 0.
# minStack.getMin();   --> Returns -2.
# 
# 
# 
# 
#

# @lc code=start
class MinStack(object):

    def __init__(self):
        self.stack = []
        self.curMin = []

    def push(self, val: int) -> None:
        self.stack.append(val)
        if not self.curMin:
            self.curMin.append(val)
        else:
            self.curMin.append(min(self.curMin[-1], val))

    def pop(self) -> None:
        self.stack.pop()
        self.curMin.pop()
        
    def top(self) -> int:
        return self.stack[-1]

    def getMin(self) -> int:
        return self.curMin[-1]

# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
# @lc code=end

