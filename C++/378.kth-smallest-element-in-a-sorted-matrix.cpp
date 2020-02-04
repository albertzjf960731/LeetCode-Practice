/*
 * @lc app=leetcode id=378 lang=cpp
 *
 * [378] Kth Smallest Element in a Sorted Matrix
 *
 * https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/description/
 *
 * algorithms
 * Medium (51.74%)
 * Likes:    1736
 * Dislikes: 101
 * Total Accepted:    149.7K
 * Total Submissions: 288K
 * Testcase Example:  '[[1,5,9],[10,11,13],[12,13,15]]\n8'
 *
 * Given a n x n matrix where each of the rows and columns are sorted in
 * ascending order, find the kth smallest element in the matrix.
 * 
 * 
 * Note that it is the kth smallest element in the sorted order, not the kth
 * distinct element.
 * 
 * 
 * Example:
 * 
 * matrix = [
 * ⁠  [ 1,  5,  9],
 * ⁠  [10, 11, 13],
 * ⁠  [12, 13, 15]
 * ],
 * k = 8,
 * 
 * return 13.
 * 
 * 
 * 
 * Note: 
 * You may assume k is always valid, 1 ≤ k ≤ n^2.
 */
#include<queue>
#include<vector>
#include<iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        // max heap
        // priority_queue<int> pq;
        // for (int i=0; i<matrix.size(); ++i){
        //     for (int j=0; j<matrix[0].size(); ++j){
        //         pq.push(matrix[i][j]);
        //         if (pq.size()>k)
        //             pq.pop();
        //     }
        // }
        // return pq.top();

        int n = matrix.size();
        int left = matrix[0][0], right = matrix[n-1][n-1];
        while (left < right) {
            int mid = left + (right-left)/2;
            
            // int count = 0;
            // for (int i=0; i<n; ++i) {
            //     auto pos = upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            //     count += pos; 
            // }
            
            int count = 0;
            for (int i=0, j=n-1; i<n; ++i) {
                while (j>=0 && matrix[i][j]>mid) 
                    j--;
                count += j+1;
            }

            if (count < k)
                left = mid+1;
            else 
                right = mid;
        }
        return left;
    }
};
// @lc code=end

int main() {
    Solution sol;
    vector<vector<int>> nums{{1,5,9}, {10,11,13},{12,13,15}};
    cout << sol.kthSmallest(nums, 8) << endl;
    return 0;
}