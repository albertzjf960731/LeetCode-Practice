/*
 * @lc app=leetcode id=1095 lang=cpp
 *
 * [1095] Find in Mountain Array
 *
 * https://leetcode.com/problems/find-in-mountain-array/description/
 *
 * algorithms
 * Hard (35.45%)
 * Likes:    157
 * Dislikes: 20
 * Total Accepted:    7.2K
 * Total Submissions: 20.2K
 * Testcase Example:  '[1,2,3,4,5,3,1]\n3'
 *
 * (This problem is an interactive problem.)
 * 
 * You may recall that an array A is a mountain array if and only if:
 * 
 * 
 * A.length >= 3
 * There exists some i with 0 < i < A.length - 1 such that:
 * 
 * A[0] < A[1] < ... A[i-1] < A[i]
 * A[i] > A[i+1] > ... > A[A.length - 1]
 * 
 * 
 * 
 * 
 * Given a mountain array mountainArr, return the minimum index such that
 * mountainArr.get(index) == target.  If such an index doesn't exist, return
 * -1.
 * 
 * You can't access the mountain array directly.  You may only access the array
 * using a MountainArray interface:
 * 
 * 
 * MountainArray.get(k) returns the element of the array at index k
 * (0-indexed).
 * MountainArray.length() returns the length of the array.
 * 
 * 
 * Submissions making more than 100 calls to MountainArray.get will be judged
 * Wrong Answer.  Also, any solutions that attempt to circumvent the judge will
 * result in disqualification.
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: array = [1,2,3,4,5,3,1], target = 3
 * Output: 2
 * Explanation: 3 exists in the array, at index=2 and index=5. Return the
 * minimum index, which is 2.
 * 
 * Example 2:
 * 
 * 
 * Input: array = [0,1,2,4,2,1], target = 3
 * Output: -1
 * Explanation: 3 does not exist in the array, so we return -1.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 3 <= mountain_arr.length() <= 10000
 * 0 <= target <= 10^9
 * 0 <= mountain_arr.get(index) <= 10^9
 * 
 * 
 */

/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 */

#include<vector>
using namespace std;


class MountainArray {
public:
    int get(int index);
    int length();
};

// @lc code=start
class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();

        int left=0, right=n-1;
        while (left<right) {
            int mid = left + (right-left)/2;
            if (mountainArr.get(mid) < mountainArr.get(mid+1)) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        int idx = left;

        left = 0, right = idx;
        while (left<=right) {
            int mid = left + (right-left)/2;

            int val = mountainArr.get(mid);
            if (val==target)
                return mid;
            else if (val<target)
                left = mid+1;
            else 
                right = mid-1;
        }

        left = idx, right = n-1;
        while (left<=right) {
            int mid = left + (right-left)/2;

            int val = mountainArr.get(mid);
            if (val==target)
                return mid;
            else if (val>target)
                left = mid+1;
            else 
                right = mid-1;
        }
        return -1;
    }
};
// @lc code=end

