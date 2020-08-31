/*
 * @lc app=leetcode id=232 lang=cpp
 *
 * [232] Implement Queue using Stacks
 */
#include<vector>
using namespace std;

// @lc code=start
class MyQueue {
private:
    vector<int> in_stack_, out_stack_;
    
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        in_stack_.push_back(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        shiftStack();
        int num = out_stack_.back();
        out_stack_.pop_back();
        return num;
    }
    
    /** Get the front element. */
    int peek() {
        shiftStack();
        return out_stack_.back();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return in_stack_.empty() && out_stack_.empty();
    }
    
    void shiftStack() {
        if (out_stack_.empty()) {
            while (!in_stack_.empty()) {
                out_stack_.push_back(in_stack_.back());
                in_stack_.pop_back();
            }
        }
        return ;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

