// Implement a basic calculator to evaluate a simple expression string.

// The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .

// The expression string contains only non-negative integers, +, -, *, / operators , open ( and closing parentheses ) and empty spaces . The integer division should truncate toward zero.

// You may assume that the given expression is always valid. All intermediate results will be in the range of [-2147483648, 2147483647].

// Some examples:

// "1 + 1" = 2
// " 6-4 / 2 " = 4
// "2*(5+5*2)/3+(6/2+8)" = 21
// "(2+6* 3+5- (3*14/7+2)*5)+3"=-12
 

// Note: Do not use the eval built-in library function.


#include<vector>
#include<string>
using namespace std;

// @lc code=start
class Solution {
public:
    int calculate(string s) {
        int n = s.size(), num = 0, ans = 0;
        char op = '+';
        
        for (int i = 0; i < n; ++i) {
            char ch = s[i];
            if (ch >= '0' && ch <= '9') {
                num = num * 10 + (c - '0');
            } else if (c == '(') {
                int j = i, cnt = 0;
                for (; i < n; ++i) {
                    if (s[i] == '(') ++cnt;
                    if (s[i] == ')') --cnt;
                    if (cnt == 0) break;
                }
                num = calculate(s.substr(j + 1, i - j - 1));
            }

            if (ch=='+' || ch=='-' || ch=='*' || ch=='/' || i == n - 1) {
                if (op == '+') stack.push_back(num);
                if (op == '-') stack.push_back(-num);
                if (op == '*' || op == '/') {
                    int tmp = (op=='*') ? stack.back() * num : stack.back() / num;
                    stack.pop_back();
                    stack.push_back(tmp);
                }
                op = ch;
                num = 0;
            } 
        }
        
        int ans = 0;
        while (!stack.empty()) {
            ans += stack.back();
            stack.pop_back();
        }
        return ans;
    }
};
// @lc code=end

