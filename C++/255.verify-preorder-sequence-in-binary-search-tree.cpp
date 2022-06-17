/*
 * @lc app=leetcode id=255 lang=cpp
 *
 * [255] Verify Preorder Sequence in Binary Search Tree 
 * 
 * Given an array of numbers, verify whether it is the correct preorder traversal sequence of a binary search tree.
 * 
 * You may assume each number in the sequence is unique.
 * 
 * Consider the following binary search tree: 
 *      5
 *     / \
 *    2   6
 *   / \
 *  1   3
 * Example 1:
 * 
 * Input: [5,2,6,1,3]
 * Output: false
 * 
 * Example 2: 
 * Input: [5,2,1,3,6]
 * Output: true
 * Follow up:
 * Could you do it using only constant space complexity?
 * 
 * 
 *  
 */

#include<vector>
#include<stack>
#include<queue>
#include<stack>
#include<iostream>

using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// @lc code=start
class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        int root = INT_MIN;
        vector<int> stack;
        for (int num : preorder) {
            if (num < root) return false;

            while (!stack.empty() && num > stack.back()) {
                root = stack.back(); 
                stack.pop_back();
            }
            stack.push_back(num);
        }
        return true;
    }
    
    bool verifyPostorder(vector<int>& postorder) {
        vector<int> stack;

        int pre_elem = INT_MAX;
        for(int i = postorder.size() - 1; i >= 0; --i) {
            if(postorder[i] > pre_elem) return false;

            while(!stack.empty() && postorder[i] < stack.back()) {
                pre_elem = stack.back();
                stack.pop_back();
            }
            stack.push_back(postorder[i]);
        }
        return true;
    }


    bool verifyPreorder(vector<int>& preorder) {
        return DFS(preorder, 0, preorder.size()-1);
    }
    bool DFS(vector<int>& preorder, int left, int right) {
        if (left >= right) return true;

        int root = preorder[left];
       
        int idx = left+1;
        while (preorder[idx] < root) idx++;

        int tmp = idx;
        while (tmp < right) {
            if (preorder[tmp++] < root) 
                return false;
        }

        return DFS(preorder, left+1, idx-1) && 
               DFS(preorder, idx, right);
    }

};

// @lc code=end
