class Solution {
public:
    string removeOuterParentheses(string s) {
        string result = "";
        stack<int> stk;
        for (int i = 0; i < s.length(); ++i) {
            if (!stk.empty() && s[i] == ')') {
                if (stk.size() == 1) {
                    result += s.substr(stk.top()+1, i-stk.top()-1);
                }
                stk.pop();
            } else stk.push(i);
            
        }
        return result;
    }
};