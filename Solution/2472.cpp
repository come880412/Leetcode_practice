class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        vector<vector<bool>> isPalind(n, vector<bool>(n, true));
        for (int i = n-2; i >= 0; --i) {
            for (int j = n-1; j > i; --j) {
                if (!isPalind[i+1][j-1] || s[i] != s[j])
                    isPalind[i][j] = false;
            }
        }

        vector<int> dp(n+1, 0);
        for (int i = k; i <= n; ++i) {
            for (int j = i-k; j >= 0; --j) {
                if (isPalind[j][i-1]) {
                    dp[i] = dp[j] + 1;
                    break;
                }
            }
            dp[i] = max(dp[i], dp[i-1]);
        }
        return dp[n];
    }
};