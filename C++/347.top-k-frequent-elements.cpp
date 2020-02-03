/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 *
 * https://leetcode.com/problems/top-k-frequent-elements/description/
 *
 * algorithms
 * Medium (58.60%)
 * Likes:    2290
 * Dislikes: 151
 * Total Accepted:    304.5K
 * Total Submissions: 519.4K
 * Testcase Example:  '[1,1,1,2,2,3]\n2'
 *
 * Given a non-empty array of integers, return the k most frequent elements.
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,1,1,2,2,3], k = 2
 * Output: [1,2]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1], k = 1
 * Output: [1]
 * 
 * 
 * Note: 
 * 
 * 
 * You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
 * Your algorithm's time complexity must be better than O(n log n), where n is
 * the array's size.
 * 
 * 
 */
#include<vector>
#include<unordered_map>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        for (int num: nums) 
            counts[num]++;
        
        // vector<vector<int>> buckets(nums.size()+1);
        // for(auto it=counts.begin(); it!=counts.end(); ++it)
        //     buckets[it->second].push_back(it->first);
        
        unordered_map<int, vector<int>> buckets;
        for(auto it=counts.begin(); it!=counts.end(); ++it)
            buckets[it->second].push_back(it->first);

        vector<int> res;
        for (int count=nums.size(); count>0; count--) {
            if (buckets.count(count)) {
                for (int num: buckets[count]) 
                    res.push_back(num);
            }
            if (res.size()>=k)
                break;
        }
        return res;
    }
};
// @lc code=end

