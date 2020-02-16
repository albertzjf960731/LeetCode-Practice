/*
 * @lc app=leetcode id=923 lang=cpp
 *
 * [923] 3Sum With Multiplicity
 *
 * https://leetcode.com/problems/3sum-with-multiplicity/description/
 *
 * algorithms
 * Medium (35.18%)
 * Likes:    275
 * Dislikes: 53
 * Total Accepted:    15.9K
 * Total Submissions: 45.3K
 * Testcase Example:  '[1,1,2,2,3,3,4,4,5,5]\n8'
 *
 * Given an integer array A, and an integer target, return the number of tuples
 * i, j, k  such that i < j < k and A[i] + A[j] + A[k] == target.
 * 
 * As the answer can be very large, return it modulo 10^9 + 7.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: A = [1,1,2,2,3,3,4,4,5,5], target = 8
 * Output: 20
 * Explanation: 
 * Enumerating by the values (A[i], A[j], A[k]):
 * (1, 2, 5) occurs 8 times;
 * (1, 3, 4) occurs 8 times;
 * (2, 2, 4) occurs 2 times;
 * (2, 3, 3) occurs 2 times.
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: A = [1,1,2,2,2,2], target = 5
 * Output: 12
 * Explanation: 
 * A[i] = 1, A[j] = A[k] = 2 occurs 12 times:
 * We choose one 1 from [1,1] in 2 ways,
 * and two 2s from [2,2,2,2] in 6 ways.
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 3 <= A.length <= 3000
 * 0 <= A[i] <= 100
 * 0 <= target <= 300
 * 
 */
#include<vector>
#include<unordered_map>
using namespace std;

// @lc code=start
class Solution {
public:
    int threeSumMulti(vector<int>& nums, int target) {
        unordered_map<int, long> cnt;
        for (int num : nums) cnt[num]++;
        
        int ans=0, mode=1e9+7;
        for (auto it1 : cnt)
            for (auto it2 : cnt) {
                int i = it1.first, j = it2.first;
                int k = target - i - j;
                if (!cnt.count(k)) continue;
                if (i==j && j==k)
                    ans += (cnt[i] * (cnt[i]-1) * (cnt[i]-2) / 6) % mode;
                else if (i==j && j!=k)
                    ans += (cnt[i] * (cnt[i]-1) / 2 * cnt[k]) % mode;
                else if (i<j && j<k)
                    ans += (cnt[i] * cnt[j] * cnt[k]) % mode;
            }
        return ans;
    }
};
// @lc code=end

