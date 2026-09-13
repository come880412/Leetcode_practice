class Solution {
public:
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid, vector<int>& rowShift, vector<int>& colShift) {
        vector<vector<int>> result(n, vector<int>(n, 0));

        for (int i = 0; i < n; ++i) {
            int k = rowShift[i];
            for (int j = 0; j < n; ++j) {
                int newPos = (j - k + n) % n;
                result[i][newPos] = grid[i][j];
            }
        }

        grid = result;
        for (int i = 0; i < n; ++i) {
            int k = colShift[i];
            for (int j = 0; j < n; ++j) {
                int newPos = (j - k + n) % n;
                result[newPos][i] = grid[j][i];
            }
        }
        return result;
    }
};