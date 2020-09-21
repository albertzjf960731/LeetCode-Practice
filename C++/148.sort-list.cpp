/*
 * @lc app=leetcode id=148 lang=cpp
 *
 * [148] Sort List
 *
 * https://leetcode.com/problems/sort-list/description/
 *
 * algorithms
 * Medium (39.19%)
 * Likes:    2098
 * Dislikes: 103
 * Total Accepted:    229.9K
 * Total Submissions: 586.2K
 * Testcase Example:  '[4,2,1,3]'
 *
 * Sort a linked list in O(n log n) time using constant space complexity.
 * 
 * Example 1:
 * 
 * 
 * Input: 4->2->1->3
 * Output: 1->2->3->4
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: -1->5->3->4->0
 * Output: -1->0->3->4->5
 * 
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
    ListNode* sortList(ListNode* head) {
        if (head==NULL || head->next==NULL)
            return head;

        // ListNode dummy(0);
        // dummy.next = head;
        // ListNode *slow=&dummy, *fast=&dummy;
        ListNode *slow=head, *fast=head, *pre=head;

        while (fast!=NULL && fast->next!=NULL) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        // ListNode *head2 = slow->next;
        // slow->next = NULL;
        ListNode* head2 = slow;
        pre->next = NULL;

        head = sortList(head);
        head2 = sortList(head2);
        return merge(head, head2);

    }
    
    ListNode* merge(ListNode* l1, ListNode* l2) {  
        ListNode dummy(0);
        ListNode* cur = &dummy;

        while(l1!=NULL && l2!=NULL) {
            if (l1->val<l2->val) {
                cur->next = l1;
                l1 = l1->next;
            }
            else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        if (l1!=NULL) cur->next = l1;
        else cur->next = l2;
        return dummy.next;
    }

    // ListNode* sortList(ListNode* head, ListNode* tail=NULL) {
    //     if (head != tail) {
    //         ListNode* idx = partition(head, tail);
    //         sortList(head, idx);
    //         sortList(idx->next, tail);
    //     }
    //     return head;
    // }
    
    // ListNode* partition(ListNode* head, ListNode* tail) {
    //     int val = head->val;
          
    //     ListNode* slow = head;
    //     ListNode* fast = head->next;
    //     while (fast != tail) {
    //         if (fast->val < val) {
    //             slow = slow->next;
    //             swap(slow->val, fast->val);
    //         }
    //         fast = fast->next;
    //     }
    //     swap(slow->val, head->val);
    //     return slow;
    // }
};
// @lc code=end

