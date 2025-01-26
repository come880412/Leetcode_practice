class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        const int m = grid.size(), n = grid[0].size();
        vector<pair<int, int>> serverPos;
        vector<int> cnt(m+n, 0);

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]) {
                    serverPos.emplace_back(make_pair(i, j));
                    cnt[i]++;
                    cnt[m+j]++;
                }
            }
        }

        int ans = 0;
        for (auto pos : serverPos) {
            auto [i, j] = pos;
            if (cnt[i] > 1 || cnt[m+j] > 1)
                ans++;
        }
        return ans;
    }
};