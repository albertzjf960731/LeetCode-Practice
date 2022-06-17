/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
 */

#include<queue>
#include<tuple>
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

    // static bool cmp(ListNode* a, ListNode* b) {
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




class Solution {
public:

    vector<int> mergekSortedArrays(vector<vector<int>> &arrays) {
        
        struct heapComp {
            // to ensure a min-heap, otherwise it is max-heap by default
            bool operator() (tuple<int, int, int> &a, tuple<int, int, int> &b) {
                return get<2>(a) > get<2>(b);  
            }
        };

        tuple<int, int,  int>  tp;   //tuple<i,j,k> => k = arrays[i][j]
        priority_queue<tuple<int, int, int>, vector<tuple<int, int ,int>>, heapComp> pq;
        vector<int> result;
        
        int arrayLen = arrays.size();
        for (int i  = 0; i < arrayLen; ++i) {
            if (arrays[i].size() != 0) {
                pq.push(make_tuple(i, 0, arrays[i][0]));
            }
        }
        
        while(!pq.empty()) {
            tuple<int, int, int> elem = pq.top();
            pq.pop();
            result.push_back(get<2>(elem));
            get<1>(elem)++;
            if (get<1>(elem) < arrays[get<0>(elem)].size()) {
                pq.push(make_tuple(get<0>(elem),
                                   get<1>(elem),
                                   arrays[get<0>(elem)][get<1>(elem)]));
            }
            
        }
        
        return result;
    }
};