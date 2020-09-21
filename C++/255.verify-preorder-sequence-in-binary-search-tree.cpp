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
        int low = INT_MIN;
        vector<int> stack;
        for (int num : preorder) {
            if (num < low) return false;

            while (!stack.empty() && num > stack.back()) {
                low = stack.back(); 
                stack.pop_back();
            }
            stack.push_back(num);
        }
        return true;
    }

    bool verifyPreorder(vector<int>& preorder) {
        return DFS(preorder, 0, preorder.size()-1, INT_MIN, INT_MAX);
    }
    bool DFS(vector<int>& preorder, int start, int end, int lower, int upper) {
        if (start > end) return true;

        int num = preorder[start];
        if (num<=lower || num>=upper) return false;

        int i;
        for (i=start + 1; i <= end; ++i) {
            if (preorder[i] >= num) break;
        }
        return DFS(preorder, start+1, i-1, lower, num) && 
               DFS(preorder, i, end, num, upper);
    }

};

// @lc code=end
