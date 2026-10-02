class Solution {
public:
    void backtrack(const int n, string current, int open, int close, vector<string>& result) {
        if (open == n and close == n)
            result.push_back(current);
        
        if (open < n) 
            backtrack(n, current + '(', open+1, close, result);
        
        if (close < open)
            backtrack(n, current + ')', open, close+1, result);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        int open = 0, close = 0;
        backtrack(n, "", open, close, result);
        return result;
    }
};