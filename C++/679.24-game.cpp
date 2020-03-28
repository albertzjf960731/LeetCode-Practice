/*
 * @lc app=leetcode id=679 lang=cpp
 *
 * [679] 24 Game
 *
 * https://leetcode.com/problems/24-game/description/
 *
 * algorithms
 * Hard (45.02%)
 * Likes:    595
 * Dislikes: 120
 * Total Accepted:    33.2K
 * Total Submissions: 73.3K
 * Testcase Example:  '[4,1,8,7]'
 *
 * 
 * You have 4 cards each containing a number from 1 to 9.  You need to judge
 * whether they could operated through *, /, +, -, (, ) to get the value of
 * 24.
 * 
 * 
 * Example 1:
 * 
 * Input: [4, 1, 8, 7]
 * Output: True
 * Explanation: (8-4) * (7-1) = 24
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: [1, 2, 1, 2]
 * Output: False
 * 
 * 
 * 
 * Note:
 * 
 * The division operator / represents real division, not integer division.  For
 * example, 4 / (1 - 2/3) = 12.
 * Every operation done is between two numbers.  In particular, we cannot use -
 * as a unary operator.  For example, with [1, 1, 1, 1] as input, the
 * expression -1 - 1 - 1 - 1 is not allowed.
 * You cannot concatenate numbers together.  For example, if the input is [1,
 * 2, 1, 2], we cannot write this as 12 + 12.
 * 
 * 
 * 
 */
#include<vector>
#include<cmath>
using namespace std;

// @lc code=start
class Solution {
private:
    const double eps = 0.001;

public:
    bool judgePoint24(vector<int>& nums) {
        bool ans = false;
        vector<double> arr(nums.begin(), nums.end());
        DFS(arr, ans);
        return ans;
    }
    void DFS(vector<double>& nums, bool& ans) {
        if (ans) return;
        
        if (nums.size()==1) {
            if (abs(nums[0]) < eps) 
                ans = true;
            return;
        }
        
        for (int i=0; i<nums.size(); ++i) {
            for (int j=0; j<i; ++j) {
                
                double p = nums[i], q = nums[j];
                vector<double> tmp{p + q, p - q, q - p, p * q};
                if (p > eps) tmp.push_back(q / p);
                if (q > eps) tmp.push_back(p / q);
                
                nums.erase(nums.begin()+i);
                nums.erase(nums.begin()+j);
                
                for (double d: tmp) {
                    nums.push_back(d);
                    DFS(nums, ans);
                    nums.pop_back();
                }
                
                nums.insert(nums.begin()+j, q);
                nums.insert(nums.begin()+i, p);
            }
        }
    }
};
// @lc code=end

