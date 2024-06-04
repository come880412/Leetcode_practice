class Solution {
public:
    bool isValidDistance(const int d, const vector<vector<int>> &distanceToThief, const vector<int> &dirR, const vector<int> &dirC) {
        int n = distanceToThief.size();
        pair<int, int> startPt = {0, 0};
        if (distanceToThief[startPt.first][startPt.second] - 1 < d) return false;

        queue<pair<int, int>> q;
        q.push(startPt);

        vector<vector<bool>> isVisited(n, vector<bool>(n, false));
        int r, c;
        while(!q.empty()) {
            r = q.front().first;
            c = q.front().second;

            // Expansion
            for (int m = 0; m < dirR.size(); ++m) {
                int tmpR = r + dirR[m];
                int tmpC = c + dirC[m];

                if (tmpR < 0 || tmpR >= n || tmpC < 0 || tmpC >= n) continue; // Out of boundary
                if (distanceToThief[tmpR][tmpC] - 1 < d || isVisited[tmpR][tmpC]) { // safeness factor should be higher or equal than d
                    continue;
                };
                if (tmpR == n - 1 && tmpC == n - 1) return true;
                isVisited[tmpR][tmpC] = true;
                q.push({tmpR, tmpC});
            }
            q.pop();
        }
        return false;
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        const int n = grid.size();
        
        // Find the position of the 1-index
        std::queue<pair<int, int>> traveler;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) traveler.push({i, j});                
            }
        }

        vector<vector<int>> distanceToThief(grid.begin(), grid.end());

        // BFS algorithm
        vector<int> dirR = {0, 0, 1, -1};
        vector<int> dirC = {1, -1, 0, 0};
        while(!traveler.empty()) {
            int r = traveler.front().first;
            int c = traveler.front().second;
            // Expansion
            for (int m = 0; m < dirR.size(); ++m) {
                int tmpR = r + dirR[m];
                int tmpC = c + dirC[m];

                if (tmpR < 0 || tmpR >= n || tmpC < 0 || tmpC >=n ) continue; // Out of boundary
                if (distanceToThief[tmpR][tmpC] != 0) continue; // Have been expanded
                distanceToThief[tmpR][tmpC] = distanceToThief[r][c] + 1;
                traveler.push({tmpR, tmpC});
            }
            traveler.pop();
        }

        // Binary Search for maximum safeness factor
        int l = 0, r = n + 1;
        int d;
        while (l < r) {
            d = r - (r - l) / 2;
            
            if (isValidDistance(d, distanceToThief, dirR, dirC)) {
                l = d;
            } else {
                r = d - 1;
            }
        }
        return l;
    }
};