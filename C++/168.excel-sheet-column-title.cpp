/*
 * @lc app=leetcode id=168 lang=cpp
 *
 * [168] Excel Sheet Column Title
 *
 * https://leetcode.com/problems/excel-sheet-column-title/description/
 *
 * algorithms
 * Easy (30.13%)
 * Likes:    961
 * Dislikes: 203
 * Total Accepted:    199.2K
 * Total Submissions: 660.8K
 * Testcase Example:  '1'
 *
 * Given a positive integer, return its corresponding column title as appear in
 * an Excel sheet.
 * 
 * For example:
 * 
 * 
 * ⁠   1 -> A
 * ⁠   2 -> B
 * ⁠   3 -> C
 * ⁠   ...
 * ⁠   26 -> Z
 * ⁠   27 -> AA
 * ⁠   28 -> AB 
 * ⁠   ...
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: 1
 * Output: "A"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 28
 * Output: "AB"
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 701
 * Output: "ZY"
 * 
 */
#include<vector>
#include<string>
using namespace std;
// @lc code=start
class Solution {
public:
    string convertToTitle(int n) {
        string res;
        while (n) {
            res.push_back('A' + (n-1)%26);
            n = (n-1)/26;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end

