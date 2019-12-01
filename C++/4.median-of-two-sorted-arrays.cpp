/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */
#include<vector>
#include<iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size(), size2 = nums2.size();
        double l=-1, r=-1;
        int i=0, j=0;

        for (int k=0; k<(size1+size2)/2+1;k++) {
            l=r;
            if (i<size1 && (j>=size2 || nums1[i]<nums2[j])) {
                r = nums1[i];
                i++;
            }
            else {
                r = nums2[j];
                j++;
            }
        }
        if ((size1+size2)%2==0) 
            return (l+r)/2;
        else 
            return r;
    }
};
// @lc code=end

int main() {
    Solution sol;
    vector<int> nums1={1,2}, nums2={3,4};
    double res = sol.findMedianSortedArrays(nums1, nums2);
    cout<<"res="<<res<<endl;
    return 0;
}
