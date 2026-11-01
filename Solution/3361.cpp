class Solution {
public:
    long long shiftDistance(string s, string t, vector<int>& nextCost, vector<int>& previousCost) {
        int n = s.length();
        long long ans = 0;

        for (int i = 0; i < n; ++i) {
            int s_idx = s[i] - 'a', t_idx = t[i] - 'a';
            long long f_cost = 0, b_cost = 0;
            for (int j = 0; j < 26; ++j) {
                int curr_idx = (s_idx + j) % 26;
                if (curr_idx == t_idx) break;
                f_cost += nextCost[curr_idx];
            }
            for (int j = 0; j < 26; ++j) {
                int curr_idx = (s_idx - j + 26) % 26;
                if (curr_idx == t_idx) break;
                b_cost += previousCost[curr_idx];
            }
            ans += min(f_cost, b_cost);
        }
        return ans;
    }
};