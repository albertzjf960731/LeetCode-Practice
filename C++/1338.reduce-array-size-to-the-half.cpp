/*
 * @lc app=leetcode id=1338 lang=cpp
 *
 * [1338] Reduce Array Size to The Half
 *
 * https://leetcode.com/problems/reduce-array-size-to-the-half/description/
 *
 * algorithms
 * Medium (66.95%)
 * Likes:    258
 * Dislikes: 26
 * Total Accepted:    23.5K
 * Total Submissions: 35.1K
 * Testcase Example:  '[3,3,3,3,5,5,5,2,2,7]'
 *
 * Given an array arr.  You can choose a set of integers and remove all the
 * occurrences of these integers in the array.
 * 
 * Return the minimum size of the set so that at least half of the integers of
 * the array are removed.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: arr = [3,3,3,3,5,5,5,2,2,7]
 * Output: 2
 * Explanation: Choosing {3,7} will make the new array [5,5,5,2,2] which has
 * size 5 (i.e equal to half of the size of the old array).
 * Possible sets of size 2 are {3,5},{3,2},{5,2}.
 * Choosing set {2,7} is not possible as it will make the new array
 * [3,3,3,3,5,5,5] which has size greater than half of the size of the old
 * array.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: arr = [7,7,7,7,7,7]
 * Output: 1
 * Explanation: The only possible set you can choose is {7}. This will make the
 * new array empty.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: arr = [1,9]
 * Output: 1
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: arr = [1000,1000,3,7]
 * Output: 1
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: arr = [1,2,3,4,5,6,7,8,9,10]
 * Output: 5
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= arr.length <= 10^5
 * arr.length is even.
 * 1 <= arr[i] <= 10^5
 * 
 */
#include<vector>
#include<set>
#include<unordered_map>
using namespace std;

// @lc code=start
class Solution {
public:
    int minSetSize(vector<int>& nums) {
        unordered_map<int, int> cnts;
        for (int num: nums) cnts[num]++;

        multiset<int, greater<int>> buckets;        
        for (auto &it: cnts) buckets.insert(it.second);
        
        int ans = 0, cnt = 0;
        for (auto it=buckets.begin(); cnt*2<nums.size(); ++it) {
            ans++;
            cnt += *it;
        }
        return ans;

        unordered_map<int, int> hmap;
        for (int num: arr) hmap[num] += 1;
        
        vector<int> cnts;
        for (auto [_, cnt]: hmap) cnts.push_back(cnt);
        sort(cnts.begin(), cnts.end(), greater<int>());
        
        int ans = 0, sum = 0;
        for (int num: cnts) {
            sum += num;
            ans += 1;
            if (sum >= arr.size()/2) break;
        }
        return ans;
    }
};
// @lc code=end

