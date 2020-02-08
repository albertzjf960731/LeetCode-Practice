/*
 * @lc app=leetcode id=60 lang=cpp
 *
 * [60] Permutation Sequence
 *
 * https://leetcode.com/problems/permutation-sequence/description/
 *
 * algorithms
 * Medium (34.69%)
 * Likes:    1079
 * Dislikes: 277
 * Total Accepted:    157.8K
 * Total Submissions: 454.6K
 * Testcase Example:  '3\n3'
 *
 * The set [1,2,3,...,n] contains a total of n! unique permutations.
 * 
 * By listing and labeling all of the permutations in order, we get the
 * following sequence for n = 3:
 * 
 * 
 * "123"
 * "132"
 * "213"
 * "231"
 * "312"
 * "321"
 * 
 * 
 * Given n and k, return the k^th permutation sequence.
 * 
 * Note:
 * 
 * 
 * Given n will be between 1 and 9 inclusive.
 * Given k will be between 1 and n! inclusive.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 3, k = 3
 * Output: "213"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 4, k = 9
 * Output: "2314"
 * 
 * 
 */
#include<string>
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    // string getPermutation(int n, int k) {
    //     vector<int> nums;
    //     for (int i=1; i<=n; i++)
    //         nums.push_back(i);
    //     for (int i=0; i<k-1; i++)
    //         nextPermutation(nums);
    //     string res;
    //     for (int num:nums) 
    //         res.push_back('0'+num);
    //     return res;
    // }

    // void nextPermutation(vector<int>& nums) {
    //     int i = nums.size()-2;
    //     while ((i>=0 && nums[i]>=nums[i+1]))
    //         i--;
    //     if (i<0) 
    //         reverse(nums.begin(), nums.end());
    //     else {
    //         int j = nums.size()-1;
    //         while (j>=0 && nums[j]<=nums[i]) 
    //             j--;
    //         swap(nums[i], nums[j]);
    //         reverse(nums.begin()+i+1, nums.end());
    //     }
    // }

    string getPermutation(int n, int k) {

        int factorial = 1;
        string res(n,'0');
        for(int i=1; i<=n; i++){
            factorial *= i;
            res[i-1] += i; //"1234"
        }

        k--;
        for(int i=0; i<n; i++){
            factorial /= (n-i);
            // i 之后的数字从小到大排好序的
            int j = i + k/factorial;  // calculate index of char to put at s[i]
            k %= factorial;
            
            // remove c by shifting to cover up (adjust the right part).
            char num = res[j];
            for(; j>i; j--)
                res[j]=res[j-1];
            res[i] = num;
        }
        return res;
    }
};
// @lc code=end

