// Good explanation: https://www.youtube.com/watch?v=STEJHYc9rMw
class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        const int m = points.size(), n = points[0].size();
        vector<vector<long long>> dp(m, vector<long long>(n, 0));
        for (int c = 0; c < n; ++c) dp[0][c] = (long long)points[0][c];

        vector<long long> left(n, 0);
        vector<long long> right(n, 0);
        for (int r = 1; r < m; ++r) {
            left[0] = dp[r - 1][0];
            right[n - 1] = dp[r - 1][n - 1];
            for (int c = 1; c < n; ++c) 
                left[c] = max(left[c - 1] - 1, dp[r - 1][c]);

            for (int c = n - 2; c >= 0; --c) 
                right[c] = max(right[c + 1] - 1, dp[r - 1][c]);

            for (int c = 0; c < n; ++ c)
                dp[r][c] = max(left[c], right[c]) + points[r][c];
        }

        long long maxPts = 0;
        for (int c = 0; c < n; ++c) maxPts = max(maxPts, dp[m - 1][c]);
        return maxPts;
    }
};