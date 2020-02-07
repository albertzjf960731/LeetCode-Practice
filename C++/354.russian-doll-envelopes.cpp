/*
 * @lc app=leetcode id=354 lang=cpp
 *
 * [354] Russian Doll Envelopes
 *
 * https://leetcode.com/problems/russian-doll-envelopes/description/
 *
 * algorithms
 * Hard (34.75%)
 * Likes:    831
 * Dislikes: 32
 * Total Accepted:    56.6K
 * Total Submissions: 162.8K
 * Testcase Example:  '[[5,4],[6,4],[6,7],[2,3]]'
 *
 * You have a number of envelopes with widths and heights given as a pair of
 * integers (w, h). One envelope can fit into another if and only if both the
 * width and height of one envelope is greater than the width and height of the
 * other envelope.
 * 
 * What is the maximum number of envelopes can you Russian doll? (put one
 * inside other)
 * 
 * Note:
 * Rotation is not allowed.
 * 
 * Example:
 * 
 * 
 * 
 * Input: [[5,4],[6,4],[6,7],[2,3]]
 * Output: 3 
 * Explanation: The maximum number of envelopes you can Russian doll is 3
 * ([2,3] => [5,4] => [6,7]).
 * 
 * 
 * 
 */
#include<vector>
using namespace std; 

// @lc code=start
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& es) {

        // Sort the array. Ascend on width and descend on height if width are same.
        // Find the longest increasing subsequence based on height.
        // Since the width is increasing, we only need to consider height.
        // [3, 4] cannot contains [3, 3], so we need to put [3, 4] before [3, 3] when sorting otherwise it will be counted as an increasing number if the order is [3, 3], [3, 4]

        sort(es.begin(), es.end(), [](vector<int> a, vector<int> b){
            return a[0]<b[0] || (a[0] == b[0] && a[1] > b[1]);});

        vector<int> dp;
        for (vector<int> e : es) {
            auto it = lower_bound(dp.begin(), dp.end(), e[1]);
            if (it==dp.end())
                dp.push_back(e[1]);
            else if (e[1] < *it)
                *it = e[1];
        }
        return dp.size();


        // 排序i, 对j 做longest increasing subsequence
        if (es.empty()) return 0;

        sort(es.begin(), es.end());
        vector<int> dp(es.size(), 1);
        for (int i=1; i<es.size(); ++i)
            for (int j=0; j<i; ++j)
                if (es[i][0]>es[j][0] && es[i][1]>es[j][1])
                    dp[i] = max(dp[i], dp[j]+1);
        return *max_element(dp.begin(), dp.end());
    }
};
// @lc code=end

