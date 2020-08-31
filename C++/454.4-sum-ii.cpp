/*
 * @lc app=leetcode id=454 lang=cpp
 *
 * [454] 4Sum II
 */
#include <vector>
#include <unordered_map>

using namespace std;
// @lc code=start
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int ans = 0;
        unordered_map<int, int> hash_map;
        for (int a: A) {
            for (int b: B) {
                hash_map[a+b] += 1;
            }
        }

        for (int c: C) {
            for (int d: D) {
                ans += hash_map[-c-d];
            }
        }
        return ans;
    }
};
// @lc code=end

