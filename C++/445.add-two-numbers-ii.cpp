/*
 * @lc app=leetcode id=445 lang=cpp
 *
 * [445] Add Two Numbers II
 *
 * https://leetcode.com/problems/add-two-numbers-ii/description/
 *
 * algorithms
 * Medium (52.61%)
 * Likes:    1058
 * Dislikes: 133
 * Total Accepted:    128K
 * Total Submissions: 243.1K
 * Testcase Example:  '[7,2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The most significant digit comes first and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 * 
 * Follow up:
 * What if you cannot modify the input lists? In other words, reversing the
 * lists is not allowed.
 * 
 * 
 * 
 * Example:
 * 
 * Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 8 -> 0 -> 7
 * 
 * 
 */

/**
 * Definition for singly-linked list.
 */
#include<vector>
#include<string>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
// @lc code=start
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> num1, num2;
        for (; l1!=NULL; l1=l1->next) num1.push_back(l1->val);
        for (; l2!=NULL; l2=l2->next) num2.push_back(l2->val);

        ListNode *cur = nullptr;
        int carry = 0;
        int i = num1.size()-1, j = num2.size()-1;
        while (i>=0 || j>=0 || carry) {
            int sum = (i>=0 ? num1[i] : 0) + (j>=0 ? num2[j] : 0) + carry;
            carry = sum / 10;
            ListNode *node = new ListNode(sum % 10);
            node->next = cur;
            cur = node;
            
            i--;
            j--;
        }
        return cur;
    }
};
// @lc code=end

