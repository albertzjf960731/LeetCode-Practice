/*
 * @lc app=leetcode id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
 *
 * https://leetcode.com/problems/sliding-window-maximum/description/
 *
 * algorithms
 * Hard (40.57%)
 * Likes:    2511
 * Dislikes: 145
 * Total Accepted:    217.9K
 * Total Submissions: 536.7K
 * Testcase Example:  '[1,3,-1,-3,5,3,6,7]\n3'
 *
 * Given an array nums, there is a sliding window of size k which is moving
 * from the very left of the array to the very right. You can only see the k
 * numbers in the window. Each time the sliding window moves right by one
 * position. Return the max sliding window.
 * 
 * Example:
 * 
 * 
 * Input: nums = [1,3,-1,-3,5,3,6,7], and k = 3
 * Output: [3,3,5,5,6,7] 
 * Explanation: 
 * 
 * Window position                Max
 * ---------------               -----
 * [1  3  -1] -3  5  3  6  7       3
 * ⁠1 [3  -1  -3] 5  3  6  7       3
 * ⁠1  3 [-1  -3  5] 3  6  7       5
 * ⁠1  3  -1 [-3  5  3] 6  7       5
 * ⁠1  3  -1  -3 [5  3  6] 7       6
 * ⁠1  3  -1  -3  5 [3  6  7]      7
 * 
 * 
 * Note: 
 * You may assume k is always valid, 1 ≤ k ≤ input array's size for non-empty
 * array.
 * 
 * Follow up:
 * Could you solve it in linear time?
 */


#include<vector>
#include<deque>
#include<iostream>
#include<queue>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> queue;
        vector<int> res;
        
        // 单调队列
        for (int i=0; i<nums.size(); ++i) {
            while (!queue.empty() && nums[queue.back()]<nums[i]) 
                queue.pop_back();
            if (!queue.empty() && queue.front() == i-k)
                queue.pop_front();

            queue.push_back(i);
            
            if (i>=k-1)
                res.push_back(nums[queue.front()]);
        }
        return res;


	priority_queue<pair<int, int>> pq;
	vector<int> res;

	for (int i = 0; i<min(k, (int)nums.size()); i++)
		pq.push(make_pair(nums[i], i));
		
	if (!pq.empty())
		res.push_back(pq.top().first);

	for (int i=k; i<nums.size(); i++) {
		pq.push(make_pair(nums[i], i));

		while (pq.top().second <= i-k)
			pq.pop();

		res.push_back(pq.top().first);
	}

	return res;
    }
};
// @lc code=end

int main() {
    vector<vector<int>> nums{{5, 2, 7, 44, 12, 7}, 
                            {45, 44, 13, 4, 0, 34},
                            {5, 2, 7, 11, 16, 42},
                            {5, 23, 7, 0, 12, 7}, 
                            {15, 2, 3, 32, 8, 32}};
    Solution sol;

    vector<vector<int>> res;
    for (int i=0; i<nums.size(); ++i) {
        res.push_back(sol.maxSlidingWindow(nums[i], 3));
    }
    return 0;
}