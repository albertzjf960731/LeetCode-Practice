/*
 * @lc app=leetcode id=719 lang=cpp
 *
 * [719] Find K-th Smallest Pair Distance
 *
 * https://leetcode.com/problems/find-k-th-smallest-pair-distance/description/
 *
 * algorithms
 * Hard (30.28%)
 * Likes:    716
 * Dislikes: 24
 * Total Accepted:    26.1K
 * Total Submissions: 85.8K
 * Testcase Example:  '[1,3,1]\n1'
 *
 * Given an integer array, return the k-th smallest distance among all the
 * pairs. The distance of a pair (A, B) is defined as the absolute difference
 * between A and B. 
 * 
 * Example 1:
 * 
 * Input:
 * nums = [1,3,1]
 * k = 1
 * Output: 0 
 * Explanation:
 * Here are all the pairs:
 * (1,3) -> 2
 * (1,1) -> 0
 * (3,1) -> 2
 * Then the 1st smallest distance pair is (1,1), and its distance is 0.
 * 
 * 
 * 
 * Note:
 * 
 * 2 .
 * 0 .
 * 1 .
 * 
 * 
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        // int N = 1000000;
        // vector<int> dist(N, 0);
        // for (int i=0; i<nums.size()-1; ++i) {
        //     for (int j=i+1; j<nums.size(); ++j)
        //         dist[abs(nums[i]-nums[j])]++;
        // }
        // int ans;
        // for (int i=0; i<N; ++i){
        //     if (dist[i]>=k) return i;
        //     k-=dist[i];
        // }
        // return 0;



        sort(nums.begin(), nums.end());

        int N = nums.size(), low = 0, high = nums.back()-nums[0];
        while (low < high) {
            int mid = (low+high) / 2;
            int count = 0;  

            // sliding window
            int left=0, right=0;
            while (right<N) {
            // for (int left=0, right=0; right<N; right++) {
                while (nums[right]-nums[left]>mid)
                    left++;
                count += right-left;
                right++;
            }
            
            // 左边界
            if (count < k) 
                low = mid + 1;
            else 
                high = mid;
        }  
        return low;
    }
};
// @lc code=end

