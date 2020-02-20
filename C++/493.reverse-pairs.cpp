/*
 * @lc app=leetcode id=493 lang=cpp
 *
 * [493] Reverse Pairs
 *
 * https://leetcode.com/problems/reverse-pairs/description/
 *
 * algorithms
 * Hard (24.31%)
 * Likes:    696
 * Dislikes: 107
 * Total Accepted:    32.4K
 * Total Submissions: 133.3K
 * Testcase Example:  '[1,3,2,3,1]'
 *
 * Given an array nums, we call (i, j) an important reverse pair if i < j and
 * nums[i] > 2*nums[j].
 * 
 * You need to return the number of important reverse pairs in the given
 * array.
 * 
 * Example1:
 * 
 * Input: [1,3,2,3,1]
 * Output: 2
 * 
 * 
 * Example2:
 * 
 * Input: [2,4,3,5,1]
 * Output: 3
 * 
 * 
 * Note:
 * 
 * The length of the given array will not exceed 50,000.
 * All the numbers in the input array are in the range of 32-bit integer.
 * 
 * 
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
    int count;
   
    void merge(vector<int>& nums, int left, int mid, int right){
        int l=left, r = mid+1;
        while(l<=mid && r<=right){
            if((long)nums[l] > (long)2*nums[r]){
                count += (mid-l+1);
                r++;
            }
            else
                l++;
        }
        // sort(nums.begin()+left, nums.begin()+right+1);
        
        vector<int> tmp(right-left+1);

        int i=left, j=mid+1, k=0;
        while (i<=mid && j<=right) {
            if (nums[i]<=nums[j])
                tmp[k++] = nums[i++];
            else
                tmp[k++] = nums[j++];
        }
        while (i<=mid) tmp[k++] = nums[i++];
        while (j<=right) tmp[k++] = nums[j++];   

        for (int p=0; p<tmp.size(); p++)
            nums[left+p] = tmp[p];
        return;
    }
    
    void mergeSort(vector<int>& nums, int left, int right){
        if (left>=right) return;
        
        int mid = left + (right-left)/2;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid+1, right);
        merge(nums, left, mid, right);
        return;
    }
public:
    int reversePairs(vector<int>& nums) {
        if(!nums.size()) return 0;
        count = 0;
        mergeSort(nums, 0, nums.size()-1);
        return count;
    }


    int sort_and_count(vector<int>::iterator begin, vector<int>::iterator end) {
        if (end - begin <= 1)
            return 0;
        auto mid = begin + (end - begin) / 2;
        int count = sort_and_count(begin, mid) + sort_and_count(mid, end);
        for (auto i = begin, j = mid; i != mid; ++i) {
            while (j != end and *i > 2L * *j)
                ++j;
            count += j - mid;
        }
        inplace_merge(begin, mid, end);
        return count;
    }

    int reversePairs(vector<int>& nums) {
        return sort_and_count(nums.begin(), nums.end());
    }
};
// @lc code=end

