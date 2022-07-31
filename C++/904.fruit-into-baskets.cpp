/*
 * @lc app=leetcode id=904 lang=cpp
 *
 * [904] Fruit Into Baskets
 *
 * https://leetcode.com/problems/fruit-into-baskets/description/
 *
 * algorithms
 * Medium (42.72%)
 * Likes:    1258
 * Dislikes: 92
 * Total Accepted:    217.8K
 * Total Submissions: 511.3K
 * Testcase Example:  '[1,2,1]'
 *
 * You are visiting a farm that has a single row of fruit trees arranged from
 * left to right. The trees are represented by an integer array fruits where
 * fruits[i] is the type of fruit the i^th tree produces.
 * 
 * You want to collect as much fruit as possible. However, the owner has some
 * strict rules that you must follow:
 * 
 * 
 * You only have two baskets, and each basket can only hold a single type of
 * fruit. There is no limit on the amount of fruit each basket can hold.
 * Starting from any tree of your choice, you must pick exactly one fruit from
 * every tree (including the start tree) while moving to the right. The picked
 * fruits must fit in one of your baskets.
 * Once you reach a tree with fruit that cannot fit in your baskets, you must
 * stop.
 * 
 * 
 * Given the integer array fruits, return the maximum number of fruits you can
 * pick.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: fruits = [1,2,1]
 * Output: 3
 * Explanation: We can pick from all 3 trees.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: fruits = [0,1,2,2]
 * Output: 3
 * Explanation: We can pick from trees [1,2,2].
 * If we had started at the first tree, we would only pick from trees [0,1].
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: fruits = [1,2,3,2,2]
 * Output: 4
 * Explanation: We can pick from trees [2,3,2,2].
 * If we had started at the first tree, we would only pick from trees
 * [1,2].
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= fruits.length <= 10^5
 * 0 <= fruits[i] < fruits.length
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> cnts;
        int size = 0;
        
        int ans = 0;
        for (int left=0, right=0; right<nums.size(); ++right) {
            
            if (size == 2 && cnts[nums[right]] == 0) {
                while (size == 2) {
                    cnts[nums[left]] -= 1;
                    if (cnts[nums[left]] == 0) size -= 1;
                    left ++;
                }
            }

            // cout << left << " " << right << endl;
            
            if ((cnts[nums[right]]) == 0) size += 1;
            cnts[nums[right]] += 1;
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
// @lc code=end

