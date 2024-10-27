class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        const int n = matrix.size();
        const int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        int ans = 0;

        for (int i = 0; i < n; ++i) {
            cout << matrix[i][0] << " ";
            dp[i][0] = matrix[i][0];
            ans += matrix[i][0];
        }
        for (int i = 1; i < m; ++i) {
            dp[0][i] = matrix[0][i];
            ans += matrix[0][i];
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                if (matrix[i][j]) 
                    dp[i][j] = 1 + min(min(dp[i-1][j-1], dp[i][j-1]), dp[i-1][j]);
                ans += dp[i][j];
            }
        }
        return ans;
    }
};