/*
 * @lc app=leetcode id=1662 lang=cpp
 *
 * [1662] Check If Two String Arrays are Equivalent
 *
 * https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/description/
 *
 * algorithms
 * Easy (81.84%)
 * Likes:    1870
 * Dislikes: 167
 * Total Accepted:    242.5K
 * Total Submissions: 291.3K
 * Testcase Example:  '["ab", "c"]\n["a", "bc"]'
 *
 * Given two string arrays word1 and word2, return true if the two arrays
 * represent the same string, and false otherwise.
 * 
 * A string is represented by an array if the array elements concatenated in
 * order forms the string.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: word1 = ["ab", "c"], word2 = ["a", "bc"]
 * Output: true
 * Explanation:
 * word1 represents string "ab" + "c" -> "abc"
 * word2 represents string "a" + "bc" -> "abc"
 * The strings are the same, so return true.
 * 
 * Example 2:
 * 
 * 
 * Input: word1 = ["a", "cb"], word2 = ["ab", "c"]
 * Output: false
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: word1  = ["abc", "d", "defg"], word2 = ["abcddefg"]
 * Output: true
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= word1.length, word2.length <= 10^3
 * 1 <= word1[i].length, word2[i].length <= 10^3
 * 1 <= sum(word1[i].length), sum(word2[i].length) <= 10^3
 * word1[i] and word2[i] consist of lowercase letters.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int w1 = 0, w2 = 0;
        int s1 = 0, s2 = 0;
        while (w1 < word1.size() && w2 < word2.size()) {
            
            if (word1[w1][s1] != word2[w2][s2]) return false;
            
            s1 += 1, s2 += 1;
            if (s1 == word1[w1].size()) s1 = 0, w1 += 1;
            if (s2 == word2[w2].size()) s2 = 0, w2 += 1;

        }
        return s1==0 && s2==0 && w1==word1.size() && w2==word2.size();
    }
};
// @lc code=end

