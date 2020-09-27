/*
 * @lc app=leetcode id=670 lang=cpp
 *
 * [670] Maximum Swap
 *
 * https://leetcode.com/problems/maximum-swap/description/
 *
 * algorithms
 * Medium (43.85%)
 * Likes:    1145
 * Dislikes: 76
 * Total Accepted:    76.9K
 * Total Submissions: 174.6K
 * Testcase Example:  '2736'
 *
 * 
 * Given a non-negative integer, you could swap two digits at most once to get
 * the maximum valued number. Return the maximum valued number you could get.
 * 
 * 
 * Example 1:
 * 
 * Input: 2736
 * Output: 7236
 * Explanation: Swap the number 2 and the number 7.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: 9973
 * Output: 9973
 * Explanation: No swap.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * The given number is in the range [0, 10^8]
 * 
 * 
 */
#include<string>
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int maximumSwap(int num) {
        // string str = to_string(num);
        // int ans = num, n=str.size();
        // for (int i=0; i<n; ++i) {
        //     for (int j=i+1; j<n; ++j) {
        //         swap(str[i], str[j]);
        //         ans = max(ans, stoi(str));
        //         swap(str[i], str[j]);
        //     }
        // }
        // return ans;
        string str = to_string(num);
        vector<int> buckets(10, 0);
        for (int i=0; i<str.size(); ++i) {
            buckets[str[i]-'0'] = i;
        }
        
        for (int i=0; i<str.size(); ++i) {
            for (int k=9; k>str[i]-'0'; --k) {
                if (buckets[k] <= i) continue;
                swap(str[i], str[buckets[k]]);
                return stoi(str);
            }
        }
        return num;
    }
};
// @lc code=end

