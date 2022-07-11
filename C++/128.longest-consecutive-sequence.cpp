/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 *
 * https://leetcode.com/problems/longest-consecutive-sequence/description/
 *
 * algorithms
 * Hard (43.79%)
 * Likes:    2604
 * Dislikes: 148
 * Total Accepted:    262K
 * Total Submissions: 598.2K
 * Testcase Example:  '[100,4,200,1,3,2]'
 *
 * Given an unsorted array of integers, find the length of the longest
 * consecutive elements sequence.
 * 
 * Your algorithm should run in O(n) complexity.
 * 
 * Example:
 * 
 * 
 * Input: [100, 4, 200, 1, 3, 2]
 * Output: 4
 * Explanation: The longest consecutive elements sequence is [1, 2, 3, 4].
 * Therefore its length is 4.
 * 
 * 
 */
#include<vector>
#include<unordered_set>
#include<unordered_map>
using namespace std;

// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // if (nums.empty()) return 0;
        
        // int ans = 1;
        // unordered_set<int> hash_set(nums.begin(), nums.end());
        // for (int num: nums) {
        //     if (!hash_set.count(num-1)) {
        //         int cnt = 0;
        //         while (num<INT_MAX && hash_set.count(num++)) 
        //             cnt ++;
        //         ans = max(ans, cnt);
        //     }
        // }
        // return ans;

        unordered_set<int> hset(nums.begin(), nums.end());
        
        int ans = 0;
        for (int num: nums) {
            if (!hset.count(num)) continue;
            
            hset.erase(num);

            int left = num - 1;
            while (hset.count(left)) hset.erase(left--);

            int right = num + 1;
            while (hset.count(right)) hset.erase(right++);

            ans = max(ans, right-left-1);
        }
        return ans;
        
        // int ans = 0;
        // unordered_map<int, int> hash_map;
        // for(int num: nums) {
        //     if (!hash_map.count(num)) {
        //         int left = hash_map.count(num-1) ? hash_map[num-1]:0;
        //         int right =  hash_map.count(num+1) ? hash_map[num+1]:0;
        //         int cnt = left + 1 + right;
                
        //         hash_map[num] = cnt;
        //         ans = max(ans, cnt);
                
        //         hash_map[num-left] = cnt;
        //         hash_map[num+right] = cnt;
                
        //     }
        // }
        // return ans;
    }
};
// @lc code=end

