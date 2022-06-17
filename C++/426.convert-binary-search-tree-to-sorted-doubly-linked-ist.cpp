/*
 * @lc app=leetcode id=426 lang=cpp
 *
 * [426] Convert Binary Search Tree to Sorted Doubly Linked List
 *
 * https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/
 *
 * algorithms
 * Medium (45.32%)
 * Likes:    1992
 * Dislikes: 257
 * Total Accepted:    284.9K
 * Total Submissions: 626.7K
 * Testcase Example:  '[1,2,5,3,4,null,6]'
 * 
 * Convert a BST to a sorted circular doubly-linked list in-place. Think of the left and right pointers as synonymous to the previous and next pointers in a doubly-linked list.
 * 
 * Let's take the following BST as an example, it may help you understand the problem better:
 * 
 * We want to transform this BST into a circular doubly linked list. Each node in a doubly linked list has a predecessor and successor. For a circular doubly linked list, the predecessor of the first element is the last element, and the successor of the last element is the first element.
 * 
 * The figure below shows the circular doubly linked list for the BST above. The "head" symbol means the node it points to is the smallest element of the linked list.
 * 
 * Specifically, we want to do the transformation in place. After the transformation, the left pointer of the tree node should point to its predecessor, and the right pointer should point to its successor. We should return the pointer to the first element of the linked list.
 * 
 * The figure below shows the transformed BST. The solid line indicates the successor relationship, while the dashed line means the predecessor relationship.
 * 
 * 
 */
/**
 * Definition for a binary tree node.
 */
#include<vector>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if (!root) return NULL;
        Node *head = NULL, *pre = NULL;
        vector<Node*> stack;
        while (root || !stack.empty()) {
            while (root) {
                stack.push_back(root);
                root = root->left;
            }
            root = stack.back(); stack.pop_back();
            if (!head) head = root;
            if (pre) {
                pre->right = root;
                root->left = pre;
            }
            pre = root;
            root = root->right;
        }
        head->left = pre;
        pre->right = head;
        return head;
    }
};
// @lc code=end

// TreeNode* createTree(vector<int>& nums) {
//     int n = nums.size();

//     if (n==0) return NULL;

//     vector<TreeNode*> tree(n);
//     for(int i=0; i<n; i++) {
//         if (nums[i]==-1){
//             tree[i] = NULL;
//             continue;
//         }
//         tree[i] = new TreeNode(nums[i]);
//     }
    
//     int pos=1;
//     for(int i=0; i<n && pos<n; i++) {
//         if (tree[i]){
//             tree[i]->left = tree[pos++];
//             if (pos<n){
//                 tree[i]->right = tree[pos++];
//             }
//         }
//     }
//     return tree[0];
// }


// int main() {
//     vector<int> nums{1, 2, 3, -1, 4, -1, -1};
//     TreeNode* root = createTree(nums);
// }