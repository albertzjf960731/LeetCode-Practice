/*
 * @lc app=leetcode id=406 lang=cpp
 *
 * [406] Queue Reconstruction by Height
 *
 * https://leetcode.com/problems/queue-reconstruction-by-height/description/
 *
 * algorithms
 * Medium (62.28%)
 * Likes:    2079
 * Dislikes: 247
 * Total Accepted:    102.7K
 * Total Submissions: 164.8K
 * Testcase Example:  '[[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]]'
 *
 * Suppose you have a random list of people standing in a queue. Each person is
 * described by a pair of integers (h, k), where h is the height of the person
 * and k is the number of people in front of this person who have a height
 * greater than or equal to h. Write an algorithm to reconstruct the queue.
 * 
 * Note:
 * The number of people is less than 1,100.
 * 
 * 
 * Example
 * 
 * 
 * Input:
 * [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
 * 
 * Output:
 * [[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
 * 
 * 
 * 
 * 
 */
#include<vector>
using namespace std; 
// @lc code=start
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        
        // 为了使插入操作不影响后续的操作，身高较高的学生应该先做插入操作，否则身高较小的学生原先正确插入的第 k 个位置可能会变成第 k+1 个位置。
        sort(people.begin(), people.end(), [](vector<int>& a, vector<int>& b) {
            return a[0]>b[0] || (a[0]==b[0] && a[1]<b[1]);
        });

        // vector<vector<int>> res;
        // for (auto p: people) 
        //     res.insert(res.begin()+p[1], p);
        // return res;

        for (int i=0; i<people.size(); i++) {
            vector<int> p = people[i];
            if (p[1]!=i) {
                people.erase(people.begin()+i);
                people.insert(people.begin()+p[1], p);
            }
        }
        return people;
    }
};
// @lc code=end

