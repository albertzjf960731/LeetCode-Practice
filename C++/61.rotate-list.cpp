/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] Rotate List
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return head;

        int n = 1;
        ListNode* tail = head;
        while (tail->next) {
            tail = tail->next;
            n++;
        }
        tail->next = head;

        for (int i=0; i<(n-k%n); i++) {
            head = head->next;
            tail = tail->next;
        }
        tail->next = NULL;
        return head;
    }
};
// @lc code=end

