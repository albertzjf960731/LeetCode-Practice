/*
 * @lc app=leetcode id=1209 lang=cpp
 *
 * [1209] Remove All Adjacent Duplicates in String II
 *
 * https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/description/
 *
 * algorithms
 * Medium (56.00%)
 * Likes:    4535
 * Dislikes: 86
 * Total Accepted:    241.6K
 * Total Submissions: 431.6K
 * Testcase Example:  '"abcd"\n2'
 *
 * You are given a string s and an integer k, a k duplicate removal consists of
 * choosing k adjacent and equal letters from s and removing them, causing the
 * left and the right side of the deleted substring to concatenate together.
 * 
 * We repeatedly make k duplicate removals on s until we no longer can.
 * 
 * Return the final string after all such duplicate removals have been made. It
 * is guaranteed that the answer is unique.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "abcd", k = 2
 * Output: "abcd"
 * Explanation: There's nothing to delete.
 * 
 * Example 2:
 * 
 * 
 * Input: s = "deeedbbcccbdaa", k = 3
 * Output: "aa"
 * Explanation: 
 * First delete "eee" and "ccc", get "ddbbbdaa"
 * Then delete "bbb", get "dddaa"
 * Finally delete "ddd", get "aa"
 * 
 * Example 3:
 * 
 * 
 * Input: s = "pbbcggttciiippooaais", k = 2
 * Output: "ps"
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 10^5
 * 2 <= k <= 10^4
 * s only contains lowercase English letters.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char, int>> stack{{'#', 0}}; 
        for (char c: s) {
            if (stack.back().first != c) 
                stack.push_back(make_pair(c, 1));
            else {
                stack.back().second += 1;
                if (stack.back().second == k)
                    stack.pop_back();
            }
        }
        
        string ans;
        for (auto &it: stack) {
            ans.append(it.second, it.first);
        }
        return ans;
    }
};
// @lc code=end

