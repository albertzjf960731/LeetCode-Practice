/*
 * @lc app=leetcode id=1996 lang=cpp
 *
 * [1996] The Number of Weak Characters in the Game
 *
 * https://leetcode.com/problems/the-number-of-weak-characters-in-the-game/description/
 *
 * algorithms
 * Medium (36.90%)
 * Likes:    1589
 * Dislikes: 53
 * Total Accepted:    46.9K
 * Total Submissions: 113.7K
 * Testcase Example:  '[[5,5],[6,3],[3,6]]'
 *
 * You are playing a game that contains multiple characters, and each of the
 * characters has two main properties: attack and defense. You are given a 2D
 * integer array properties where properties[i] = [attacki, defensei]
 * represents the properties of the i^th character in the game.
 * 
 * A character is said to be weak if any other character has both attack and
 * defense levels strictly greater than this character's attack and defense
 * levels. More formally, a character i is said to be weak if there exists
 * another character j where attackj > attacki and defensej > defensei.
 * 
 * Return the number of weak characters.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: properties = [[5,5],[6,3],[3,6]]
 * Output: 0
 * Explanation: No character has strictly greater attack and defense than the
 * other.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: properties = [[2,2],[3,3]]
 * Output: 1
 * Explanation: The first character is weak because the second character has a
 * strictly greater attack and defense.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: properties = [[1,5],[10,4],[4,3]]
 * Output: 1
 * Explanation: The third character is weak because the second character has a
 * strictly greater attack and defense.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 2 <= properties.length <= 10^5
 * properties[i].length == 2
 * 1 <= attacki, defensei <= 10^5
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(nums.begin(), nums.end(), [](vector<int>& a, vector<int>& b) {
            return a[0]<b[0] || (a[0]==b[0] && a[1]>b[1]);
        });
        
        int ans = 0, cur_max = INT_MIN;
        for (int i=nums.size()-1; i>=0; --i) {
            if (nums[i][1] < cur_max) ans += 1;
            cur_max = max(cur_max, nums[i][1]);
        }
        return ans;
    }
    }
};
// @lc code=end

