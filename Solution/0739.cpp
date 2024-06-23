class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<pair<int,int>> s;
        vector<int> ans(n, 0);
        for (int i = 0; i < n; ++i) {
            int temp = temperatures[i];

            while (!s.empty()) {
                auto const &val = s.top();
                if (temp > val.second) ans[val.first] = i - val.first;
                else break;
                s.pop();
            }
            s.push({i, temp});
        }
        return ans;
    }
};