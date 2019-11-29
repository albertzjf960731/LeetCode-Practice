/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

#include<vector>
#include<string>
#include<queue>
#include<iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<string> letterCombinations(string digits) {
    //     vector<string> res;
    //     if(digits.empty()) return res;

    //     vector<string> letter = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    //     string path = "";
    //     DFS(digits, 0, path, res, letter);
    //     return res;  
    // }

    // void DFS(string digits, int index, string& path, vector<string>& res, vector<string>& letter) {
    //     if (index==digits.size()) {
    //         res.push_back(path);
    //         return;
    //     }
    //     for (auto ch: letter[digits[index]-'0']) {
    //         path.push_back(ch);
    //         DFS(digits, index+1, path, res, letter);
    //         path.pop_back();
    //     }

    
        vector<string> res;
        if (digits.empty()) return res;

        vector<string> letter = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        queue<string> q;
        q.push("");

        for (int i=0; i<digits.size(); i++) {
            while (q.front().size() == i) {
                string temp = q.front();
                q.pop();

                for (auto ch: letter[digits[i] - '0'])
                    q.push(temp+ch);
            }
        }

        while (!q.empty()) {
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
};
// @lc code=end

void printVector(vector<string>& ss){
    for(int i=0; i<ss.size(); i++){
        if (i>0) cout << ", "; 
        cout << ss[i];
    }
    cout << endl;
}

int main() {
    Solution sol;
    string digits = "23";
    vector<string> res = sol.letterCombinations(digits);
    printVector(res);
    return 0;
}