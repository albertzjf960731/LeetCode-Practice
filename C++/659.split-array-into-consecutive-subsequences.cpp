/*
 * @lc app=leetcode id=659 lang=cpp
 *
 * [659] Split Array into Consecutive Subsequences
 *
 * https://leetcode.com/problems/split-array-into-consecutive-subsequences/description/
 *
 * algorithms
 * Medium (42.70%)
 * Likes:    810
 * Dislikes: 311
 * Total Accepted:    33.1K
 * Total Submissions: 77.6K
 * Testcase Example:  '[1,2,3,3,4,5]'
 *
 * Given an array nums sorted in ascending order, return true if and only if
 * you can split it into 1 or more subsequences such that each subsequence
 * consists of consecutive integers and has length at least 3.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,3,3,4,5]
 * Output: True
 * Explanation:
 * You can split them into two consecutive subsequences : 
 * 1, 2, 3
 * 3, 4, 5
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [1,2,3,3,4,4,5,5]
 * Output: True
 * Explanation:
 * You can split them into two consecutive subsequences : 
 * 1, 2, 3, 4, 5
 * 3, 4, 5
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: [1,2,3,4,4,5]
 * Output: False
 * 
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10000
 * 
 * 
 * 
 * 
 */
#include<vector>
#include<unordered_map>
using namespace std;

// @lc code=start
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int> cnt, tails;
        for(int i : nums) cnt[i]++;
        
        for(int i: nums){
            if(!cnt[i]) continue;
            
            cnt[i]--;
            // cout << "tails.count(" << i-1 << ")=" << tails.count(i-1) << " ";
            // cout << "tails["<<i-1<<"]=" << tails[i-1] << endl;

            if(tails[i-1]>0){
                tails[i-1]--;
                tails[i]++;
            }
            else if (cnt[i+1] && cnt[i+2]){
                cnt[i+1]--;
                cnt[i+2]--;
                tails[i+2]++;
            }
            else return false;
        }
        return true;
    }
};
// @lc code=end

