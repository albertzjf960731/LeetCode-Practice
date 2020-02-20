/*
 * @lc app=leetcode id=315 lang=cpp
 *
 * [315] Count of Smaller Numbers After Self
 *
 * https://leetcode.com/problems/count-of-smaller-numbers-after-self/description/
 *
 * algorithms
 * Hard (40.49%)
 * Likes:    1719
 * Dislikes: 67
 * Total Accepted:    105.7K
 * Total Submissions: 260.8K
 * Testcase Example:  '[5,2,6,1]'
 *
 * You are given an integer array nums and you have to return a new counts
 * array. The counts array has the property where counts[i] is the number of
 * smaller elements to the right of nums[i].
 * 
 * Example:
 * 
 * 
 * Input: [5,2,6,1]
 * Output: [2,1,1,0] 
 * Explanation:
 * To the right of 5 there are 2 smaller elements (2 and 1).
 * To the right of 2 there is only 1 smaller element (1).
 * To the right of 6 there is 1 smaller element (1).
 * To the right of 1 there is 0 smaller element.
 * 
 */
#include<vector>
#include<queue>
using namespace std; 

// @lc code=start

class Solution {
public:
    #define iterator vector<vector<int>>::iterator
    void sort_and_count(iterator begin, iterator end, vector<int>& count) {
        if (end - begin <= 1) 
            return;
        iterator mid = begin + (end-begin)/2;
        sort_and_count(begin, mid, count);
        sort_and_count(mid, end, count);
      
        for (iterator i=begin, j=mid; i!=mid; i++) {
            while (j!=end && (*i)[0] > (*j)[0]) 
                j++;
            count[(*i)[1]] += j - mid; 
        }
        inplace_merge(begin, mid, end);
    }
    vector<int> countSmaller(vector<int>& nums) {
        vector<vector<int>> hold;
        for (int i=0; i<nums.size(); ++i) 
            hold.push_back(vector<int>({nums[i], i}));

        vector<int> count(nums.size(), 0);
        sort_and_count(hold.begin(), hold.end(), count);
        return count;
    }
};
// @lc code=end

