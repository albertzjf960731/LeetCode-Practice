/*
 * @lc app=leetcode id=1980 lang=cpp
 *
 * [1980] Find Unique Binary String
 *
 * https://leetcode.com/problems/find-unique-binary-string/description/
 *
 * algorithms
 * Medium (63.42%)
 * Likes:    602
 * Dislikes: 28
 * Total Accepted:    25.4K
 * Total Submissions: 40.1K
 * Testcase Example:  '["01","10"]'
 *
 * Given an array of strings nums containing n unique binary strings each of
 * length n, return a binary string of length n that does not appear in nums.
 * If there are multiple answers, you may return any of them.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = ["01","10"]
 * Output: "11"
 * Explanation: "11" does not appear in nums. "00" would also be correct.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = ["00","01"]
 * Output: "11"
 * Explanation: "11" does not appear in nums. "10" would also be correct.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = ["111","011","001"]
 * Output: "101"
 * Explanation: "101" does not appear in nums. "000", "010", "100", and "110"
 * would also be correct.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == nums.length
 * 1 <= n <= 16
 * nums[i].length == n
 * nums[i] is either '0' or '1'.
 * All the strings of nums are unique.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums[0].size();
        
        unordered_set<int> hset;
        // for (string& s: nums) {
        //     int num = 0;
        //     for (int i=n-1; i>=0; --i) {
        //         num += (s[i]-'0') << (n-i-1);
        //     }
        //     // cout << num << " ";
        //     hset.insert(num);
        // }
        for (string& s: nums) hset.insert(stoi(num, 0, 2));
        // cout << endl;
        
        for (int i=0; i<(1<<n); ++i) {
            if (!hset.count(i)) {
                // cout << i << endl;
                // string s;
                // while (i != 0) {
                //     s = (i%2 == 0 ? "0" : "1") + s;
                //     i /= 2;
                // }
                // return string(n-s.size(), '0') + s;
                return bitset<16>(res).to_string().substr(16-nums.size());
            }
        }
        return ""; 


        string ans="";
        for(int i=0; i<nums.size(); i++) 
            ans+= nums[i][i]=='0' ? '1' : '0';          // Using ternary operator
			// ans+=to_string(1-(nums[i][i]-'0'));     // Alternate:  or use to_string & 1-x to flip
        return ans;
    }
};
// @lc code=end

