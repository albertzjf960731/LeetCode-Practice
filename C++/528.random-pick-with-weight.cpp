/*
 * @lc app=leetcode id=528 lang=cpp
 *
 * [528] Random Pick with Weight
 *
 * https://leetcode.com/problems/random-pick-with-weight/description/
 *
 * algorithms
 * Medium (43.43%)
 * Likes:    482
 * Dislikes: 918
 * Total Accepted:    54.4K
 * Total Submissions: 125K
 * Testcase Example:  '["Solution", "pickIndex"]\n[[[1]], []]'
 *
 * Given an array w of positive integers, where w[i] describes the weight of
 * index i, write a function pickIndex which randomly picks an index in
 * proportion to its weight.
 * 
 * Note:
 * 
 * 
 * 1 <= w.length <= 10000
 * 1 <= w[i] <= 10^5
 * pickIndex will be called at most 10000 times.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: 
 * ["Solution","pickIndex"]
 * [[[1]],[]]
 * Output: [null,0]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 
 * ["Solution","pickIndex","pickIndex","pickIndex","pickIndex","pickIndex"]
 * [[[1,3]],[],[],[],[],[]]
 * Output: [null,0,1,1,1,0]
 * 
 * 
 * Explanation of Input Syntax:
 * 
 * The input is two lists: the subroutines called and their arguments.
 * Solution's constructor has one argument, the array w. pickIndex has no
 * arguments. Arguments are always wrapped with a list, even if there aren't
 * any.
 * 
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
private:
    vector<int> sum;
public:
    Solution(vector<int>& w) {
        sum = w;
        for (int i=1; i<w.size(); ++i)
            sum[i] = sum[i-1] + w[i];
    }
    
    int pickIndex() {
        int x = rand() % sum.back();
        
//         int left=0, right=sum.size()-1;
//         while (left < right) {
//             int mid = left + (right-left)/2;
//             if (sum[mid] <= x) left = mid+1;
//             else right = mid;
//         }
//         return left;
        return upper_bound(sum.begin(), sum.end(), x) - sum.begin();

    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
// @lc code=end

