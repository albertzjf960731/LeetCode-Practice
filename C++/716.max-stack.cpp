/*
 * @lc app=leetcode id=716 lang=cpp
 *
 * [716] Max Stack
 *
 * https://leetcode.com/problems/min-stack/description/
 *
 * algorithms
 * Easy (40.83%)
 * Likes:    2608
 * Dislikes: 272
 * Total Accepted:    410.1K
 * Total Submissions: 1M
 * Testcase Example:  '["MinStack","push","push","push","getMin","pop","top","getMin"]\n' +
  '[[],[-2],[0],[-3],[],[],[],[]]'
 *
 * Design a max stack that supports push, pop, top, peekMax and popMax.
 * 
 * push(x) -- Push element x onto stack.
 * pop() -- Remove the element on top of the stack and return it.
 * top() -- Get the element on the top.
 * peekMax() -- Retrieve the maximum element in the stack.
 * popMax() -- Retrieve the maximum element in the stack, and remove it. If you find more than one maximum elements, only remove the top-most one.
 * 
 * Example 1:
 * MaxStack stack = new MaxStack();
 * stack.push(5); 
 * stack.push(1);
 * stack.push(5);
 * stack.top(); -> 5
 * stack.popMax(); -> 5
 * stack.top(); -> 1
 * stack.peekMax(); -> 5
 * stack.pop(); -> 1
 * stack.top(); -> 5
 * 
 * Note:
 * -1e7 <= x <= 1e7
 * Number of operations won't exceed 10000.
 * The last four operations won't be called when stack is empty.

 * 
 * 
 */
#include<vector>
using namespace std;

// @lc code=start
// class MaxStack {
// private:
//     vector<int> nums, maxs;
// public:
//     /** initialize your data structure here. */
//     MaxStack() {}
    
//     void push(int x) {
//         if (maxs.empty() || maxs.back() <= x) 
//             maxs.push_back(x);
//         nums.push_back(x);
//     }
    
//     int pop() {
//         if (!maxs.empty() && maxs.back()==nums.back()) 
//             maxs.pop_back();
//         int num = nums.back(); 
//         nums.pop_back();
//         return num;
//     }
    
//     int top() {
//         return nums.back();
//     }
    
//     int peekMax() {
//         return maxs.back();
//     }
    
//     int popMax() {
//         int mx = maxs.back();

//         vector<int> tmp;
//         while (nums.back() != maxs.back()) {
//             tmp.push_back(nums.back()); 
//             nums.pop_back();
//         }

//         nums.pop_back(); maxs.pop_back();
//         while (!tmp.empty()) {
//             nums.push_back(tmp.back()); 
//             tmp.pop_back();
//         }
//         return mx;
//     }
// };
class MaxStack {
public:
    vector<pair<int, int>> stack_;
    /** initialize your data structure here. */
    MaxStack() {
        
    }
    
    void push(int x) {
        int max_num;
        if(stack_.empty())
            max_num = x;
        else
            max_num = max(x, stack_.back().second);
        stack_.push_back(make_pair(x, max_num));
    }
    
    void pop() {
        stack_.pop_back();
    }
    
    int top() {
        return stack_.back().first;
    }
    
    int peekMax() {
        // if (stack_.empty())
        //     return -1;
        return stack_.back().second;
    }
    int popMax() {
        int mx = stack_.back().second;

        vector<pair<int, int>> tmp;
        while (stack_.back().first != mx) {
            tmp.push_back(stack_.back()); 
            stack_.pop_back();
        }
        stack_.pop_back();
        while (!tmp.empty()) {
            stack_.push_back(tmp.back()); 
            tmp.pop_back();
        }
        return mx;
    }

};


/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

