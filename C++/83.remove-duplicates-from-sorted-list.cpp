/*
 * @lc app=leetcode id=83 lang=cpp
 *
 * [83] Remove Duplicates from Sorted List
 *
 * https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/
 *
 * algorithms
 * Easy (43.81%)
 * Likes:    1023
 * Dislikes: 89
 * Total Accepted:    389K
 * Total Submissions: 887.1K
 * Testcase Example:  '[1,1,2]'
 *
 * Given a sorted linked list, delete all duplicates such that each element
 * appear only once.
 * 
 * Example 1:
 * 
 * 
 * Input: 1->1->2
 * Output: 1->2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 1->1->2->3->3
 * Output: 1->2->3
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
    ListNode* deleteDuplicates(ListNode* head) {

        ListNode *cur = head;
        while (cur && cur->next) {
            if (cur->val == cur->next->val) {
                ListNode* tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
            }
            else
                cur = cur->next;
        }

        return head;
    }
};
// @lc code=end

