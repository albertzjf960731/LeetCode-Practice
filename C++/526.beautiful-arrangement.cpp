/*
 * @lc app=leetcode id=526 lang=cpp
 *
 * [526] Beautiful Arrangement
 *
 * https://leetcode.com/problems/beautiful-arrangement/description/
 *
 * algorithms
 * Medium (57.98%)
 * Likes:    718
 * Dislikes: 151
 * Total Accepted:    53.5K
 * Total Submissions: 91.8K
 * Testcase Example:  '2'
 *
 * Suppose you have N integers from 1 to N. We define a beautiful arrangement
 * as an array that is constructed by these N numbers successfully if one of
 * the following is true for the ith position (1 <= i <= N) in this
 * array:
 * 
 * 
 * The number at the ith position is divisible by i.
 * i is divisible by the number at the ith position.
 * 
 * 
 * 
 * 
 * Now given N, how many beautiful arrangements can you construct?
 * 
 * Example 1:
 * 
 * 
 * Input: 2
 * Output: 2
 * Explanation: 
 * 
 * The first beautiful arrangement is [1, 2]:
 * 
 * Number at the 1st position (i=1) is 1, and 1 is divisible by i (i=1).
 * 
 * Number at the 2nd position (i=2) is 2, and 2 is divisible by i (i=2).
 * 
 * The second beautiful arrangement is [2, 1]:
 * 
 * Number at the 1st position (i=1) is 2, and 2 is divisible by i (i=1).
 * 
 * Number at the 2nd position (i=2) is 1, and i (i=2) is divisible by 1.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * N is a positive integer and will not exceed 15.
 * 
 * 
 * 
 * 
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int countArrangement(int N) {
        int ans = 0;
        vector<int> visited(N + 1, 0); // 也可以状态压缩来表示visited
        DFS(N, visited, 1, ans);
        return ans;
    }
    void DFS(int N, vector<int>& visited, int pos, int& ans) {
        if (pos > N) {
            ++ans; 
            return;
        }
        for (int i=1; i<=N; ++i) {
            if (visited[i]==0 && (i%pos==0 || pos%i==0)) {
                visited[i] = 1;
                DFS(N, visited, pos+1, ans);
                visited[i] = 0;
            }
        }
    }
};
// @lc code=end

