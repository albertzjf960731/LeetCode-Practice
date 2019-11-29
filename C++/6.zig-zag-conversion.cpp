/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 *  [6] ZigZag Conversion
 */


#include <string>
#include <iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows==1 or numRows>=s.size()) 
            return s;

        string temp[numRows];
        int row = 0, step = 1;

        for (int i=0; i<s.size(); i++) {
            temp[row].push_back(s[i]);

            if (row==0)
                step=1;
            else if (row==numRows-1) 
                step=-1;
            row += step;
        }

        // s.clear();
        string res = "";
        for (int i=0; i<numRows; i++) 
            res.append(temp[i]);
        return res;
    }
};
// @lc code=end

int main() {
    Solution sol;
    string s = "PAYPALISHIRING";
    int numRows = 3;
    cout << sol.convert(s, numRows) <<endl;
    return 0;
}