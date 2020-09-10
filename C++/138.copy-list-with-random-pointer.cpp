/*
 * @lc app=leetcode id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 *
 * https://leetcode.com/problems/copy-list-with-random-pointer/description/
 *
 * algorithms
 * Medium (32.16%)
 * Likes:    2471
 * Dislikes: 570
 * Total Accepted:    341K
 * Total Submissions: 1.1M
 * Testcase Example:  '[[7,null],[13,0],[11,4],[10,2],[1,0]]\r'
 *
 * A linked list is given such that each node contains an additional random
 * pointer which could point to any node in the list or null.
 * 
 * Return a deep copy of the list.
 * 
 * The Linked List is represented in the input/output as a list of n nodes.
 * Each node is represented as a pair of [val, random_index] where:
 * 
 * 
 * val: an integer representing Node.val
 * random_index: the index of the node (range from 0 to n-1) where random
 * pointer points to, or null if it does not point to any node.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
 * Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: head = [[1,1],[2,1]]
 * Output: [[1,1],[2,1]]
 * 
 * 
 * Example 3:
 * 
 * 
 * 
 * 
 * Input: head = [[3,null],[3,0],[3,null]]
 * Output: [[3,null],[3,0],[3,null]]
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: head = []
 * Output: []
 * Explanation: Given linked list is empty (null pointer), so return null.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * -10000 <= Node.val <= 10000
 * Node.random is null or pointing to a node in the linked list.
 * Number of Nodes will not exceed 1000.
 * 
 * 
 */

/*
// Definition for a Node.
*/
#include<vector>
#include<unordered_map>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
// @lc code=start
class Solution {
public:
    // Node* copyRandomList(Node* head) {
    //     if(head==NULL) return head;
    //     Node *head2, *l1, *l2;
        
    //     // Build the 2nd list by creating a new node for each node in 1st list. 
    //     // While doing so, insert each new node after it's corresponding node in the 1st list.
    //     for (l1=head; l1!=NULL; l1=l1->next->next) {
    //         l2 = new Node(l1->val);
    //         l2->next = l1->next;
    //         l1->next = l2;
    //     }
        
    //     // The new head is the 2nd node as that was the first inserted node.
    //     head2 = head->next;

    //     // Fix the random pointers in the 2nd list: (Remember that l1->next is actually l2)
    //     // l2->random will be the node in 2nd list that corresponds l1->random, which is next node of l1->random.
    //     for(l1=head; l1!=NULL; l1=l1->next->next) {
    //         if (l1->random!=NULL)
    //             l1->next->random = l1->random->next;
    //     }

    //     // Separate the combined list into 2: Splice out nodes that are part of second list. 
    //     for (l1=head; l1!=NULL; l1=l1->next) {
    //         l2 = l1->next;
    //         l1->next = l2->next;
    //         if(l2->next!=NULL) 
    //             l2->next = l2->next->next;
    //     }

    //     // Return the new head that we saved in step 2.
    //     return head2;
    // }

    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        Node *head2 = new Node(head->val);
        unordered_map<Node*, Node*> hash_map;
        hash_map[head] = head2;

        Node *cur2 = head2, *cur1 = head->next;
        while (cur1) {
            Node *node = new Node(cur1->val);
            cur2->next = node;
            hash_map[cur1] = node;
            
            cur2 = cur2->next;
            cur1 = cur1->next;
        }

        cur2 = head2; cur1 = head;
        while (cur1) {
            cur2->random = hash_map[cur1->random];
            cur2 = cur2->next;
            cur1 = cur1->next;
        }
        return head2;
    }
};
// @lc code=end

