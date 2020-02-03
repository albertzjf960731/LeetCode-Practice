/*
 * @lc app=leetcode id=692 lang=cpp
 *
 * [692] Top K Frequent Words
 *
 * https://leetcode.com/problems/top-k-frequent-words/description/
 *
 * algorithms
 * Medium (48.52%)
 * Likes:    1224
 * Dislikes: 109
 * Total Accepted:    114.8K
 * Total Submissions: 234.8K
 * Testcase Example:  '["i", "love", "leetcode", "i", "love", "coding"]\n2'
 *
 * Given a non-empty list of words, return the k most frequent elements.
 * Your answer should be sorted by frequency from highest to lowest. If two
 * words have the same frequency, then the word with the lower alphabetical
 * order comes first.
 * 
 * Example 1:
 * 
 * Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
 * Output: ["i", "love"]
 * Explanation: "i" and "love" are the two most frequent words.
 * ⁠   Note that "i" comes before "love" due to a lower alphabetical order.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is",
 * "is"], k = 4
 * Output: ["the", "is", "sunny", "day"]
 * Explanation: "the", "is", "sunny" and "day" are the four most frequent
 * words,
 * ⁠   with the number of occurrence being 4, 3, 2 and 1 respectively.
 * 
 * 
 * 
 * Note:
 * 
 * You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
 * Input words contain only lowercase letters.
 * 
 * 
 * 
 * Follow up:
 * 
 * Try to solve it in O(n log k) time and O(n) extra space.
 * 
 * 
 */
#include<vector>
#include<unordered_map>
#include<map>
#include<string>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> counts;
        for (string word: words) 
            counts[word]++;
        
        vector<vector<string>> buckets(words.size()+1);
        for(auto it=counts.begin(); it!=counts.end(); ++it)
            buckets[it->second].push_back(it->first);
        
        vector<string> res;
        for (int count=words.size(); count>0 && k>0; count--) {
            if (buckets[count].empty()) continue;

            int size = min(k, (int)buckets[count].size());
            // for (int i=0; i<size; i++) 
            //     res.push_back(buckets[count][i]);
            res.insert(res.end(), buckets[count].begin(), buckets[count].begin()+size);
            
            k-=size;
        }
        return res;
    }
};
// @lc code=end

