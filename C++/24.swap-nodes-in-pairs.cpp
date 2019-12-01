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
        ListNode *pre, *post;
        while (cur->next && cur->next->next) {
            pre = cur->next;
            post = cur->next->next;

            cur->next = post;
            pre->next = post->next;
            post->next = pre;

            cur = pre;
        }
        return dummy.next;
    }
};
// @lc code=end

