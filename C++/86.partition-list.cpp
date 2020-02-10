/*
 * @lc app=leetcode id=86 lang=cpp
 *
 * [86] Partition List
 *
 * https://leetcode.com/problems/partition-list/description/
 *
 * algorithms
 * Medium (39.11%)
 * Likes:    920
 * Dislikes: 245
 * Total Accepted:    188.5K
 * Total Submissions: 480.4K
 * Testcase Example:  '[1,4,3,2,5,2]\n3'
 *
 * Given a linked list and a value x, partition it such that all nodes less
 * than x come before nodes greater than or equal to x.
 * 
 * You should preserve the original relative order of the nodes in each of the
 * two partitions.
 * 
 * Example:
 * 
 * 
 * Input: head = 1->4->3->2->5->2, x = 3
 * Output: 1->2->2->4->3->5
 * 
 * 
 */
#include<iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
// @lc code=start
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode h1(0), h2(0);
        ListNode *l1=&h1, *l2=&h2;

        ListNode *cur = head;
        while (cur) {
            if (cur->val < x) {
                l1->next = cur;
                l1 = l1->next;
            }
            else {
                l2->next = cur;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        l2->next = NULL;
        l1->next = h2.next;
        return h1.next;
    }
};
// @lc code=end

