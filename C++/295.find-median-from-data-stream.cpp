/*
 * @lc app=leetcode id=295 lang=cpp
 *
 * [295] Find Median from Data Stream
 *
 * https://leetcode.com/problems/find-median-from-data-stream/description/
 *
 * algorithms
 * Hard (40.00%)
 * Likes:    1676
 * Dislikes: 33
 * Total Accepted:    146K
 * Total Submissions: 364.6K
 * Testcase Example:  '["MedianFinder","addNum","addNum","findMedian","addNum","findMedian"]\n' +
  '[[],[1],[2],[],[3],[]]'
 *
 * Median is the middle value in an ordered integer list. If the size of the
 * list is even, there is no middle value. So the median is the mean of the two
 * middle value.
 * For example,
 * 
 * [2,3,4], the median is 3
 * 
 * [2,3], the median is (2 + 3) / 2 = 2.5
 * 
 * Design a data structure that supports the following two operations:
 * 
 * 
 * void addNum(int num) - Add a integer number from the data stream to the data
 * structure.
 * double findMedian() - Return the median of all elements so far.
 * 
 * 
 * 
 * 
 * Example:
 * 
 * 
 * addNum(1)
 * addNum(2)
 * findMedian() -> 1.5
 * addNum(3) 
 * findMedian() -> 2
 * 
 * 
 * 
 * 
 * Follow up:
 * 
 * 
 * If all integer numbers from the stream are between 0 and 100, how would you
 * optimize it?
 * If 99% of all integer numbers from the stream are between 0 and 100, how
 * would you optimize it?
 * 
 * 
 */
#include<vector>
#include<queue>
using namespace std;

// @lc code=start
class MedianFinder {
private:
    priority_queue<int> max_pq;
    priority_queue<int, vector<int>, greater<int>> min_pq;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (min_pq.size() < max_pq.size()) {
            max_pq.push(num);
            min_pq.push(max_pq.top());
            max_pq.pop();
        }
        else {
            min_pq.push(num);
            max_pq.push(min_pq.top());
            min_pq.pop();
        }
    }
    
    double findMedian() {
        if (min_pq.size() == max_pq.size()) 
            return (min_pq.top() + max_pq.top()) / 2.0;
        else 
            return max_pq.top();
    }  return max_pq.top();
    }

// private:
//     multiset<int> ans;
//     multiset<int>::iterator it;
    
// public:
//     /** initialize your data structure here. */
//     MedianFinder() {
        
//     }
    
//     void addNum(int num) {
//         if (ans.size() == 0) {
//             it = ans.insert(num);
//             return;
//         }
        
//         ans.insert(num);
//         if (ans.size()%2!=0 && num<*it) --it;
//         else if (ans.size()%2==0 && num>=*it) ++it;
        
//     }
    
//     double findMedian() {
//         if (ans.size()%2 != 0) 
//             return *it;
//         else 
//             return (double) (*it+*prev(it))/2;
//     }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end

