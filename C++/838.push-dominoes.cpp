/*
 * @lc app=leetcode id=838 lang=cpp
 *
 * [838] Push Dominoes
 *
 * https://leetcode.com/problems/push-dominoes/description/
 *
 * algorithms
 * Medium (52.65%)
 * Likes:    1821
 * Dislikes: 125
 * Total Accepted:    62.7K
 * Total Submissions: 118.6K
 * Testcase Example:  '"RR.L"'
 *
 * There are n dominoes in a line, and we place each domino vertically upright.
 * In the beginning, we simultaneously push some of the dominoes either to the
 * left or to the right.
 * 
 * After each second, each domino that is falling to the left pushes the
 * adjacent domino on the left. Similarly, the dominoes falling to the right
 * push their adjacent dominoes standing on the right.
 * 
 * When a vertical domino has dominoes falling on it from both sides, it stays
 * still due to the balance of the forces.
 * 
 * For the purposes of this question, we will consider that a falling domino
 * expends no additional force to a falling or already fallen domino.
 * 
 * You are given a string dominoes representing the initial state where:
 * 
 * 
 * dominoes[i] = 'L', if the i^th domino has been pushed to the left,
 * dominoes[i] = 'R', if the i^th domino has been pushed to the right, and
 * dominoes[i] = '.', if the i^th domino has not been pushed.
 * 
 * 
 * Return a string representing the final state.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: dominoes = "RR.L"
 * Output: "RR.L"
 * Explanation: The first domino expends no additional force on the second
 * domino.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: dominoes = ".L.R...LR..L.."
 * Output: "LL.RR.LLRRLL.."
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == dominoes.length
 * 1 <= n <= 10^5
 * dominoes[i] is either 'L', 'R', or '.'.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = s.size();
        for (int i=1; i<n; ++i) {
            if (s[i] == '.') {
                if (s[i-1]=='R' || s[i-1]=='r') s[i] = 'r';
            }
        }
        
        for (int i=n-2; i>=0; i--) {
            if (s[i] == '.') {
                if (s[i+1]=='L' || s[i+1]=='l') s[i] = 'l';
            }
            else if (s[i+1]=='L' && s[i]=='r') {
                int j = i;
                while (j>=0 && s[j] == 'r') j --;
                
                int len = i - j;
                for (int k=0; k<len/2; ++k) s[i--] = 'l';
                if (len % 2 == 1) s[i--] = '.';
            }
        }
        
        for (int i=0; i<n; ++i) {
            if (s[i] == 'l') s[i] = 'L';
            else if (s[i] == 'r') s[i] = 'R';
        }
        return s;
    }
};
// @lc code=end

