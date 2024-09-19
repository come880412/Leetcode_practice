class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        if (m_.find(expression) != m_.end()) return m_[expression];
        vector<int> ans;
        for (int i = 0; i < expression.size(); ++i) {
            char ope = expression[i];
            if (ope == '+' || ope == '-' || ope == '*') {
                string left = expression.substr(0, i);
                string right = expression.substr(i + 1);

                vector<int> leftSol = diffWaysToCompute(left);
                vector<int> rightSol = diffWaysToCompute(right);

                for (int a : leftSol) {
                    for (int b : rightSol) {
                        switch (ope) {
                            case '+' : ans.emplace_back(a + b); break;
                            case '-' : ans.emplace_back(a - b); break;
                            case '*' : ans.emplace_back(a * b); break;
                        }
                    }
                }
            }
        }
        
        if (ans.empty()) ans.emplace_back(stoi(expression));
        m_[expression] = ans;
        return m_[expression];
    }

private:
    unordered_map<string, vector<int>> m_;
};