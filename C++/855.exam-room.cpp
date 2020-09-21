/*
 * @lc app=leetcode id=855 lang=cpp
 *
 * [855] Exam Room
 *
 * https://leetcode.com/problems/exam-room/description/
 *
 * algorithms
 * Medium (41.11%)
 * Likes:    469
 * Dislikes: 194
 * Total Accepted:    23.5K
 * Total Submissions: 57.1K
 * Testcase Example:  '["ExamRoom","seat","seat","seat","seat","leave","seat"]\n' +
  '[[10],[],[],[],[],[4],[]]'
 *
 * In an exam room, there are N seats in a single row, numbered 0, 1, 2, ...,
 * N-1.
 * 
 * When a student enters the room, they must sit in the seat that maximizes the
 * distance to the closest person.  If there are multiple such seats, they sit
 * in the seat with the lowest number.  (Also, if no one is in the room, then
 * the student sits at seat number 0.)
 * 
 * Return a class ExamRoom(int N) that exposes two functions: ExamRoom.seat()
 * returning an int representing what seat the student sat in, and
 * ExamRoom.leave(int p) representing that the student in seat number p now
 * leaves the room.  It is guaranteed that any calls to ExamRoom.leave(p) have
 * a student sitting in seat p.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: ["ExamRoom","seat","seat","seat","seat","leave","seat"],
 * [[10],[],[],[],[],[4],[]]
 * Output: [null,0,9,4,2,null,5]
 * Explanation:
 * ExamRoom(10) -> null
 * seat() -> 0, no one is in the room, then the student sits at seat number 0.
 * seat() -> 9, the student sits at the last seat number 9.
 * seat() -> 4, the student sits at the last seat number 4.
 * seat() -> 2, the student sits at the last seat number 2.
 * leave(4) -> null
 * seat() -> 5, the student sits at the last seat number 5.
 * 
 * 
 * ​​​​​​​
 * 
 * Note:
 * 
 * 
 * 1 <= N <= 10^9
 * ExamRoom.seat() and ExamRoom.leave() will be called at most 10^4 times
 * across all test cases.
 * Calls to ExamRoom.leave(p) are guaranteed to have a student currently
 * sitting in seat number p.
 * 
 * 
 */
#include<vector>
#include<set>
using namespace std;

// @lc code=start
// class ExamRoom {
// private:
//     int N; 
//     vector<int> seats;

// public:
//     ExamRoom(int n) {
//         N = n;
//     }
    
//     int seat() {
//         if (seats.size() == 0) {
//             seats.push_back(0);
//             return 0;
//         }

//         int dist = max(seats[0], N-1-seats.back());
//         for (int i = 0; i < seats.size()-1; ++i) 
//             dist = max(dist, (seats[i+1]-seats[i])/2);

//         if (seats[0] == dist) {
//             seats.insert(seats.begin(), 0);
//             return 0;
//         }
//         for (int i = 0; i < seats.size()-1; ++i)
//             if ((seats[i+1]-seats[i])/2 == dist) {
//                 seats.insert(seats.begin()+i+1, seats[i]+dist);
//                 return seats[i+1];
//             }
//         seats.push_back(N-1);
//         return N-1;
//     }
    
//     void leave(int p) {
//         for (int i = 0; i < seats.size(); ++i) 
//             if (seats[i] == p) 
//                 seats.erase(seats.begin()+i);
//     }
// };
class ExamRoom {
private:
    int n;
    set<int> seats;
    
public:
    ExamRoom(int N) {
        n = N;
    }
    
    int seat() {
        int last=0, dist=0, idx=0;
        for (int num: seats) {
            if (last==0) {
                if (dist<num-last) {
                    dist = num-last;
                    idx=0;
                }
            } 
            else {
                if (dist < (num-last+1)/2) {
                    dist = (num-last+1)/2;
                    idx = last + dist - 1;
                }
            }
            last = num + 1;
        }
        
        if (last>0 && dist<n-last) {
            dist = n-last;
            idx = n-1;
        }
        seats.insert(idx);
        return idx;
    }
    
    void leave(int p) {
        seats.erase(p);
    }
};
/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(N);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */
// @lc code=end

