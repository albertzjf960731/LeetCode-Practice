/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
 *
 * https://leetcode.com/problems/palindrome-linked-list/description/
 *
 * algorithms
 * Easy (37.87%)
 * Likes:    2377
 * Dislikes: 315
 * Total Accepted:    347.4K
 * Total Submissions: 917.3K
 * Testcase Example:  '[1,2]'
 *
 * Given a singly linked list, determine if it is a palindrome.
 * 
 * Example 1:
 * 
 * 
 * Input: 1->2
 * Output: false
 * 
 * Example 2:
 * 
 * 
 * Input: 1->2->2->1
 * Output: true
 * 
 * Follow up:
 * Could you do it in O(n) time and O(1) space?
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
    bool isPalindrome(ListNode* head) {
        if (head==NULL || head->next==NULL)
            return true;

        ListNode *slow=head, *fast=head->next;
        while (fast!=NULL && fast->next!=NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *head2 = NULL;
        if (fast==NULL) { // odd
            head2 = head;
            while (head2->next!=slow)
                head2 = head2->next;
            head2->next = NULL;
            head2 = slow;
        }
        else { // even
            head2 = slow->next;
            slow->next = NULL;
        }

        ListNode *head1 = head;
        head2 = reverseList(head2);
        while (head1!=NULL && head2!=NULL) {
            if (head1->val != head2->val)
                return false;
            head1 = head1->next;
            head2 = head2->next;
        }
        return true;
    }

    ListNode* reverseList(ListNode* head) {             
        ListNode* cur = head, *pre=NULL, *next=NULL;
        while (cur) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};
// @lc code=end

