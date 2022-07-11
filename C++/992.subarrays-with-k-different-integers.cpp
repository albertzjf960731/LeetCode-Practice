/*
 * @lc app=leetcode id=992 lang=cpp
 *
 * [992] Subarrays with K Different Integers
 *
 * https://leetcode.com/problems/subarrays-with-k-different-integers/description/
 *
 * algorithms
 * Hard (46.39%)
 * Likes:    677
 * Dislikes: 13
 * Total Accepted:    19K
 * Total Submissions: 41K
 * Testcase Example:  '[1,2,1,2,3]\n2'
 *
 * Given an array A of positive integers, call a (contiguous, not necessarily
 * distinct) subarray of A good if the number of different integers in that
 * subarray is exactly K.
 * 
 * (For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.)
 * 
 * Return the number of good subarrays of A.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: A = [1,2,1,2,3], K = 2
 * Output: 7
 * Explanation: Subarrays formed with exactly 2 different integers: [1,2],
 * [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: A = [1,2,1,3,4], K = 3
 * Output: 3
 * Explanation: Subarrays formed with exactly 3 different integers: [1,2,1,3],
 * [2,1,3], [1,3,4].
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= A.length <= 20000
 * 1 <= A[i] <= A.length
 * 1 <= K <= A.length
 * 
 */
#include<vector>
#include<unordered_map>
using namespace std;

// @lc code=start
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int ans = 0;
        
        unordered_map<int, int> hmap;
        for (int left=0, right=0, last=0; right<nums.size(); ++right) {
            
            hmap[nums[right]] += 1;
            
            if (hmap.size() < k) continue;
            
            while (hmap.size() > k) {
                hmap[nums[left]] -= 1;
                if (hmap[nums[left]] == 0) hmap.erase(nums[left]);
                left += 1;
                
                last = left;
            }
            
            while (hmap[nums[left]] > 1) {
                hmap[nums[left]] -= 1;
                left += 1;
            }
            ans += left - last + 1;
        }
        return ans;


        return atMostK(nums, k) - atMostK(nums, k-1);
    }
    
    int atMostK(vector<int>& nums, int k) {
        int ans = 0;
        
        unordered_map<int, int> hmap;
        for (int left=0, right=0; right<nums.size(); ++right) {
            
            hmap[nums[right]] += 1;
                        
            while (hmap.size() > k) {
                hmap[nums[left]] -= 1;
                if (hmap[nums[left]] == 0) hmap.erase(nums[left]);
                left += 1;
            }
            
            ans += right - left + 1;
        }
        return ans;
    }
};
// @lc code=end

