/*
 * @lc app=leetcode id=1349 lang=cpp
 *
 * [1349] Maximum Students Taking Exam
 *
 * https://leetcode.com/problems/maximum-students-taking-exam/description/
 *
 * algorithms
 * Hard (42.36%)
 * Likes:    316
 * Dislikes: 9
 * Total Accepted:    6K
 * Total Submissions: 14.1K
 * Testcase Example:  '[["#",".","#","#",".","#"],[".","#","#","#","#","."],["#",".","#","#",".","#"]]'
 *
 * Given a m * n matrix seats  that represent seats distributions in a
 * classroom. If a seat is broken, it is denoted by '#' character otherwise it
 * is denoted by a '.' character.
 * 
 * Students can see the answers of those sitting next to the left, right, upper
 * left and upper right, but he cannot see the answers of the student sitting
 * directly in front or behind him. Return the maximum number of students that
 * can take the exam together without any cheating being possible..
 * 
 * Students must be placed in seats in good condition.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: seats = [["#",".","#","#",".","#"],
 * [".","#","#","#","#","."],
 * ["#",".","#","#",".","#"]]
 * Output: 4
 * Explanation: Teacher can place 4 students in available seats so they don't
 * cheat on the exam. 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: seats = [[".","#"],
 * ["#","#"],
 * ["#","."],
 * ["#","#"],
 * [".","#"]]
 * Output: 3
 * Explanation: Place all students in available seats. 
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: seats = [["#",".",".",".","#"],
 * [".","#",".","#","."],
 * [".",".","#",".","."],
 * [".","#",".","#","."],
 * ["#",".",".",".","#"]]
 * Output: 10
 * Explanation: Place students in available seats in column 1, 3 and 5.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * seats contains only characters '.' and'#'.
 * m == seats.length
 * n == seats[i].length
 * 1 <= m <= 8
 * 1 <= n <= 8
 * 
 * 
 */
#include<vector>
#include<bitset>
using namespace std;

// @lc code=start
class Solution {
public:
    int maxStudents(vector<vector<char>>& seats) {
        // // dp[i][j] 表示当第 i 行的座位分布为 j 时，前 i 行可容纳的最大学生人数
        // // dp[i+1][j] = max(dp[i+1][j], dp[i][k] + count(j))
        
        // int m=seats.size(), n=seats[0].size();
        // vector<vector<int>> dp(m+1, vector<int>(1<<n));

        // for(int row=1; row<=m; row++){
        //     for(int s=0; s<(1<<n); s++){ //遍历 2^n 个状态
                
        //         bitset<8> bs(s); //记录对应状态的bit位
        //         bool ok=true;
        //         for(int j=0; j<n; j++){
        //             if((bs[j] && seats[row-1][j]=='#') || (j<n-1 && bs[j] && bs[j+1])){
        //                 ok=false;
        //                 break;
        //             }
        //         }
        //         if(!ok){
        //             dp[row][s] = -1;//说明坐在坏椅子上或相邻坐了，该状态舍弃
        //             continue;
        //         }
                
        //         for(int last=0; last<(1<<n); last++){//找到一种当前行的可行状态后，遍历上一行的所有状态
        //             if(dp[row-1][last]==-1)//上一行的状态被舍弃了，那就直接下一个状态
        //                 continue;
        //             bitset<8> lbs(last);
        //             bool flag=true;
        //             for(int j=0; j<n; j++){
        //                 if(lbs[j] && ((j>0 && bs[j-1]) || (j<n-1 && bs[j+1]))){//如果找到的这个上一行状态的j位置坐了人，
        //                     flag=false;                                    //下一行的j+1位置或j-1位置也坐了人，那么该状态不合法，舍弃
        //                     break;
        //                 }
        //             }
        //             if(flag){//flag为真说明这个last状态的每个位置都合法
        //                 dp[row][s] = max(dp[row][s], dp[row-1][last]+(int)bs.count());//转移方程
        //             }
        //         }

        //     }
        // }
        
        // int ans=0;
        // for(int i=0; i<(1<<n); i++){//在最后一行的所有状态中找出最大的
        //     ans = max(ans, dp[m][i]);
        // }
        // return ans;
    
        int m = seats.size(), n = seats[0].size();
        vector<vector<int>> dp = vector<vector<int>>(m+1, vector<int>(1<<n,0));
        
        vector<int> nums(1<<n, 0);
        for (int i=1; i<(1<<n); ++i) {
            int num = i;
            while (num) {
                nums[i] ++;
                num = num & (num-1);
            }
        }
        
        for (int i=1; i<=m; ++i) {
            
            int seat = 0;
            for (int k=0; k<n; ++k) {
                if (seats[i-1][k] == '#') 
                    seat |= 1<<k;
            }
  
            for (int cur_state=0; cur_state<(1<<n); ++cur_state) {
                if (seat&cur_state) continue;
                
                // cur_row
                if ( ((cur_state<<1)&cur_state) != 0 && 
                     ((cur_state>>1)&cur_state) != 0) continue;
                
                // prev_row
                int cnt = 0;
                for (int pre_state=0; pre_state<(1<<n); ++pre_state) {
                    if (((pre_state<<1)&cur_state) == 0 && ((pre_state>>1)&cur_state) == 0)
                        cnt = max(cnt, dp[i-1][pre_state]);
                }
                
                dp[i][cur_state] = cnt+nums[cur_state];
            }
        }
        
        int ans = 0;
        for (int state=0; state<(1<<n); ++state) 
            ans = max(ans, dp[m][state]);
        return ans;
    }
};
// @lc code=end

