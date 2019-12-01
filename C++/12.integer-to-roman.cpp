/*
 * @lc app=leetcode.cn id=12 lang=cpp
 *
 * [12] 整数转罗马数字
 */
#include<string>
#include<iostream>
#include<vector>

using namespace std;

// @lc code=start
class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int, string>> hash_map {{1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};

        string ans = "";
        for (auto item: hash_map) {
            while (num >= item.first) {
                num -= item.first;
                ans.append(item.second);
            }
        }
        return ans;
    }
};
// @lc code=end

int main(){
    Solution sol;
    int num = 4;
    string ans = sol.intToRoman(num);
    cout<<"ans="<<ans<<endl;
    return 0;
}
