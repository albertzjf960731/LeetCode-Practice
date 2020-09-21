/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
 */

/**
 * Definition for singly-linked list.
 */

#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// @lc code=start
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* cur = &dummy;
        ListNode *pre, *next;
        while (cur->next && cur->next->next) {
            pre = cur->next;
            next = cur->next->next;

            cur->next = next;
            pre->next = next->next;
            next->next = pre;

            cur = pre;
        }
        return dummy.next;


        if (!head || !head->next) return head;
        
        ListNode dummy(0);
        dummy.next = head->next;
        
        head->next = head->next->next;
        dummy.next->next = head;

        head->next = swapPairs(head->next);
        
        return dummy.next;
    }
};
// @lc code=end

