/*
 * @lc app=leetcode id=92 lang=cpp
 *
 * [92] Reverse Linked List II
 *
 * https://leetcode.com/problems/reverse-linked-list-ii/description/
 *
 * algorithms
 * Medium (36.66%)
 * Likes:    1687
 * Dislikes: 112
 * Total Accepted:    231.1K
 * Total Submissions: 628.3K
 * Testcase Example:  '[1,2,3,4,5]\n2\n4'
 *
 * Reverse a linked list from position m to n. Do it in one-pass.
 * 
 * Note: 1 ≤ m ≤ n ≤ length of list.
 * 
 * Example:
 * 
 * 
 * Input: 1->2->3->4->5->NULL, m = 2, n = 4
 * Output: 1->4->3->2->5->NULL
 * 
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m==n) return head;

        ListNode dummy(0);
        dummy.next=head;

        ListNode* pre = &dummy;
        for (int i=0; i<m-1; i++) 
            pre = pre->next;

        ListNode* cur = pre->next, *next=NULL, *reverse=NULL;

        for(int i=0; i<n-m+1; i++) {
            next = cur->next;
            cur->next = reverse;
            reverse = cur;
            cur = next;
        }
        pre->next->next = cur;
        pre->next = reverse;

        return dummy.next;
    }
};
// @lc code=end

