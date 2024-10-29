/*BFS solution
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
*/

// Dynamic programming (DP)
class Solution {
public:
    vector<pair<int, int>> dir{{-1, 1}, {0, 1}, {1, 1}};
    int maxMoves(vector<vector<int>>& grid) {
        const int m = grid.size();
        const int n = grid[0].size();
        int maxMove = 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for (int c = n - 2; c >= 0; --c) {
            for (int r = 0; r < m; ++r) {
                for (const auto& [dr, dc] : dir) {
                    int currR = r + dr, currC = c + dc;
                    if (currR < 0 || currC < 0 || currR >= m || currC >= n) continue;
                    if (grid[currR][currC] > grid[r][c])
                        dp[r][c] = max(dp[r][c], dp[currR][currC] + 1);
                }
            }
        }
        for (int r = 0; r < m; ++r) 
            maxMove = max(maxMove, dp[r][0]);
        return maxMove;
    }
};