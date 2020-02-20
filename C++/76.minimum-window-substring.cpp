/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 *
 * https://leetcode.com/problems/minimum-window-substring/description/
 *
 * algorithms
 * Hard (32.68%)
 * Likes:    3195
 * Dislikes: 233
 * Total Accepted:    308.6K
 * Total Submissions: 942.3K
 * Testcase Example:  '"ADOBECODEBANC"\n"ABC"'
 *
 * Given a string S and a string T, find the minimum window in S which will
 * contain all the characters in T in complexity O(n).
 * 
 * Example:
 * 
 * 
 * Input: S = "ADOBECODEBANC", T = "ABC"
 * Output: "BANC"
 * 
 * 
 * Note:
 * 
 * 
 * If there is no such window in S that covers all characters in T, return the
 * empty string "".
 * If there is such window, you are guaranteed that there will always be only
 * one unique minimum window in S.
 * 
 * 
 */
#include<string>
#include<vector>
#include<unordered_map>
using namespace std; 

// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        // 初始化计数
        vector<int> t_count(128, 0);
        for(auto ch: t) t_count[ch]++;

        int left=0, right=0, len=1;
        int left_ans = 0, len_ans=INT_MAX;
        int count = t.size();

        while(right < s.size()){
            if (count > 0){
                char ch_right = s[right];
                if(t_count[ch_right]>0) 
                    count--;
                t_count[ch_right]--;
                right++;
            }

            while (count==0){
                len = right-left;
                if(len<len_ans) {
                    len_ans = len;
                    left_ans = left;
                }

                char ch_left = s[left];
                if(t_count[ch_left]==0) 
                    count++;
                t_count[ch_left]++;
                left++;
            }
        }

        return len_ans==INT_MAX? "" : s.substr(left_ans, len_ans);
    }
};
// @lc code=end

