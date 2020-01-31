/*
 * @lc app=leetcode id=349 lang=cpp
 *
 * [349] Intersection of Two Arrays
 *
 * https://leetcode.com/problems/intersection-of-two-arrays/description/
 *
 * algorithms
 * Easy (58.16%)
 * Likes:    533
 * Dislikes: 953
 * Total Accepted:    278.7K
 * Total Submissions: 479.1K
 * Testcase Example:  '[1,2,2,1]\n[2,2]'
 *
 * Given two arrays, write a function to compute their intersection.
 * 
 * Example 1:
 * 
 * 
 * Input: nums1 = [1,2,2,1], nums2 = [2,2]
 * Output: [2]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 * Output: [9,4]
 * 
 * 
 * Note:
 * 
 * 
 * Each element in the result must be unique.
 * The result can be in any order.
 * 
 * 
 * 
 * 
 */
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1{nums1.begin(), nums1.end()};
        vector<int> res;

        for(int num:nums2) {
            // if(set1.count(num)) {
            //     res.push_back(num);
            //     set1.erase(num);
            // }
            if(set1.erase(num))
                res.push_back(num);
        }
        return res;
    }
};
// @lc code=end

