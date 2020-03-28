/*
 * @lc app=leetcode id=710 lang=cpp
 *
 * [710] Random Pick with Blacklist
 *
 * https://leetcode.com/problems/random-pick-with-blacklist/description/
 *
 * algorithms
 * Hard (32.54%)
 * Likes:    244
 * Dislikes: 51
 * Total Accepted:    10.2K
 * Total Submissions: 31.3K
 * Testcase Example:  '["Solution", "pick", "pick", "pick"]\n[[1, []], [], [], []]'
 *
 * Given a blacklist B containing unique integers from [0, N), write a function
 * to return a uniform random integer from [0, N) which is NOT in B.
 * 
 * Optimize it such that it minimizes the call to system’s Math.random().
 * 
 * Note:
 * 
 * 
 * 1 <= N <= 1000000000
 * 0 <= B.length < min(100000, N)
 * [0, N) does NOT include N. See interval notation.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: 
 * ["Solution","pick","pick","pick"]
 * [[1,[]],[],[],[]]
 * Output: [null,0,0,0]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 
 * ["Solution","pick","pick","pick"]
 * [[2,[]],[],[],[]]
 * Output: [null,1,1,1]
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 
 * ["Solution","pick","pick","pick"]
 * [[3,[1]],[],[],[]]
 * Output: [null,0,0,2]
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: 
 * ["Solution","pick","pick","pick"]
 * [[4,[2]],[],[],[]]
 * Output: [null,1,3,1]
 * 
 * 
 * Explanation of Input Syntax:
 * 
 * The input is two lists: the subroutines called and their arguments.
 * Solution's constructor has two arguments, N and the blacklist B. pick has no
 * arguments. Arguments are always wrapped with a list, even if there aren't
 * any.
 * 
 */
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

// @lc code=start
// class Solution {
// private:
//     int N;
//     unordered_set<int> blacklist;
// public:
//     Solution(int N, vector<int>& blacklist) {
//         this->N = N;
//         this->blacklist = {blacklist.begin(), blacklist.end()};
//     }
    
//     int pick() {
//         while (true) {
//             int num = rand() % N;
//             if (!blacklist.count(num)) return num;
//         }
//         return -1;
//     }
// };
class Solution {
private:
    int len;
    unordered_map<int, int> hash_map;
public:
    Solution(int N, vector<int>& blacklist) {
        len = N - blacklist.size();
        
        unordered_set<int> hash_set;
        for (int i=len; i<N; ++i) hash_set.insert(i);
        for (int num: blacklist) hash_set.erase(num);
        
        auto it = hash_set.begin();
        for (int num: blacklist) {
            if (num < len)
                hash_map[num] = *it++;
        }
        
    }
    
    int pick() {
        int num = rand() % len;
        return hash_map.count(num) ? hash_map[num] : num;
    }
};
/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(N, blacklist);
 * int param_1 = obj->pick();
 */
// @lc code=end

