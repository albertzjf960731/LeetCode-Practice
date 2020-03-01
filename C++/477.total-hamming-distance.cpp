/*
 * @lc app=leetcode id=477 lang=cpp
 *
 * [477] Total Hamming Distance
 *
 * https://leetcode.com/problems/total-hamming-distance/description/
 *
 * algorithms
 * Medium (50.20%)
 * Likes:    682
 * Dislikes: 48
 * Total Accepted:    57.1K
 * Total Submissions: 113.8K
 * Testcase Example:  '[4,14,2]'
 *
 * The Hamming distance between two integers is the number of positions at
 * which the corresponding bits are different.
 * 
 * Now your job is to find the total Hamming distance between all pairs of the
 * given numbers.
 * 
 * 
 * Example:
 * 
 * Input: 4, 14, 2
 * 
 * Output: 6
 * 
 * Explanation: In binary representation, the 4 is 0100, 14 is 1110, and 2 is
 * 0010 (just
 * showing the four bits relevant in this case). So the answer will be:
 * HammingDistance(4, 14) + HammingDistance(4, 2) + HammingDistance(14, 2) = 2
 * + 2 + 2 = 6.
 * 
 * 
 * 
 * Note:
 * 
 * Elements of the given array are in the range of 0  to 10^9
 * Length of the array will not exceed 10^4. 
 * 
 * 
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        if (nums.empty())
            return 0;
        
        int ans = 0;        
        for(int i=0; i<32; i++) {
            
            int cnt = 0;
            for(int j=0; j<nums.size(); j++) {
                if (nums[j] & (1<<i)) 
                    cnt++;
            }
            
            ans += cnt * (nums.size()-cnt);
        }
        
        return ans;
    }
};
// @lc code=end

