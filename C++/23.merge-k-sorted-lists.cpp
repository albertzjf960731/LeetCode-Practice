/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
 */

#include<queue>
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

    // static bool heapComp(ListNode* a, ListNode* b) {
    //         return a->val > b->val;
    // }

    // ListNode* mergeKLists(vector<ListNode*>& lists) {
    //     vector<ListNode*> queue;
    //     for(int i=0; i<lists.size(); i++){
    //         if(lists[i]) queue.push_back(lists[i]);
    //     }
    //     make_heap(queue.begin(), queue.end(), heapComp);


    //     ListNode dummy(0), *cur=&dummy;

    //     while(queue.size()>0) {
    //         cur->next = queue.front();

    //         pop_heap(queue.begin(), queue.end(), heapComp);
    //         queue.pop_back();

    //         cur = cur->next;
    //         if(cur->next) {
    //             queue.push_back(cur->next);
    //             push_heap(queue.begin(), queue.end(), heapComp);
    //         }
    //     }
    //     return dummy.next;

    struct heapComp {
        bool operator()(const ListNode* l, const ListNode* r) {
            return l->val > r->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        priority_queue<ListNode*, vector<ListNode*>, heapComp> queue;
        for (ListNode* node: lists){
            if(node) queue.push(node);
        }

        ListNode dummy(0), *cur = &dummy;

        while(!queue.empty()) {
            cur->next = queue.top();
            queue.pop();
            cur = cur->next;
            if(cur->next) queue.push(cur->next);
        }
        return dummy.next;
    }
};
// @lc code=end

