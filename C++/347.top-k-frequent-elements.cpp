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
        unordered_map<int, int> cnts;
        for (int num: nums) cnts[num] += 1;

        vector<vector<int>> bins(nums.size()+1);
        for (auto& [num, cnt]: cnts) bins[cnt].push_back(num);

        vector<int> ans;
        for (int i=nums.size(); i>=0; --i) {
            if (bins[i].empty()) continue;
            
            ans.insert(ans.end(), bins[i].begin(), bins[i].end());
            if (ans.size() >= k) break;
        }
        return ans;

    }
};
// @lc code=end

