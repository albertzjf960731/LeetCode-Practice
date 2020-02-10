/*
 * @lc app=leetcode id=143 lang=cpp
 *
 * [143] Reorder List
 *
 * https://leetcode.com/problems/reorder-list/description/
 *
 * algorithms
 * Medium (34.14%)
 * Likes:    1369
 * Dislikes: 97
 * Total Accepted:    195.5K
 * Total Submissions: 572.5K
 * Testcase Example:  '[1,2,3,4]'
 *
 * Given a singly linked list L: L0→L1→…→Ln-1→Ln,
 * reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
 * 
 * You may not modify the values in the list's nodes, only nodes itself may be
 * changed.
 * 
 * Example 1:
 * 
 * 
 * Given 1->2->3->4, reorder it to 1->4->2->3.
 * 
 * Example 2:
 * 
 * 
 * Given 1->2->3->4->5, reorder it to 1->5->2->4->3.
 * 
 * 
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
    void reorderList(ListNode* head) {
        if (head==NULL || head->next==NULL)
            return;

        // ListNode dummy(0);
        // dummy.next = head;
        // ListNode *slow=&dummy, *fast=&dummy;
        ListNode *slow=head, *fast=head;

        while (fast!=NULL && fast->next!=NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *head2 = slow->next;
        slow->next = NULL;
        
        ListNode* cur=head2, *pre=NULL, *next=NULL;
        while (cur) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        head2 = pre;
        
        ListNode* cur1=head, *cur2=head2, *next1=NULL, *next2=NULL;
        while (cur1 && cur2) {
            next1 = cur1->next;
            next2 = cur2->next;
            cur1->next = cur2;
            cur2->next = next1;
            cur1 = next1;
            cur2 = next2;
        }     
    }
};
// @lc code=end

