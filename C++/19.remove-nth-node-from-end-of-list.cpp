/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
 */

/**
 * Definition for singly-linked list.
 */

#include<vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
// @lc code=start
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode *slow=&dummy, *fast=&dummy;

        for (int i=0; i<n; i++)
            fast = fast->next;
        while (fast->next){
            fast = fast->next;
            slow = slow->next;
        }
        
        ListNode *to_be_deleted = slow->next;
        slow->next = slow->next->next;
        delete to_be_deleted;
        
        return dummy.next;
    }
};
// @lc code=end

