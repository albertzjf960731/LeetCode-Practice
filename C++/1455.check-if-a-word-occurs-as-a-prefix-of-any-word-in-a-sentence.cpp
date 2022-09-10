/*
 * @lc app=leetcode id=1455 lang=cpp
 *
 * [1455] Check If a Word Occurs As a Prefix of Any Word in a Sentence
 *
 * https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/description/
 *
 * algorithms
 * Easy (64.38%)
 * Likes:    574
 * Dislikes: 28
 * Total Accepted:    54.4K
 * Total Submissions: 84.6K
 * Testcase Example:  '"i love eating burger"\n"burg"'
 *
 * Given a sentence that consists of some words separated by a single space,
 * and a searchWord, check if searchWord is a prefix of any word in sentence.
 * 
 * Return the index of the word in sentence (1-indexed) where searchWord is a
 * prefix of this word. If searchWord is a prefix of more than one word, return
 * the index of the first word (minimum index). If there is no such word return
 * -1.
 * 
 * A prefix of a string s is any leading contiguous substring of s.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: sentence = "i love eating burger", searchWord = "burg"
 * Output: 4
 * Explanation: "burg" is prefix of "burger" which is the 4th word in the
 * sentence.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: sentence = "this problem is an easy problem", searchWord = "pro"
 * Output: 2
 * Explanation: "pro" is prefix of "problem" which is the 2nd and the 6th word
 * in the sentence, but we return 2 as it's the minimal index.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: sentence = "i am tired", searchWord = "you"
 * Output: -1
 * Explanation: "you" is not a prefix of any word in the sentence.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= sentence.length <= 100
 * 1 <= searchWord.length <= 10
 * sentence consists of lowercase English letters and spaces.
 * searchWord consists of lowercase English letters.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int n = sentence.size(), m = searchWord.size();
        for (int i=0, idx=1; i<n; ++i, ++idx) {
            if (sentence.substr(i, m) == searchWord) 
                return idx;
            while (i<n && sentence[i]!=' ') ++i;
        }
        return -1;
    }
};
// @lc code=end

