/*
 * @lc app=leetcode id=752 lang=cpp
 *
 * [752] Open the Lock
 */
#include<vector>
#include<string>
#include<queue>
#include<unordered_set>
using namespace std;

// @lc code=start
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> visited(deadends.begin(), deadends.end());
        if (visited.count("0000")) return -1;
        
        int ans = 0;
        
        visited.insert("0000");
        queue<string> q({"0000"});
        while (!q.empty()) {
            int q_size = q.size();
            while (q_size--) {
                string cur = q.front();
                q.pop();
                if (cur==target) return ans;
                
                for (int i=0; i<4; ++i) {
                    for (int j=-1; j<=1; ++j) {
                        if (j==0) continue;
                        string str = cur;
                        str[i] = (str[i]-'0' + 10 +j) % 10 + '0';
                        if (!visited.count(str)) {
                            q.push(str);
                            visited.insert(str);
                        }
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};
// @lc code=end

