/*
 * @lc app=leetcode id=1122 lang=cpp
 *
 * [1122] Relative Sort Array
 *
 * https://leetcode.com/problems/relative-sort-array/description/
 *
 * algorithms
 * Easy (67.23%)
 * Likes:    410
 * Dislikes: 30
 * Total Accepted:    39.2K
 * Total Submissions: 58.3K
 * Testcase Example:  '[2,3,1,3,2,4,6,7,9,2,19]\n[2,1,4,3,9,6]'
 *
 * Given two arrays arr1 and arr2, the elements of arr2 are distinct, and all
 * elements in arr2 are also in arr1.
 * 
 * Sort the elements of arr1 such that the relative ordering of items in arr1
 * are the same as in arr2.  Elements that don't appear in arr2 should be
 * placed at the end of arr1 in ascending order.
 * 
 * 
 * Example 1:
 * Input: arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
 * Output: [2,2,2,1,4,3,3,9,6,7,19]
 * 
 * 
 * Constraints:
 * 
 * 
 * arr1.length, arr2.length <= 1000
 * 0 <= arr1[i], arr2[i] <= 1000
 * Each arr2[i] is distinct.
 * Each arr2[i] is in arr1.
 * 
 * 
 */
#include<vector>
#include<map>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> hash_map;
        for (int num : nums1) 
            hash_map[num]++;

        int idx = 0;
        for (int num : nums2) {
            while(hash_map[num]-- > 0) 
                nums1[idx++] = num;
        }
        for (auto it : hash_map) {
            while(it.second-- > 0) 
                nums1[idx++] = it.first;
        }
        return nums1;
    }
};
// @lc code=end

