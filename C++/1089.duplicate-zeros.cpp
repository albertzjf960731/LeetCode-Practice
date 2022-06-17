/*
 * @lc app=leetcode id=1089 lang=cpp
 *
 * [1089] Duplicate Zeros
 *
 * https://leetcode.com/problems/duplicate-zeros/description/
 *
 * algorithms
 * Easy (51.20%)
 * Likes:    1731
 * Dislikes: 547
 * Total Accepted:    278.8K
 * Total Submissions: 544K
 * Testcase Example:  '[1,0,2,3,0,4,5,0]'
 *
 * Given a fixed-length integer array arr, duplicate each occurrence of zero,
 * shifting the remaining elements to the right.
 * 
 * Note that elements beyond the length of the original array are not written.
 * Do the above modifications to the input array in place and do not return
 * anything.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: arr = [1,0,2,3,0,4,5,0]
 * Output: [1,0,0,2,3,0,0,4]
 * Explanation: After calling your function, the input array is modified to:
 * [1,0,0,2,3,0,0,4]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: arr = [1,2,3]
 * Output: [1,2,3]
 * Explanation: After calling your function, the input array is modified to:
 * [1,2,3]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= arr.length <= 10^4
 * 0 <= arr[i] <= 9
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        int m = n + count(arr.begin(), arr.end(), 0);
        
        for (int i=n-1, j=m-1; i>=0; i--, j--) {
            
            if (j < n) arr[j] = arr[i];
            
            if (arr[i] == 0) {
                j--;
                if (j < n) arr[j] = 0;
            }
        }
    }
};
// @lc code=end

