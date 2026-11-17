class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<pair<int, int>> dirs({{0, 1}, {0, -1}, {1, 0}, {-1, 0}});
        queue<pair<int, int>> q;

        int fresh = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 2) q.push({i, j});
                else if (grid[i][j] == 1) fresh++;
            }
        }

        int mins = 0;
        while (!q.empty() && fresh > 0) {
            int q_len = q.size();
            for (int k = 0; k < q_len; ++k) {
                auto curr = q.front();
                q.pop();
                for (auto& dir : dirs) {
                    int i = curr.first + dir.first;
                    int j = curr.second + dir.second;
                    if (i < 0 || i >= m || j < 0 || j >= n) 
                        continue;
                    if (grid[i][j] == 1) {
                        q.push({i, j});
                        grid[i][j] = 2;
                        fresh--;
                    }
                }
            }
            mins++;
        }

        return fresh == 0 ? mins : -1;
    }
};