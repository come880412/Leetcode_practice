class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        const int m = isWater.size(), n = isWater[0].size();
        vector<vector<int>> ans(m, vector<int>(n, -1));
        queue<pair<int, int>> q;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (isWater[i][j]) {
                    ans[i][j] = 0;
                    q.push(make_pair(i, j));
                }
            }
        }

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (auto [x, y] : dir_) {
                int next_r = r + x, next_c = c + y;
                if (next_r < 0 || next_r >= m || next_c < 0 || next_c >= n || ans[next_r][next_c] != -1)
                    continue;
                ans[next_r][next_c] = ans[r][c] + 1;
                q.push(make_pair(next_r, next_c));
            }
        }
        return ans;
    }

private:
    vector<pair<int, int>> dir_{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
};