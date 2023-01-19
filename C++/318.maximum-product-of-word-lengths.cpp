/*
 * @lc app=leetcode id=318 lang=cpp
 *
 * [318] Maximum Product of Word Lengths
 *
 * https://leetcode.com/problems/maximum-product-of-word-lengths/description/
 *
 * algorithms
 * Medium (56.71%)
 * Likes:    1793
 * Dislikes: 96
 * Total Accepted:    146.3K
 * Total Submissions: 256.7K
 * Testcase Example:  '["abcw","baz","foo","bar","xtfn","abcdef"]'
 *
 * Given a string array words, return the maximum value of length(word[i]) *
 * length(word[j]) where the two words do not share common letters. If no such
 * two words exist, return 0.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: words = ["abcw","baz","foo","bar","xtfn","abcdef"]
 * Output: 16
 * Explanation: The two words can be "abcw", "xtfn".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: words = ["a","ab","abc","d","cd","bcd","abcd"]
 * Output: 4
 * Explanation: The two words can be "ab", "cd".
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: words = ["a","aa","aaa","aaaa"]
 * Output: 0
 * Explanation: No such pair of words.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 2 <= words.length <= 1000
 * 1 <= words[i].length <= 1000
 * words[i] consists only of lowercase English letters.
 * 
 * 
 */

#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> mask(n, 0);
        for (int i=0; i<n; i++) {
            for (char c: words[i]) {
                mask[i] |= (1<<(c-'a'));
            }
        }
        int ans = 0;
        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                if ((mask[i] & mask[j]) == 0) {
                    ans = max(ans, int(words[i].size()*words[j].size()));
                }
            }
        }
        return ans;
    }
};
// @lc code=end

