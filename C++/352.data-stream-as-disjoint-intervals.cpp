/*
 * @lc app=leetcode id=352 lang=cpp
 *
 * [352] Data Stream as Disjoint Intervals
 *
 * https://leetcode.com/problems/data-stream-as-disjoint-intervals/description/
 *
 * algorithms
 * Hard (54.45%)
 * Likes:    1053
 * Dislikes: 237
 * Total Accepted:    67.2K
 * Total Submissions: 123.6K
 * Testcase Example:  '["SummaryRanges","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals"]\n' +
  '[[],[1],[],[3],[],[7],[],[2],[],[6],[]]'
 *
 * Given a data stream input of non-negative integers a1, a2, ..., an,
 * summarize the numbers seen so far as a list of disjoint intervals.
 * 
 * Implement the SummaryRanges class:
 * 
 * 
 * SummaryRanges() Initializes the object with an empty stream.
 * void addNum(int value) Adds the integer value to the stream.
 * int[][] getIntervals() Returns a summary of the integers in the stream
 * currently as a list of disjoint intervals [starti, endi]. The answer should
 * be sorted by starti.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input
 * ["SummaryRanges", "addNum", "getIntervals", "addNum", "getIntervals",
 * "addNum", "getIntervals", "addNum", "getIntervals", "addNum",
 * "getIntervals"]
 * [[], [1], [], [3], [], [7], [], [2], [], [6], []]
 * Output
 * [null, null, [[1, 1]], null, [[1, 1], [3, 3]], null, [[1, 1], [3, 3], [7,
 * 7]], null, [[1, 3], [7, 7]], null, [[1, 3], [6, 7]]]
 * 
 * Explanation
 * SummaryRanges summaryRanges = new SummaryRanges();
 * summaryRanges.addNum(1);      // arr = [1]
 * summaryRanges.getIntervals(); // return [[1, 1]]
 * summaryRanges.addNum(3);      // arr = [1, 3]
 * summaryRanges.getIntervals(); // return [[1, 1], [3, 3]]
 * summaryRanges.addNum(7);      // arr = [1, 3, 7]
 * summaryRanges.getIntervals(); // return [[1, 1], [3, 3], [7, 7]]
 * summaryRanges.addNum(2);      // arr = [1, 2, 3, 7]
 * summaryRanges.getIntervals(); // return [[1, 3], [7, 7]]
 * summaryRanges.addNum(6);      // arr = [1, 2, 3, 6, 7]
 * summaryRanges.getIntervals(); // return [[1, 3], [6, 7]]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= value <= 10^4
 * At most 3 * 10^4 calls will be made to addNum and getIntervals.
 * 
 * 
 * 
 * Follow up: What if there are lots of merges and the number of disjoint
 * intervals is small compared to the size of the data stream?
 * 
 */

// @lc code=start
class SummaryRanges {
class SummaryRanges {
private:
    set<int> nums;

public:
    SummaryRanges() {

    }
    
    void addNum(int value) {
        nums.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;

        for (auto it=nums.begin(); it!=nums.end(); ++it) {
            if (ans.size()!=0 && (*it) == ans.back()[1]+1)
                ans.back()[1] = *it;
            else 
                ans.push_back({*it, *it});
        }
        return ans;
    }


private:
    map<int, int> intervals;

public:
    SummaryRanges() {

    }
    
    void addNum(int value) {
        int left = value, right = value;

        auto it = intervals.upper_bound(value);
        if (it != intervals.begin()) {
            auto prev = it; prev--;
            if (prev->second >= value) return;
            if (prev->second == value - 1) left = prev->first;
        }

        if (it != intervals.end() && it->first==value+1) {
            right = it->second;
            intervals.erase(it);
        }

        intervals[left] = right;
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;
        for (auto it: intervals) 
            ans.push_back({it.first, it.second});
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
// @lc code=end

