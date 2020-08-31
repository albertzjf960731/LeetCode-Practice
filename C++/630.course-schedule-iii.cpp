/*
 * @lc app=leetcode id=630 lang=cpp
 *
 * [630] Course Schedule III
 */

// @lc code=start
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];});
        
        int curTime = 0;
        priority_queue<int> q;

        for (auto course : courses) {
            curTime += course[0];
            q.push(course[0]);
            while (curTime > course[1]) {
                curTime -= q.top(); 
                q.pop();
            }
        }
        return q.size();   
    }
};
// @lc code=end

