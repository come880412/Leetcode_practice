class Solution {
public:
    int minDays(int n) {
        vector<int> dp(n+1, INT_MAX);

        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            int L = 1;
            while (L * (L+1) / 2 <= i) {
                int val = (L * (L+1) / 2);
                int remaining = i - val;
                int candidate;
                if (remaining == 0) 
                    candidate =  L;
                else 
                    candidate = dp[remaining] + 1 + L;
                dp[i] = min(dp[i], candidate);
                ++L;
            }
        }
        return dp[n];
    }
};