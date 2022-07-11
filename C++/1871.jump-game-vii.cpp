/*
 * @lc app=leetcode id=1871 lang=cpp
 *
 * [1871] Jump Game VII
 *
 * https://leetcode.com/problems/jump-game-vii/description/
 *
 * algorithms
 * Medium (24.97%)
 * Likes:    933
 * Dislikes: 54
 * Total Accepted:    25.1K
 * Total Submissions: 100K
 * Testcase Example:  '"011010"\n2\n3'
 *
 * You are given a 0-indexed binary string s and two integers minJump and
 * maxJump. In the beginning, you are standing at index 0, which is equal to
 * '0'. You can move from index i to index j if the following conditions are
 * fulfilled:
 * 
 * 
 * i + minJump <= j <= min(i + maxJump, s.length - 1), and
 * s[j] == '0'.
 * 
 * 
 * Return true if you can reach index s.length - 1 in s, or false otherwise.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "011010", minJump = 2, maxJump = 3
 * Output: true
 * Explanation:
 * In the first step, move from index 0 to index 3. 
 * In the second step, move from index 3 to index 5.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "01101110", minJump = 2, maxJump = 3
 * Output: false
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 2 <= s.length <= 10^5
 * s[i] is either '0' or '1'.
 * s[0] == '0'
 * 1 <= minJump <= maxJump < s.length
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        
        s[0] = '2';
        int max_idx = 0;
        for (int i=0; i<s.size(); ++i) {
            if (s[i] != '2') continue;
            for (int j=max(i+minJump, max_idx); j<=min(i+maxJump, n-1); ++j)
                if (s[j]=='0') s[j] = '2';
            max_idx = i + maxJump;
        }
        
        return s.back() == '2';


        int n = s.size();
        if (s.back() == '1') return false;
        
        queue<int> q;
        q.push(0);
                
        int max_idx = 0;
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            
            if (i == n-1) return true;
            
            for (int j=max(i+minJump, max_idx); j<=min(i+maxJump, n-1); ++j) {
                if (s[j] == '0') q.push(j);
            }
            max_idx = min(i+maxJump+1, n);
        }
        return false;     
    }
};
// @lc code=end

