/*
 * @lc app=leetcode id=599 lang=cpp
 *
 * [599] Minimum Index Sum of Two Lists
 *
 * https://leetcode.com/problems/minimum-index-sum-of-two-lists/description/
 *
 * algorithms
 * Easy (49.62%)
 * Likes:    476
 * Dislikes: 177
 * Total Accepted:    76.4K
 * Total Submissions: 154K
 * Testcase Example:  '["Shogun","Tapioca Express","Burger King","KFC"]\n' +
  '["Piatti","The Grill at Torrey Pines","Hungry Hunter Steakhouse","Shogun"]'
 *
 * 
 * Suppose Andy and Doris want to choose a restaurant for dinner, and they both
 * have a list of favorite restaurants represented by strings. 
 * 
 * 
 * You need to help them find out their common interest with the least list
 * index sum. If there is a choice tie between answers, output all of them with
 * no order requirement. You could assume there always exists an answer.
 * 
 * 
 * 
 * Example 1:
 * 
 * Input:
 * ["Shogun", "Tapioca Express", "Burger King", "KFC"]
 * ["Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse",
 * "Shogun"]
 * Output: ["Shogun"]
 * Explanation: The only restaurant they both like is "Shogun".
 * 
 * 
 * 
 * Example 2:
 * 
 * Input:
 * ["Shogun", "Tapioca Express", "Burger King", "KFC"]
 * ["KFC", "Shogun", "Burger King"]
 * Output: ["Shogun"]
 * Explanation: The restaurant they both like and have the least index sum is
 * "Shogun" with index sum 1 (0+1).
 * 
 * 
 * 
 * 
 * Note:
 * 
 * The length of both lists will be in the range of [1, 1000].
 * The length of strings in both lists will be in the range of [1, 30].
 * The index is starting from 0 to the list length minus 1.
 * No duplicates in both lists.
 * 
 * 
 */
#include<vector>
#include<unordered_map>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> hash_set1;
        for (int i=0; i<list1.size(); i++)
            hash_set1[list1[i]] = i;
        
        vector<string> res;
        int idx_sum = INT_MAX;
        for (int i=0; i<list2.size(); i++) {
            if (hash_set1.count(list2[i])) {
                if (i+hash_set1[list2[i]] < idx_sum) {
                    res.clear();
                    res.push_back(list2[i]);
                    idx_sum = i+hash_set1[list2[i]];
                }
                else if (i+hash_set1[list2[i]] == idx_sum)
                    res.push_back(list2[i]);
            }
        }
        return res; 
    }
};
// @lc code=end

