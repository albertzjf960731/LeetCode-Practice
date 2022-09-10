/*
 * @lc app=leetcode id=326 lang=cpp
 *
 * [326] Power of Three
 *
 * https://leetcode.com/problems/power-of-three/description/
 *
 * algorithms
 * Easy (43.80%)
 * Likes:    1257
 * Dislikes: 146
 * Total Accepted:    504.5K
 * Total Submissions: 1.2M
 * Testcase Example:  '27'
 *
 * Given an integer n, return true if it is a power of three. Otherwise, return
 * false.
 * 
 * An integer n is a power of three, if there exists an integer x such that n
 * == 3^x.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 27
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 0
 * Output: false
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: n = 9
 * Output: true
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * -2^31 <= n <= 2^31 - 1
 * 
 * 
 * 
 * Follow up: Could you solve it without loops/recursion?
 */

// @lc code=start
class NumArray {
public:
    bool isPowerOfThree(int n) {
//         unordered_set<int> hset;
        
//         int num = 1;
//         hset.insert(num);
//         while (num < (INT_MAX/3)) {
//             num *= 3;
//             hset.insert(num);
//         }
        
        unordered_set<int> hset{1, 3, 9, 27, 81, 243, 729, 2187, 6561, 19683, 59049, 177147, 531441, 1594323, 4782969, 14348907, 43046721, 129140163, 387420489, 1162261467};
        
        return hset.count(n);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end

