/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int count = 0;
        ListNode *pre = head;
        while(pre) {
            ++count;
            pre = pre->next;
        }
        if (k<=1 || count<k)
            return head;

        ListNode *cur = head, *next=NULL;
        pre = NULL;
        for (int i=0;i<k;++i) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        } 
        head->next = reverseKGroup(cur, k);
        return pre;
    }
};
// @lc code=end

