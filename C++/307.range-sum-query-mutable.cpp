/*
 * @lc app=leetcode id=307 lang=cpp
 *
 * [307] Range Sum Query - Mutable
 *
 * https://leetcode.com/problems/range-sum-query-mutable/description/
 *
 * algorithms
 * Medium (31.85%)
 * Likes:    998
 * Dislikes: 70
 * Total Accepted:    91.4K
 * Total Submissions: 286.2K
 * Testcase Example:  '["NumArray","sumRange","update","sumRange"]\n[[[1,3,5]],[0,2],[1,2],[0,2]]'
 *
 * Given an integer array nums, find the sum of the elements between indices i
 * and j (i ≤ j), inclusive.
 * 
 * The update(i, val) function modifies nums by updating the element at index i
 * to val.
 * 
 * Example:
 * 
 * 
 * Given nums = [1, 3, 5]
 * 
 * sumRange(0, 2) -> 9
 * update(1, 2)
 * sumRange(0, 2) -> 8
 * 
 * 
 * Note:
 * 
 * 
 * The array is only modifiable by the update function.
 * You may assume the number of calls to update and sumRange function is
 * distributed evenly.
 * 
 * 
 */
#include<vector>
using namespace std; 

// @lc code=start
class NumArray {
// private:
//     int n;
//     vector<int> sums;
    
// public:
//     NumArray(vector<int>& nums) {
//         n = nums.size();
//         sums = vector<int>(n+1, 0);

//         for (int i=0; i<nums.size(); i++) 
//             sums[i+1] = nums[i]+sums[i];
//     }
//     void update(int i, int val) {
//         int diff = val - (sums[i+1]-sums[i]);
//         for (int j=i; j<n; j++) 
//             sums[j+1] += diff;
//     }
    
//     int sumRange(int i, int j) {
//         return sums[j+1]-sums[i];
//     }

// Binary Indexed Trees（中文名为树状数组，下文简称为BIT）是一种特殊的数据结构，可多用于高效计算数列的前缀和， 区间和。对于长度为n的数组，它可以以O(logn)的时间得到任意前缀和 ∑i=1ja[i],1<=j<=N，并同时支持在 O(logn)时间内支持动态单点值的修改。空间复杂度 O(n)
// 虽然BIT名称中带有tree这个词，但是实际存储时是利用两个数组进行存储，记这两个数组为nums和 BIT。假设我们现在需要对原始数组 arr 进行前缀求和和区间求和，那么可以按照以下步骤进行。

// 1.初始化

// nums[i]=arr[i]
// BIT[i]=∑k=i−lowestbit(i)+1iarr[k]
// 上面的lowestbit(i)指将i转为二进制后,最后一个1的位置所代表的数值。如lowestbit(1)=1、lowestbit(6)=2，具体的实现可通过(i&-i)获取。

// 下图就是初始化后的情况，横轴为数组的下标(记为i)，纵轴为下标数值对应的lowestbit（i&-i），长方形表示BIT[i]涵盖的求和的范围



// 可以看到每个数组下标的lowestbit（也就是图中描黑的部分）在形态上构成了一棵树的形状，这也是名称中tree的来源。并且对于每个下标的lowestbit表示成的tree node有以下特性。

// (1)假如i是左子节点，那么其父节点下标为i+(lowestbit(i))
// (2)假如i是右子节点，那么其父节点下标为i-(lowestbit(i))

// 上面这两个特性非常重要，也是我们进行后文分析的重要基础。

// 2. 更新一个数值
// 假如要修改原始数组 arr 中的下标为i的值，那么需要修改nums数组中对应下标的值。除此之外还需要修改BIT数组中涵盖了arr[i]的值。结合上图可以知道，BIT数组中涵盖了arr[i]的值为下标i及其所有父节点，伪代码如下

// while i < n:
//     BIT[i] += new_value
//     i += (i&-i)
// 3. 区间求和

// 假如要求arr数组下标区间为[i,j]的数值之和，那么可以先求下标为[0,i-1]的数值之和，再求下标为[0,j]的数值之和，然后用后者减去前者即可。

// 通过观察上面初始化后的图可以知道求[0, i]可以通过下面的方法：

// count = 0
// while i>0:
//     count += BIT[i]
//     i -= (i&-i)
// 通过上面的操作，通过利用额外的两个数数组，将原来的区间求和的操作从时间复杂度O(n)变为了O(logn),但是更新数组的值的操作的时间复杂度也从原来的O(1)变为了O(logn),所以这种数据结构更适合用于区间求和频繁的应用场景。


private:
    vector<int> bit_;
    vector<int> nums_;

public:
    NumArray(vector<int> &nums) {
        bit_.resize(nums.size()+1);
        nums_ = nums;
        for(int i = 0; i < nums.size(); i++){
            add(i+1, nums[i]);
        }
    }

    int lowbit(int pos){
        return pos&(-pos);
    }
    void add(int pos, int value){
        while(pos < bit_.size()){
            bit_[pos] += value;
            pos += lowbit(pos);
        }
    }
    int sum(int pos){
        int res = 0;
        while(pos > 0){
            res += bit_[pos];
            pos -= lowbit(pos);
        }
        return res;
    }

    void update(int i, int val) {
        int ori = nums_[i];
        int delta = val - ori;
        nums_[i] = val;
        add(i+1, delta);
    }

    int sumRange(int i, int j) {
        return sum(j+1) - sum(i);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */
// @lc code=end

