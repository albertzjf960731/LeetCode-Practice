/*
 * @lc app=leetcode id=330 lang=cpp
 *
 * [330] Patching Array
 *
 * https://leetcode.com/problems/patching-array/description/
 *
 * algorithms
 * Hard (34.05%)
 * Likes:    420
 * Dislikes: 68
 * Total Accepted:    34.6K
 * Total Submissions: 101.4K
 * Testcase Example:  '[1,3]\n6'
 *
 * Given a sorted positive integer array nums and an integer n, add/patch
 * elements to the array such that any number in range [1, n] inclusive can be
 * formed by the sum of some elements in the array. Return the minimum number
 * of patches required.
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,3], n = 6
 * Output: 1 
 * Explanation:
 * Combinations of nums are [1], [3], [1,3], which form possible sums of: 1, 3,
 * 4.
 * Now if we add/patch 2 to nums, the combinations are: [1], [2], [3], [1,3],
 * [2,3], [1,2,3].
 * Possible sums are 1, 2, 3, 4, 5, 6, which now covers the range [1, 6].
 * So we only need 1 patch.
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1,5,10], n = 20
 * Output: 2
 * Explanation: The two patches can be [2, 4].
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [1,2,2], n = 5
 * Output: 0
 * 
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {

        // 如果列表中一个数都没有，这种情况比较简单：
        // 1、首先必须要有1；
        // 2、然后必须要有2；
        // 3、这时，覆盖区间是[1，3]，如果还不能全覆盖，下一个要添加的数是4；
        // 4、。。。依此类推。
        // 所以最终数量是log2(n)。

        // 如果nums不为空，此时核心思想是，在已经有的覆盖范围[1，M]基础上，如果下一个数nums[k]在已经覆盖范围内，那覆盖范围将扩充到[1, M + nums[k]]，如果超出覆盖范围，那么下一下要添加的数必须是M+1，这样才能使覆盖连续，覆盖范围扩充到[1, 2M+1]。

        long max_num=1;
        int cnt=0, i=0;
        // vector<long> patch;
        while (max_num<=n) {
            if (i<nums.size() && max_num>=nums[i]) {
                max_num += nums[i++];
            }
            else {
                // patch.push_back(max_num);
                max_num = max_num * 2;
                cnt ++;
            }             
        }
        // for (int num: patch) cout << num << " ";
        // cout << endl;
        return cnt;
    }
};
// @lc code=end

