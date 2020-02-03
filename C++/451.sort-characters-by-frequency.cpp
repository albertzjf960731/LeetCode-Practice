/*
 * @lc app=leetcode id=451 lang=cpp
 *
 * [451] Sort Characters By Frequency
 *
 * https://leetcode.com/problems/sort-characters-by-frequency/description/
 *
 * algorithms
 * Medium (58.50%)
 * Likes:    994
 * Dislikes: 89
 * Total Accepted:    124.4K
 * Total Submissions: 212.6K
 * Testcase Example:  '"tree"'
 *
 * Given a string, sort it in decreasing order based on the frequency of
 * characters.
 * 
 * Example 1:
 * 
 * Input:
 * "tree"
 * 
 * Output:
 * "eert"
 * 
 * Explanation:
 * 'e' appears twice while 'r' and 't' both appear once.
 * So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid
 * answer.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input:
 * "cccaaa"
 * 
 * Output:
 * "cccaaa"
 * 
 * Explanation:
 * Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
 * Note that "cacaca" is incorrect, as the same characters must be together.
 * 
 * 
 * 
 * Example 3:
 * 
 * Input:
 * "Aabb"
 * 
 * Output:
 * "bbAa"
 * 
 * Explanation:
 * "bbaA" is also a valid answer, but "Aabb" is incorrect.
 * Note that 'A' and 'a' are treated as two different characters.
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
    string frequencySort(string str) {
        unordered_map<char, int> count;
        for (char ch: str)
            count[ch]++;
        
        // vector<string> buckets(str.size()+1, "");
        // for(auto& it: count) 
        //     buckets[it.second].append(it.second, it.first);
        
        // string res;
        // for (int i=str.size(); i>0; i--) {
        //     if (!buckets[i].empty())
        //         res.append(buckets[i]);
        // }
        // return res;

        sort(str.begin(), str.end(), [&](char a, char b) {
            return count[a] > count[b] || (count[a] == count[b] && a < b); 
        });
        return str;
    }
};
// @lc code=end

