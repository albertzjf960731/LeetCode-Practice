/*
 * @lc app=leetcode id=164 lang=cpp
 *
 * [164] Maximum Gap
 *
 * https://leetcode.com/problems/maximum-gap/description/
 *
 * algorithms
 * Hard (33.82%)
 * Likes:    632
 * Dislikes: 154
 * Total Accepted:    78.4K
 * Total Submissions: 231.6K
 * Testcase Example:  '[3,6,9,1]'
 *
 * Given an unsorted array, find the maximum difference between the successive
 * elements in its sorted form.
 * 
 * Return 0 if the array contains less than 2 elements.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,6,9,1]
 * Output: 3
 * Explanation: The sorted form of the array is [1,3,6,9], either
 * (3,6) or (6,9) has the maximum difference 3.
 * 
 * Example 2:
 * 
 * 
 * Input: [10]
 * Output: 0
 * Explanation: The array contains less than 2 elements, therefore return 0.
 * 
 * Note:
 * 
 * 
 * You may assume all elements in the array are non-negative integers and fit
 * in the 32-bit signed integer range.
 * Try to solve it in linear time/space.
 * 
 * 
 */
#include<vector>  
#include<algorithm>
using namespace std;

// @lc code=start
class Bucket {
public:
    bool used = false;
    int minval = numeric_limits<int>::max(); // same as INT_MIN
    int maxval = numeric_limits<int>::min(); // same as INT_MAX
};

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        // if (nums.empty() || nums.size()==1)
        //     return 0;

        // int minNum = *min_element(nums.begin(), nums.end()); 
        // int maxNum = *max_element(nums.begin(), nums.end());
        // int bucketSize = max(1, (maxNum-minNum) / (int)(nums.size()-1));
        // int bucketNum = (maxNum-minNum)/bucketSize+1;

        // vector<Bucket> buckets(bucketNum);

        // for(int num:nums) {
        //     int idx = (num-minNum)/bucketSize;
        //     buckets[idx].used = true;
        //     buckets[idx].minval = min(num, buckets[idx].minval);
        //     buckets[idx].maxval = max(num, buckets[idx].maxval);
        // }

        // int pre = minNum, ans = 0;
        // for(auto bucket: buckets) {
        //     if (!bucket.used)
        //         continue;
        //     ans = max(ans, bucket.minval-pre);
        //     pre = bucket.maxval;
        // }

        // return ans;
        
        if (nums.size() <= 1) return 0;
        
        int mx = INT_MIN, mn = INT_MAX;
        for (int num: nums) {
            mx = max(mx, num);
            mn = min(mn, num);
        }
                
        int size = (mx-mn)/nums.size() + 1, cnt = (mx-mn)/size + 1;
        vector<int> bucket_min(cnt, INT_MAX), bucket_max(cnt, INT_MIN);
        for (int num: nums) {
            int idx = (num - mn) / size;
            bucket_min[idx] = min(bucket_min[idx], num);
            bucket_max[idx] = max(bucket_max[idx], num);
        }
        
        int ans = 0;
        for (int i=1, pre=0; i < cnt; ++i) {
            if (bucket_min[i] == INT_MAX || bucket_max[i] == INT_MIN) continue;
            ans = max(ans, bucket_min[i] - bucket_max[pre]);
            pre = i;
        }
        return ans;
    }
};
// @lc code=end

