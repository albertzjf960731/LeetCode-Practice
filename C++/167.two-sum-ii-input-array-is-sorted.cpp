/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input array is sorted
 *
 * https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/
 *
 * algorithms
 * Easy (52.51%)
 * Likes:    1291
 * Dislikes: 514
 * Total Accepted:    341.6K
 * Total Submissions: 650.5K
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * Given an array of integers that is already sorted in ascending order, find
 * two numbers such that they add up to a specific target number.
 * 
 * The function twoSum should return indices of the two numbers such that they
 * add up to the target, where index1 must be less than index2.
 * 
 * Note:
 * 
 * 
 * Your returned answers (both index1 and index2) are not zero-based.
 * You may assume that each input would have exactly one solution and you may
 * not use the same element twice.
 * 
 * 
 * Example:
 * 
 * 
 * Input: numbers = [2,7,11,15], target = 9
 * Output: [1,2]
 * Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.
 * 
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int left=0, right=nums.size()-1;
        while (left<right) {
            int num = nums[left]+nums[right];
            if (num<target) left++;
            else if (num>target) right--;
            else return vector<int>{left+1, right+1};   
        }
        return vector<int>();
    }
};
// @lc code=end

// find pair in an array having minimum absolute sum 

#include <iostream>
#include <cstdlib>
#include <climits>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        while (left < right) {
            int sum = nums[left] + nums[right];
            if (sum == target) break;
            else if (sum < target) left++;
            else right--;
        }
        return {left+1, right+1};
    }
};

// Function to find a pair in an array with minimum absolute sum
void findPair(int arr[], int n)
{
	if (n < 2)
		return;

	// sort the array if array is unsorted
	// sort(arr, arr + n);

	// maintain two indexes pointing to end-points of the array
	int low = 0;
	int high = n - 1;

	// min stores minimum absolute difference
	int min = INT_MAX;
	int i, j;

	// reduce search space arr[low..high] at each iteration of the loop

	// loop till low is less than high
	while (low < high)
	{
		// update minimum if current absolute sum is less
		if (abs(arr[high] + arr[low]) < min)
		{
			min = abs(arr[high] + arr[low]);
			i = low;
			j = high;
		}

		// optimization - pair with 0 sum is found
		if (min == 0)
			break;

		// increment low index if total is less than 0
		// decrement high index is total is more than 0
		(arr[high] + arr[low] < 0)? low++: high--;
	}

	// print the pair
	cout << "Pair found (" << arr[i] << ", " << arr[j] << ")";
}

// Find Pair in an Array having Minimum Absolute Sum
int main()
{
	int arr[] = { -6, -5, -3, 0, 2, 4, 9 };
	int n = sizeof(arr)/sizeof(arr[0]);

	findPair(arr, n);

	return 0;
}