/*
 * @lc app=leetcode id=203 lang=cpp
 *
 * [203] Remove Linked List Elements
 *
 * https://leetcode.com/problems/remove-linked-list-elements/description/
 *
 * algorithms
 * Easy (36.76%)
 * Likes:    1073
 * Dislikes: 60
 * Total Accepted:    267K
 * Total Submissions: 726.2K
 * Testcase Example:  '[1,2,6,3,4,5,6]\n6'
 *
 * Remove all elements from a linked list of integers that have value val.
 * 
 * Example:
 * 
 * 
 * Input:  1->2->6->3->4->5->6, val = 6
 * Output: 1->2->3->4->5
 * 
 * 
 */

/**
 * Definition for singly-linked list.
 * };
 */
#include<vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}

// @lc code=start
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode *cur = &dummy;
        while (cur->next) {
            if (cur->next->val==val) 
                cur->next = cur->next->next;
            else 
                cur = cur->next;
        }   
        return dummy.next;
    }
};
// @lc code=end

