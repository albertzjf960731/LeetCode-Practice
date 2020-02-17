/*
 * @lc app=leetcode id=1265 lang=cpp
 *
 * [1265] Reverse Linked List
 *
 * https://leetcode.com/problems/reverse-linked-list/description/
 *
 * algorithms
 * Easy (58.27%)
 * Likes:    3287
 * Dislikes: 78
 * Total Accepted:    779.2K
 * Total Submissions: 1.3M
 * Testcase Example:  '[1,2,3,4,5]'
 * 
 * You are given an immutable linked list, print out all values of each node in reverse with the help of the following interface:
 * 
 * ImmutableListNode: An interface of immutable linked list, you are given the head of the list.
 * 
 * You need to use the following functions to access the linked list (you can't access the ImmutableListNode directly):
 * 
 * ImmutableListNode.printValue(): Print value of the current node.
 * ImmutableListNode.getNext(): Return the next node.
 * The input is only given to initialize the linked list internally. You must solve this problem without modifying the linked list. In other words, you must operate the linked list using only the mentioned APIs.
 * 
 * 
 * Follow up:
 * 
 * Could you solve this problem in:
 * Constant space complexity?
 * Linear time complexity and less than linear space complexity?
 * 
 * Example 1:
 * 
 * Input: head = [1,2,3,4]
 * Output: [4,3,2,1]
 * Example 2:
 * 
 * Input: head = [0,-4,-1,3,-5]
 * Output: [-5,3,-1,-4,0]
 * Example 3:
 * 
 * Input: head = [-2,0,6,4,4,-6]
 * Output: [-6,4,4,6,0,-2]
 * 
 * Constraints:
 * 
 * The length of the linked list is between [1, 1000].
 * The value of each node in the linked list is between [-1000, 1000].

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
    void printLinkedListInReverse(ListNode* head) {
        // 递归本质上是一个栈结构
        if (head==NULL) return;

        printLinkedListInReverse(head.getNext());
        head.printValue();

        if (head==NULL) return;
        vector<ListNode*> stack;
        ListNode* cur = head;
        while (cur) {
            stack.push_back(cur);
            cur = cur->next;
        }

        while (!stack.empty()) {
            cur = stack.back();
            stack.pop_back();
            cur.printValue();
        }

        reversePrint(head, NULL);

    }
    void reversePrint(ListNode* start, ListNode* end) {
        if (start==end)  return;

        ListNode *slow=start, *fast=start;
        while (fast->next!=NULL && fast->next->next!=NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        reversePrint(slow->next, end);
        slow.printValue();
        reversePrint(start, slow);
    }
};
// @lc code=end

