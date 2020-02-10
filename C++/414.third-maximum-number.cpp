/*
 * @lc app=leetcode id=414 lang=cpp
 *
 * [414] Third Maximum Number
 *
 * https://leetcode.com/problems/third-maximum-number/description/
 *
 * algorithms
 * Easy (29.91%)
 * Likes:    512
 * Dislikes: 946
 * Total Accepted:    119.5K
 * Total Submissions: 399.4K
 * Testcase Example:  '[3,2,1]'
 *
 * Given a non-empty array of integers, return the third maximum number in this
 * array. If it does not exist, return the maximum number. The time complexity
 * must be in O(n).
 * 
 * Example 1:
 * 
 * Input: [3, 2, 1]
 * 
 * Output: 1
 * 
 * Explanation: The third maximum is 1.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: [1, 2]
 * 
 * Output: 2
 * 
 * Explanation: The third maximum does not exist, so the maximum (2) is
 * returned instead.
 * 
 * 
 * 
 * Example 3:
 * 
 * Input: [2, 2, 3, 1]
 * 
 * Output: 1
 * 
 * Explanation: Note that the third maximum here means the third maximum
 * distinct number.
 * Both numbers with value 2 are both considered as second maximum.
 * 
 * 
 */
#include<vector>
#include<set>
using namespace std;

// @lc code=start
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        // [2, 2, 3, 1] = 1
        long a, b, c;
        a = b = c = LONG_MIN;
        for (int num : nums) {
            if (num <= c || num == b || num == a) 
                continue;
            if (num>a) {
                c = b;
                b = a;
                a = num;
            }
            else if (num>b) {
                c = b;
                b = num;
            }
            else if (num>c) 
                c = num;
        }
        return c==LONG_MIN ? a : c;

        // Since we only have 3 elements, insert/delete is constant time operations. Don't stick to O(nlog n) concept. We only care about big O when the things we are dealing with is big.
        set<int> hash_set;
        for (int num : nums) {
            hash_set.insert(num);
            if (hash_set.size() > 3)
                hash_set.erase(hash_set.begin());
        }
        return hash_set.size()==3 ? *hash_set.begin() : *hash_set.rbegin();
    }
};
// @lc code=end

