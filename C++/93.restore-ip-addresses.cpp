/*
 * @lc app=leetcode id=93 lang=cpp
 *
 * [93] Restore IP Addresses
 *
 * https://leetcode.com/problems/restore-ip-addresses/description/
 *
 * algorithms
 * Medium (33.03%)
 * Likes:    892
 * Dislikes: 386
 * Total Accepted:    162.4K
 * Total Submissions: 490K
 * Testcase Example:  '"25525511135"'
 *
 * Given a string containing only digits, restore it by returning all possible
 * valid IP address combinations.
 * 
 * Example:
 * 
 * 
 * Input: "25525511135"
 * Output: ["255.255.11.135", "255.255.111.35"]
 * 
 * 
 */
#include<string>
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        string path;
        DFS(s, 0, 0, path, res);
        return res;
    }
    void DFS(string s,int start,int step,string path,vector<string>& res){
        int s_size = s.size();
        if (start == s_size && step==4) {
            path.erase(path.end()-1);
            res.push_back(path);
            return;
        }
    
        if(s.size()-start > (4-step)*3) return;
        // if(s.size()-start < (4-step)) return;

        int num=0;
        for(int i=start; i<start+3; i++){
            num=num*10+(s[i]-'0');
            if(num<=255){
                path += s[i];
                DFS(s, i+1, step+1, path+'.', res);
            }
            if(num==0) break;
        }
    }
};
// @lc code=end

