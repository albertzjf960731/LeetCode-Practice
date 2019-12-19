/*
 * @lc app=leetcode id=82 lang=cpp
 *
 * [82] Remove Duplicates from Sorted List II
 *
 * https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/
 *
 * algorithms
 * Medium (34.72%)
 * Likes:    1162
 * Dislikes: 95
 * Total Accepted:    213.4K
 * Total Submissions: 613.4K
 * Testcase Example:  '[1,2,3,3,4,4,5]'
 *
 * Given a sorted linked list, delete all nodes that have duplicate numbers,
 * leaving only distinct numbers from the original list.
 * 
 * Example 1:
 * 
 * 
 * Input: 1->2->3->3->4->4->5
 * Output: 1->2->5
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 1->1->1->2->3
 * Output: 2->3
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode *pre=&dummy, *cur=head;

        while(cur) {
            int flag = 0;

            while (cur->next && cur->val == cur->next->val) {
                cur = cur->next;
                flag = 1;
            }

            //发生了相等的情况, pre.next 直接指向 cur.next 删除所有重复数字
            if (flag) {
                pre->next = cur->next;
                flag = 0;
            }
            //没有发生相等的情况, pre 移到 cur 的地方
            else 
                pre = cur;
                
            cur = cur->next;
        }
        return dummy.next;
    }
};
// @lc code=end

