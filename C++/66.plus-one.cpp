/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 *
 * https://leetcode.com/problems/plus-one/description/
 *
 * algorithms
 * Easy (41.79%)
 * Likes:    1103
 * Dislikes: 1890
 * Total Accepted:    480.9K
 * Total Submissions: 1.2M
 * Testcase Example:  '[1,2,3]'
 *
 * Given a non-empty array of digits representing a non-negative integer, plus
 * one to the integer.
 * 
 * The digits are stored such that the most significant digit is at the head of
 * the list, and each element in the array contain a single digit.
 * 
 * You may assume the integer does not contain any leading zero, except the
 * number 0 itself.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,3]
 * Output: [1,2,4]
 * Explanation: The array represents the integer 123.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [4,3,2,1]
 * Output: [4,3,2,2]
 * Explanation: The array represents the integer 4321.
 * 
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        // long num = 0;
        // for (int i:digits)
        //     num = num*10 + i;

        // num += 1;
        // vector<int> res;
        // while (num>0) {
        //     res.push_back(num%10);
        //     num/=10;
        // }
        // reverse(res.begin(), res.end());
        // return res;

        for (int i=digits.size()-1; i>-1; i--) {
            if (digits[i]==9)
                digits[i] = 0;
            else {
                digits[i]++;
                return digits;
            }
        }
        digits[0] = 1;
        digits.push_back(0);
        return digits;
    }
};
// @lc code=end

