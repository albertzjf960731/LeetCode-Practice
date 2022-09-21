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
        
        string s = to_string(num);
        
        vector<int> idx(10, -1);
        for (int i=0; i<s.size(); ++i) 
            idx[s[i]-'0'] = i;
        
        for (int i=0; i<s.size(); ++i) {
            for (int j=9; j>(s[i]-'0'); --j) {
                if (idx[j] > i) {
                    swap(s[i], s[idx[j]]);
                    return stoi(s);
                }
            }
        }
        return num;
    }
};
// @lc code=end

