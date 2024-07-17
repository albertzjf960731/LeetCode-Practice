/*
 * @lc app=leetcode id=846 lang=cpp
 *
 * [846] Hand of Straights
 *
 * https://leetcode.com/problems/hand-of-straights/description/
 *
 * algorithms
 * Medium (51.63%)
 * Likes:    438
 * Dislikes: 59
 * Total Accepted:    30.6K
 * Total Submissions: 59.3K
 * Testcase Example:  '[1,2,3,6,2,3,4,7,8]\n3'
 *
 * Alice has a hand of cards, given as an array of integers.
 * 
 * Now she wants to rearrange the cards into groups so that each group is size
 * W, and consists of W consecutive cards.
 * 
 * Return true if and only if she can.
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: hand = [1,2,3,6,2,3,4,7,8], W = 3
 * Output: true
 * Explanation: Alice's hand can be rearranged as [1,2,3],[2,3,4],[6,7,8].
 * 
 * Example 2:
 * 
 * 
 * Input: hand = [1,2,3,4,5], W = 4
 * Output: false
 * Explanation: Alice's hand can't be rearranged into groups of 4.
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= hand.length <= 10000
 * 0 <= hand[i] <= 10^9
 * 1 <= W <= hand.length
 * 
 * 
 */
#include<vector>
#include<map>
using namespace std;

// @lc code=start
class Solution {
public:
    bool isNStraightHand(vector<int>& nums, int k) {
        int n = nums.size();
        if(n%k != 0) return false;

        map<int, int> cnts;
        for (int num: nums) cnts[num] += 1;
        
        for (auto [num, cnt]: cnts) {
            if (cnt == 0) continue;
            
            for (int i=0; i<k; ++i) {
                cnts[num+i] -= cnt;
                if (cnts[num+i] < 0) return false;
            }
        }
        return true;
    }
};
// @lc code=end

