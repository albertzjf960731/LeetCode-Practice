/*
 * @lc app=leetcode id=373 lang=cpp
 *
 * [373] Find K Pairs with Smallest Sums
 *
 * https://leetcode.com/problems/find-k-pairs-with-smallest-sums/description/
 *
 * algorithms
 * Medium (35.10%)
 * Likes:    977
 * Dislikes: 81
 * Total Accepted:    84.1K
 * Total Submissions: 238.7K
 * Testcase Example:  '[1,7,11]\n[2,4,6]\n3'
 *
 * You are given two integer arrays nums1 and nums2 sorted in ascending order
 * and an integer k.
 * 
 * Define a pair (u,v) which consists of one element from the first array and
 * one element from the second array.
 * 
 * Find the k pairs (u1,v1),(u2,v2) ...(uk,vk) with the smallest sums.
 * 
 * Example 1:
 * 
 * 
 * Input: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
 * Output: [[1,2],[1,4],[1,6]] 
 * Explanation: The first 3 pairs are returned from the sequence: 
 * [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
 * 
 * Example 2:
 * 
 * 
 * Input: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
 * Output: [1,1],[1,1]
 * Explanation: The first 2 pairs are returned from the sequence: 
 * [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
 * 
 * Example 3:
 * 
 * 
 * Input: nums1 = [1,2], nums2 = [3], k = 3
 * Output: [1,3],[2,3]
 * Explanation: All possible pairs are returned from the sequence: [1,3],[2,3]
 * 
 * 
 */
#include<vector>
#include<queue>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        // vector<vector<int>> res;

		// priority_queue< pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int, int>>> > pq;
		
        // for(int i=0; i<nums1.size();i++) {
		// 	for(int j=0;j<nums2.size();j++) {
		// 		pq.push(make_pair(nums1[i]+nums2[j], make_pair(nums1[i], nums2[j])));
		// 	}
		// } 

		// while(!pq.empty() && k--) {
		// 	res.push_back({pq.top().second.first, pq.top().second.second});
		// 	pq.pop();
		// }	

        // return res;

        if (nums1.empty() || nums2.empty() || k==0)
            return {};

        vector<vector<int>> res;
        
        auto cmp = [&nums1, &nums2](pair<int, int> a, pair<int, int> b) {
            return nums1[a.first]+nums2[a.second] > nums1[b.first]+nums2[b.second];
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);

        for (int i=0; i<nums1.size(); i++) 
            pq.push(make_pair(i, 0));
        while (k-- > 0 && !pq.empty()) {
            auto it = pq.top();
            pq.pop();
            if(it.second+1<nums2.size())
                pq.push(make_pair(it.first, it.second+1));
            res.push_back({nums1[it.first], nums2[it.second]});
        }
        return res;


        // vector<vector<int>> res;
        // int size1=nums1.size(), size2=nums2.size();
        
        // if (size1==0 || size2==0) return res;
        
        // int left=nums1[0]+nums2[0], right=nums1.back()+nums2.back(), mid;
        // while (left<right) {
        //     mid = left + (right-left)/2;

        //     int count = 0;
        //     for (int i=0, j=size2-1; i<size1; ++i) {
        //         while (j>=0 && nums1[i]+nums2[j]>mid) 
        //             j--;
        //         count += j+1;
        //     }
        //     if (count<k) 
        //         left = mid+1;
        //     else 
        //         right = mid;
        // }
        // return res;
    }
};
// @lc code=end

