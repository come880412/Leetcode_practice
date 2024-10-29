class Solution {
public:
    vector<pair<int, int>> dir{{-1, 1}, {0, 1}, {1, 1}};
    int maxMoves(vector<vector<int>>& grid) {
        const int m = grid.size();
        const int n = grid[0].size();
        int maxMove = 0;

        for (int i = 0; i < m; ++i) {
            queue<pair<int, int>> q;
            vector<vector<bool>> visited(m, vector<bool>(n, false));

            int move = -1;
            q.push({i, 0});
            while (!q.empty()) {
                int currSize = q.size();
                for (int j = 0; j < currSize; ++j) {
                    auto [currR, currC] = q.front();
                    q.pop();

                    for (const auto& [dr, dc] : dir) { 
                        int nextR = currR + dr, nextC = currC + dc;
                        if (nextR >= 0 && nextC >= 0 && nextR < m && nextC < n && 
                        !visited[nextR][nextC] && grid[nextR][nextC] > grid[currR][currC]) {
                            visited[nextR][nextC] = true;
                            q.push({nextR, nextC});
                        }
                    }
                }
                move++;
            }
            maxMove = max(maxMove, move);
        }
        return maxMove;
    }
};
