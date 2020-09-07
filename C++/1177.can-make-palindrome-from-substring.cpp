/*
 * @lc app=leetcode id=1177 lang=cpp
 *
 * [1177] Can Make Palindrome from Substring
 *
 * https://leetcode.com/problems/can-make-palindrome-from-substring/description/
 *
 * algorithms
 * Medium (32.95%)
 * Likes:    141
 * Dislikes: 128
 * Total Accepted:    8.4K
 * Total Submissions: 25.4K
 * Testcase Example:  '"abcda"\n[[3,3,0],[1,2,0],[0,3,1],[0,3,2],[0,4,1]]'
 *
 * Given a string s, we make queries on substrings of s.
 * 
 * For each query queries[i] = [left, right, k], we may rearrange the substring
 * s[left], ..., s[right], and then choose up to k of them to replace with any
 * lowercase English letter. 
 * 
 * If the substring is possible to be a palindrome string after the operations
 * above, the result of the query is true. Otherwise, the result is false.
 * 
 * Return an array answer[], where answer[i] is the result of the i-th query
 * queries[i].
 * 
 * Note that: Each letter is counted individually for replacement so if for
 * example s[left..right] = "aaa", and k = 2, we can only replace two of the
 * letters.  (Also, note that the initial string s is never modified by any
 * query.)
 * 
 * 
 * Example :
 * 
 * 
 * Input: s = "abcda", queries = [[3,3,0],[1,2,0],[0,3,1],[0,3,2],[0,4,1]]
 * Output: [true,false,false,true,true]
 * Explanation:
 * queries[0] : substring = "d", is palidrome.
 * queries[1] : substring = "bc", is not palidrome.
 * queries[2] : substring = "abcd", is not palidrome after replacing only 1
 * character.
 * queries[3] : substring = "abcd", could be changed to "abba" which is
 * palidrome. Also this can be changed to "baab" first rearrange it "bacd" then
 * replace "cd" with "ab".
 * queries[4] : substring = "abcda", could be changed to "abcba" which is
 * palidrome.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length, queries.length <= 10^5
 * 0 <= queries[i][0] <= queries[i][1] < s.length
 * 0 <= queries[i][2] <= s.length
 * s only contains lowercase English letters.
 * 
 * 
 */
#include<vector>
#include<string>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {

        // 对于每次询问，统计区间内出现次数为奇数的字母的个数 tt。
        // 如果 k≥t/2k≥t/2，则我们可以通过替换将其变成回文串。这是因为，出现次数为偶数的字母我们不需要担心；出现次数为奇数的字母，我们替换其中的一半（如果长度为奇数则替换一半的下取整）则可以将他们配对。
        // 为了快速求出区间内每个字母出现的次数，我们通过前缀和数组 ch(i,j)ch(i,j)，记录前 ii 个字母中，字母 jj 出现的次数。
        // 每次询问，求出区间 [l, r] 内的字母个数。

        vector<vector<int>> prefix(26, vector<int>(s.size()+1, 0));
        for(int i=0; i<s.size(); ++i){
            for(int j=0 ; j<26; ++j){
                prefix[j][i+1] = prefix[j][i] + (s[i]-'a'==j ? 1 : 0);
            }
        }  

        vector<bool> res;
        for(auto query: queries)
            res.push_back(isValid(prefix, query[0], query[1], query[2]));

        return res;
    }

    bool isValid(vector<vector<int>> &prefix, int left,int right, int k){
        int sum = 0;

        for(int i=0; i<26; ++i){
            sum += (prefix[i][right+1] - prefix[i][left])%2;
        }

        return (sum/2) <= k; 
    }
};
// @lc code=end

