/*
 * @lc app=leetcode id=179 lang=cpp
 *
 * [179] Largest Number
 *
 * https://leetcode.com/problems/largest-number/description/
 *
 * algorithms
 * Medium (26.99%)
 * Likes:    1338
 * Dislikes: 167
 * Total Accepted:    150.8K
 * Total Submissions: 558.6K
 * Testcase Example:  '[10,2]'
 *
 * Given a list of non negative integers, arrange them such that they form the
 * largest number.
 * 
 * Example 1:
 * 
 * 
 * Input: [10,2]
 * Output: "210"
 * 
 * Example 2:
 * 
 * 
 * Input: [3,30,34,5,9]
 * Output: "9534330"
 * 
 * 
 * Note: The result may be very large, so you need to return a string instead
 * of an integer.
 * 
 */
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    static bool cmp(int m, int n) {
        return to_string(m)+to_string(n) > to_string(n)+to_string(m);
    }
    string largestNumber(vector<int>& nums) {
        string ans ;
        sort(nums.begin(), nums.end(), cmp);
        // sort(nums.begin(), nums.end(), 
        //     [](const int &m, const int&n) {
        //         return to_string(m)+to_string(n) > to_string(n)+to_string(m);
        //     });

        for(int i=0;i<nums.size();++i){
            ans+=to_string(nums[i]);
        }
        if(ans[0]=='0')
            return "0";
        return ans;
    }
};
// @lc code=end

