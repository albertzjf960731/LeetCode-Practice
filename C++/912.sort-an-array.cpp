/*
 * @lc app=leetcode id=912 lang=cpp
 *
 * [912] Sort an Array
 *
 * https://leetcode.com/problems/sort-an-array/description/
 *
 * algorithms
 * Medium (62.58%)
 * Likes:    247
 * Dislikes: 179
 * Total Accepted:    47.7K
 * Total Submissions: 76.3K
 * Testcase Example:  '[5,2,3,1]'
 *
 * Given an array of integers nums, sort the array in ascending order.
 * 
 * 
 * Example 1:
 * Input: nums = [5,2,3,1]
 * Output: [1,2,3,5]
 * Example 2:
 * Input: nums = [5,1,1,2,0,0]
 * Output: [0,0,1,1,2,5]
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 50000
 * -50000 <= nums[i] <= 50000
 * 
 * 
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        
    }
    // 按照排序的效率分有以下10种:
    // 1.简单排序:冒泡排序、(直接)选择排序、(直接)插入排序。
    // 2.高效排序:快速排序、堆排序、希尔排序。
    // 3.基于分治递归思想的:归并排序。
    // 4.线性排序:计数排序、桶排序、基数排序。

    // 按照排序的方式又可分为:

    // 1.插入排序:直接插入排序、希尔排序。
    // 2.选择排序:直接选择排序、堆排序。
    // 3.交换排序:冒泡排序、快速排序。
    // 4.线性排序:计数排序、基数排序、桶排序;其中基数排序又叫桶排序;
    // 5.递归排序:归并排序。
    
    // 简单排序
    void bubble_sort(vector<int>& nums) {
        for (int i=0; i<nums.size()-1; i++)
            for (int j=0; j<nums.size()-1-i; j++)
                if (nums[j]>nums[j+1])
                    swap(nums[j], nums[j+1]);
    }    

    void insertion_sort(vector<int>& nums) {
        for(int i=1; i<nums.size(); i++){
            int num = nums[i];
            int j = i-1;
            while(j>=0 && nums[j]>num){
                nums[j+1] = nums[j];
                j--;
            }
            nums[j+1] = num;
        }
    }

    void selection_sort(vector<int>& nums) {
        for (int i=0; i<nums.size()-1; i++) {
            int idx = i;
            for (int j=i+1; j<nums.size(); j++)
                if (nums[j]<nums[idx])
                    idx = j;
            swap(nums[i], nums[idx]);
        }
    }
    
    // 高效排序
    {
        random_shuffle(nums.begin(), nums.end());
        qSort(nums, 0, nums.size()-1);
        return nums;
    }
    void quick_sort(vector<int>& nums, int left, int right) {
        if(left>=right)
            return;
        int idx = partition(nums, left, right);
        quick_sort(nums, left, idx-1);
        quick_sort(nums, idx+1, right);
    }
    int partition(vector<int>& nums, int left, int right) {
        int pivot=nums[left], l=left+1, r=right;
        while (l<=r) {
            if (nums[l]>pivot && nums[r]<pivot)
                swap(nums[l++], nums[r--]);
            if (nums[l]<=pivot) l++;
            if (nums[r]>=pivot) r--;
        }
        swap(nums[left], nums[r]);
        return r;
    }

    void heap_sort(vector<int>& nums) {
        for (int i=nums.size()/2-1; i>= 0; i--)
            max_heapify(nums, i, nums.size()-1);
        for (int i=nums.size()-1; i>0; i--) {
            swap(nums[0], nums[i]);
            max_heapify(nums, 0, i-1);
        }
    }
    void max_heapify(vector<int>& nums, int left, int right) {
        int parent = left;
        int child = parent*2 + 1;
        while (child<=right) { 
            // 选择较大的自节点
            if (child+1<=right && nums[child]<nums[child+1])
                child++;
            // 父节点大于子节点
            if (nums[parent]>nums[child]) 
                return;
            else { 
                swap(nums[parent], nums[child]);
                parent = child;
                child = parent*2 + 1;
            }
        }
    }

    void shell_sort(vector<int>& nums) {
        int d = nums.size()/2;
        while (d>=1) {
            for (int i=d; i<nums.size(); i++) {
                for (int j=i; j>=d && nums[j]<nums[j-d]; j-=d) {
                    swap(nums[j], nums[j-d]);
                }
            }
            d = d/2;
        }
    }

    void merge_sort(vector<int> &nums, int left, int right) {
        if (left >= right)
            return;
        int mid = left + (right-left)/2;
        merge_sort(nums, left, mid);
        merge_sort(nums, mid+1, right);
        merge(nums, left, mid, right);
    }

    void merge(vector<int> &nums, int left, int mid, int right) {
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
    }


};
// @lc code=end

