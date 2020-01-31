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
    // double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    //     int size1 = nums1.size(), size2 = nums2.size();
    //     double l=-1, r=-1;
    //     int i=0, j=0;

    //     for (int k=0; k<(size1+size2)/2+1; ++k) {
    //         l = r;
    //         if (i<size1 && (j>=size2 || nums1[i]<nums2[j])) {
    //             r = nums1[i];
    //             i++;
    //         }
    //         else {
    //             r = nums2[j];
    //             j++;
    //         }
    //     }
    //     if ((size1+size2)%2==0) 
    //         return (l+r)/2;
    //     else 
    //         return r;
    // }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size(), size2 = nums2.size();
        int k = size1 + size2;

        if (k%2 == 1) 
            return findKth(nums1, 0, size1-1, nums2, 0, size2-1, k/2);
        else 
            return  (findKth(nums1, 0, size1-1, nums2, 0, size2-1, k/2) + findKth(nums1, 0, size1-1, nums2, 0, size2-1, k/2-1)) / 2.0;
    }

private:
    int findKth(vector<int>& nums1, int l1, int r1, vector<int>& nums2, int l2, int r2, int k) {

        int size1=r1-l1+1, size2=r2-l2+1;
        if (size1==0) 
            return nums2[l2+k];
        if (size2==0)
            return nums1[l1+k];

        int m1=size1/2, m2=size2/2;
        if (m1+m2 < k) {
            if(nums1[l1+m1] > nums2[l2+m2]){
                return findKth(nums1, l1, r1, nums2, l2+m2+1, r2, k-m2-1);
            }
            else {
                return findKth(nums1, l1+m1+1, r1, nums2, l2, r2, k-m1-1);
            }
        }
        else {
            if (nums1[l1+m1]>nums2[l2+m2]){
                return findKth(nums1, l1, l1+m1-1, nums2, l2, r2, k);
            }
            else {
                return findKth(nums1, l1, r1, nums2, l2, l2+m2-1, k);
            }
        }
    }
};
// @lc code=end

int main() {
    Solution sol;
    vector<int> nums1={1,2,3}, nums2={4,5, 6};
    // double res = sol.findKth(nums1, 0, nums1.size()-1, nums2, 0, nums2.size()-1, 3);
    double res = sol.findMedianSortedArrays(nums1, nums2);
    cout<<"res="<<res<<endl;
    return 0;
}
