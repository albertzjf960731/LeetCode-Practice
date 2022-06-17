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


        // int count = 0, temp;
        // ListNode *head, *last;
        // for(head = l1; head; head = head->next)
        //     count++;
        // for(head = l2; head; head = head->next)
        //     count--;
        // if(count < 0)                       //计算两链表长度，将l1指向长链，l2指向短链，将l2的值加到l1中
        //     swap(l1,l2);            
        // last = head = new ListNode(0);      //在链首加一个值为0的节点作为初始的last节点，如果最终该节点值仍为0则删除该节点
        // head->next = l1;
        // for(int i = abs(count); i != 0; i--){  //将两链数位对齐
        //     if(l1->val != 9)
        //         last = l1;
        //     l1 = l1->next;
        // }
        // while(l1){
        //     temp = l1->val + l2->val;
        //     if(temp > 9){                   //如果发生进位，则更新last到l1之间所有数位的值
        //         temp -= 10;                 //进位后当前数位最大值为8，故将last指针指向当前数位
        //         last->val += 1;
        //         last = last->next;
        //         while(last != l1){
        //             last->val = 0;
        //             last = last->next;
        //         }
        //     }
        //     else if(temp != 9)             
        //         last = l1;
        //     l1->val = temp;
        //     l1 = l1->next;
        //     l2 = l2->next;
        // }
        // return head->val == 1 ? head : head->next;
    }
};
// @lc code=end

