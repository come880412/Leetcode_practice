class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();
        vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, 0)));
        dp[0][0][c - 1] = grid[0][0] + grid[0][c - 1];

        for (int i = 1; i < r; ++i) {
            for (int y1 = 0; y1 <= min(i, c - 1); ++y1) {
                for (int y2 = c - 1; y2 >= max(0, c - 1 - i); --y2) {
                    int currCherry = (y1 != y2) ? grid[i][y1] + grid[i][y2] : grid[i][y1];
                    for (int d1 = max(0, y1 - 1); d1 <= min(y1 + 1, c - 1); ++d1) {
                        for (int d2 = min(c - 1, y2 + 1); d2 >= max(0, y2 - 1); --d2) {
                            dp[i][y1][y2] = max(dp[i][y1][y2], currCherry + dp[i - 1][d1][d2]);
                        }
                    }
                }
            }
        }

        int result = 0;
        for (int y1 = 0; y1 < c; ++y1) {
            for (int y2 = 0; y2 < c; ++y2) {
                result = max(result, dp[r - 1][y1][y2]);
            }
        }
        return result;
    }
};