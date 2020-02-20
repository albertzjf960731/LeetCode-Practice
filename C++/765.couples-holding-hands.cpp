/*
 * @lc app=leetcode id=765 lang=cpp
 *
 * [765] Couples Holding Hands
 *
 * https://leetcode.com/problems/couples-holding-hands/description/
 *
 * algorithms
 * Hard (53.27%)
 * Likes:    496
 * Dislikes: 53
 * Total Accepted:    20.3K
 * Total Submissions: 38.1K
 * Testcase Example:  '[0,2,1,3]'
 *
 * 
 * N couples sit in 2N seats arranged in a row and want to hold hands.  We want
 * to know the minimum number of swaps so that every couple is sitting side by
 * side.  A swap consists of choosing any two people, then they stand up and
 * switch seats. 
 * 
 * The people and seats are represented by an integer from 0 to 2N-1, the
 * couples are numbered in order, the first couple being (0, 1), the second
 * couple being (2, 3), and so on with the last couple being (2N-2, 2N-1).
 * 
 * The couples' initial seating is given by row[i] being the value of the
 * person who is initially sitting in the i-th seat.
 * 
 * Example 1:
 * Input: row = [0, 2, 1, 3]
 * Output: 1
 * Explanation: We only need to swap the second (row[1]) and third (row[2])
 * person.
 * 
 * 
 * Example 2:
 * Input: row = [3, 2, 0, 1]
 * Output: 0
 * Explanation: All couples are already seated side by side.
 * 
 * 
 * 
 * Note:
 * ⁠
 * ⁠len(row) is even and in the range of [4, 60].
 * ⁠row is guaranteed to be a permutation of 0...len(row)-1.
 * 
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int minSwapsCouples(vector<int>& nums) {
        // N integers problem
        int ans = 0;
        for(int i=0; i<nums.size(); ++ i) {
            for (int j=nums[i]; i!=j; j=nums[i]) {
                swap(nums[i],nums[j]);
                ans++;
            }
        }
        return ans;


        // instead of i == row[i], we require i == ptn[pos[ptn[row[i]]]], where we have defined two additional arrays ptn and pos:

        // ptn[i] denotes the partner of label i (i can be either a seat or a person) - - ptn[i] = i + 1 if i is even; ptn[i] = i - 1 if i is odd.

        // pos[i] denotes the index of the person with label i in the row array - - row[pos[i]] == i.

        // The meaning of i == ptn[pos[ptn[row[i]]]] is as follows:

        // The person sitting at seat i has a label row[i], and we want to place him/her next to his/her partner.

        // So we first find the label of his/her partner, which is given by ptn[row[i]].

        // We then find the seat of his/her partner, which is given by pos[ptn[row[i]]].

        // Lastly we find the seat next to his/her partner's seat, which is given by ptn[pos[ptn[row[i]]]].

        int ans = 0;

        vector<int> ptn(nums.size(), 0);
        vector<int> pos(nums.size(), 0);
        for (int i=0; i<nums.size(); i++) {
            ptn[i] = (i%2==0 ? i+1 : i-1);
            pos[nums[i]] = i;
        }
        
        for (int i=0; i<nums.size(); i++) {
            for (int j=ptn[pos[ptn[nums[i]]]]; i!=j; j = ptn[pos[ptn[nums[i]]]]) {
                swap(nums[i], nums[j]);
                swap(pos[nums[i]], pos[nums[j]]);
                ans++;
            }
        }   
        return ans;
    }
};
// @lc code=end

