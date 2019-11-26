/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] Add Two Numbers
 */

#include<iostream>  
using namespace std;  

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};


// @lc code=start
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // 点运算符( . )的左边操作数是一个结果为结构的表达式；
        // 箭头运算符( -> )的左边的操作数是一个指向结构体的指针。
        ListNode dummy(0), *cur = &dummy;
        // ListNode *dummy = new ListNode(0);

        int carry = 0;

        while (l1 || l2 || carry) {
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            carry = sum / 10;
            cur->next = new ListNode(sum%10);
            cur = cur->next;
            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
        }
        return dummy.next;
    }
};
// @lc code=end

int main(){
    Solution sol;
    ListNode l1(0), *cur = &l1;
}