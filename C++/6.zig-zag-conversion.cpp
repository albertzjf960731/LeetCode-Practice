/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 *  [6] ZigZag Conversion
 */


#include <string>
#include<vector>
#include <iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows==1) return s;
        
        vector<string> tmp(numRows);
        
        int row=0, d=1;
        for (int i=0; i<s.size(); i++) {
            tmp[row].push_back(s[i]);
            if(row==0) 
                d = 1;
            else if (row==numRows-1)
                d = -1;
            row += d;  
        }

        string res;
        for (int i=0; i<numRows; i++) 
            res.append(tmp[i]);
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