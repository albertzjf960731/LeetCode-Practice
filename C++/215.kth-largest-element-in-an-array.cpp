/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 *
 * https://leetcode.com/problems/kth-largest-element-in-an-array/description/
 *
 * algorithms
 * Medium (51.60%)
 * Likes:    2850
 * Dislikes: 209
 * Total Accepted:    511.5K
 * Total Submissions: 983.6K
 * Testcase Example:  '[3,2,1,5,6,4]\n2'
 *
 * Find the kth largest element in an unsorted array. Note that it is the kth
 * largest element in the sorted order, not the kth distinct element.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,2,1,5,6,4] and k = 2
 * Output: 5
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [3,2,3,1,2,4,5,5,6] and k = 4
 * Output: 4
 * 
 * Note: 
 * You may assume k is always valid, 1 ≤ k ≤ array's length.
 * 
 */

// 1. 按从大到小全排序，然后取第k个元素，时间复杂度O(nlogn)，空间复杂度O(1)
// 2. 利用堆进行部分排序。维护一个大根堆，将数组元素全部压入堆，然后弹出k次，第k个就是答案。时间复杂度O(klogn)，空间复杂度O(n)
// 3. 选择排序，第k次选择后即可得到第k大的数，时间复杂度O(nk)，空间复杂度O(1)
// 4. 堆排序，维护一个k大小的小根堆，将数组中的每个元素与堆顶元素进行比较，如果比堆顶元素大，则删除堆顶元素并添加该元素，如果比堆顶元素小，则什么也不做，继续下一个元素。时间复杂度O(nlogk)，空间复杂度O(k)。
// 5. 利用快速排序中的partition思想，从数组中随机选择一个元素x，把数组划分为前后两部分sa和sb，sa中的元素小于x，sb中的元素大于或等于x。这时有两种情况：
// sa的元素个数小于k，则递归求解sb中的第k-|sa|大的元素
// sa的元素个数大于或等于k，则递归求解sa中的第k大的元素
// 时间复杂度O(n)，空间复杂度O(1)

#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

// @lc code=start
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // nth_element(nums.begin(), nums.begin()+k-1, nums.end(), greater<int>());
        // return nums[k-1];

        // partial_sort(nums.begin(), nums.begin()+k, nums.end(), greater<int>());
        // return nums[k-1];

        // min-heap
        // priority_queue<int, vector<int>, greater<int>> pq;
        // for(int num: nums) {
        //     pq.push(num);
        //     if (pq.size() > k)
        //         pq.pop();
        // }
        // return pq.top();

        // max-heap
        // priority_queue<int> pq{nums.begin(), nums.end()};
        // for (int i=0; i<k-1; i++)
        //     pq.pop();
        // return pq.top();

        // int left = 0, right = nums.size()-1, kth;
        // while (true) {
        //     int idx = partition(nums, left, right);
        //     if (idx==k-1){
        //         kth = nums[idx];
        //         break;
        //     }
        //     if(idx < k-1)
        //         left = idx+1;
        //     else
        //         right = idx-1;
        // }
        // return kth;

        int left = 0, right = nums.size()-1;
        while (left<=right) {
            int idx = partition(nums, left, right);
            
            if (idx < k-1) 
                left = idx+1;
            else if (idx > k-1)
                right = idx-1;
            else 
                return nums[idx];
        }
        return -1;
    }

private:
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[left], l=left+1, r=right;
        while(l<=r){
            if (nums[l]<pivot && nums[r]>pivot)
                swap(nums[l++], nums[r--]);
            if (nums[l]>=pivot)
                l++;
            if (nums[r]<=pivot)
                r--;
        }
        swap(nums[left], nums[r]);
        return r;
    }
};
// @lc code=end

