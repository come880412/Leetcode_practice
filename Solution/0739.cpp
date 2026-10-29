class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        
        stack<int> s;
        vector<int> ans(n, 0);
        for (int i = 0; i < n; ++i) {
            int t = temperatures[i];
            while (!s.empty() && t > temperatures[s.top()]) {
                ans[s.top()] = i - s.top();
                s.pop();
            }
            s.push(i);
        }
        return ans;
    }
};