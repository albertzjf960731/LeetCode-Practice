/*
 * @lc app=leetcode id=1171 lang=cpp
 *
 * [1171] Remove Zero Sum Consecutive Nodes from Linked List
 *
 * https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/description/
 *
 * algorithms
 * Medium (41.53%)
 * Likes:    271
 * Dislikes: 24
 * Total Accepted:    9.9K
 * Total Submissions: 23.8K
 * Testcase Example:  '[1,2,-3,3,1]'
 *
 * Given the head of a linked list, we repeatedly delete consecutive sequences
 * of nodes that sum to 0 until there are no such sequences.
 * 
 * After doing so, return the head of the final linked list.  You may return
 * any such answer.
 * 
 * 
 * (Note that in the examples below, all sequences are serializations of
 * ListNode objects.)
 * 
 * Example 1:
 * 
 * 
 * Input: head = [1,2,-3,3,1]
 * Output: [3,1]
 * Note: The answer [1,2,1] would also be accepted.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: head = [1,2,3,-3,4]
 * Output: [1,2,4]
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: head = [1,2,3,-3,-2]
 * Output: [1]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The given linked list will contain between 1 and 1000 nodes.
 * Each node in the linked list has -1000 <= node.val <= 1000.
 * 
 * 
 */

/**
 * Definition for singly-linked list.
 */
#include<vector>
#include<unordered_map>
#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// @lc code=start
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {

        // 前缀和，
        // if sum(0, i)==sum(0, j)
        // sum(i, j)==0

        unordered_map<int, ListNode*> hash_map;

        ListNode dummy(0);
        dummy.next = head;
        
        ListNode* cur = &dummy;
        int sum = 0;
        while (cur) {
            sum += cur->val;
            if (hash_map.count(sum)) {
                ListNode* pre = hash_map[sum];
                ListNode* mid = pre->next;
                int mid_sum = sum;
                while (mid!=cur) {
                    mid_sum += mid->val;
                    hash_map.erase(mid_sum);
                    mid = mid->next;
                }
                pre->next = mid->next;
                // hash_map[sum]->next = cur->next;
                }
            else 
                hash_map[sum] = cur;
            cur = cur->next;
        }
        return dummy.next;
    }
};
// @lc code=end

int main() {
    Solution sol;

    vector<int> nums {1,3,2,-3,-2,5,5,-5,1};

    ListNode* head = new ListNode(1);
    ListNode* cur = head;
    for (int i=1; i<nums.size(); ++i) {
        cur->next = new ListNode(nums[i]);
        cur = cur->next;
    }
    ListNode* res = sol.removeZeroSumSublists(head);
    cout << "res=";
    cur = res;
    while (cur) {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;
    return 0;
}