/*
 * @lc app=leetcode id=433 lang=cpp
 *
 * [433] Minimum Genetic Mutation
 *
 * https://leetcode.com/problems/minimum-genetic-mutation/description/
 *
 * algorithms
 * Medium (40.20%)
 * Likes:    336
 * Dislikes: 42
 * Total Accepted:    26.8K
 * Total Submissions: 66.5K
 * Testcase Example:  '"AACCGGTT"\n"AACCGGTA"\n["AACCGGTA"]'
 *
 * A gene string can be represented by an 8-character long string, with choices
 * from "A", "C", "G", "T".
 * 
 * Suppose we need to investigate about a mutation (mutation from "start" to
 * "end"), where ONE mutation is defined as ONE single character changed in the
 * gene string.
 * 
 * For example, "AACCGGTT" -> "AACCGGTA" is 1 mutation.
 * 
 * Also, there is a given gene "bank", which records all the valid gene
 * mutations. A gene must be in the bank to make it a valid gene string.
 * 
 * Now, given 3 things - start, end, bank, your task is to determine what is
 * the minimum number of mutations needed to mutate from "start" to "end". If
 * there is no such a mutation, return -1.
 * 
 * Note:
 * 
 * 
 * Starting point is assumed to be valid, so it might not be included in the
 * bank.
 * If multiple mutations are needed, all mutations during in the sequence must
 * be valid.
 * You may assume start and end string is not the same.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * start: "AACCGGTT"
 * end:   "AACCGGTA"
 * bank: ["AACCGGTA"]
 * 
 * return: 1
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * start: "AACCGGTT"
 * end:   "AAACGGTA"
 * bank: ["AACCGGTA", "AACCGCTA", "AAACGGTA"]
 * 
 * return: 2
 * 
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * start: "AAAAACCC"
 * end:   "AACCCCCC"
 * bank: ["AAAACCCC", "AAACCCCC", "AACCCCCC"]
 * 
 * return: 3
 * 
 * 
 * 
 * 
 */
#include<string>
#include<vector>
#include<queue>
#include<unordered_set>
using namespace std;

// @lc code=start
class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        if (bank.empty()) return -1;
        unordered_set<string> gene_set(bank.begin(), bank.end());
        if (!gene_set.count(end)) return -1;
        
        int ans = 0;
        queue<string> q;
        q.push(start);
        while (!q.empty()) {
            int q_size = q.size();
            while (q_size--) {
                string gene = q.front();
                q.pop();
                
                if (gene==end)
                    return ans;
                for (int i=0; i<gene.size(); i++) {
                    char ch = gene[i];
                    for (char j: vector<int>{'A', 'C', 'G', 'T'}) {
                        gene[i] = j;
                        if (gene_set.count(gene)) {
                            q.push(gene);
                            gene_set.erase(gene);
                        }
                    }
                    gene[i] = ch;
                }
            }
            ans ++;
        }
        return -1;
    }
};
// @lc code=end

