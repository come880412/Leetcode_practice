class Solution {
public:
    struct pos {
        int r;
        int c;
    };

    pos instruct_to_dir(char dir) {
        if (dir == 'L') return {0, -1};
        else if (dir == 'R') return {0, 1};
        else if (dir == 'U') return {-1, 0};
        else return {1, 0};
    }

    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        visited[0][0] = true;
        pos currPos(0, 0);
        while (true) {
            int r = currPos.r, c = currPos.c;
            pos movingDir = instruct_to_dir(grid[r][c]);
            pos newPos(r + movingDir.r, c + movingDir.c);
            if (newPos.r < 0 || newPos.r >= m || newPos.c < 0 || newPos.c >=n || visited[newPos.r][newPos.c])
                break;
            else 
                visited[newPos.r][newPos.c] = true;
            currPos = newPos;
        }
        return {currPos.r, currPos.c};

    }
};