class Solution {
public:
    bool isMagicSquare(const vector<vector<int>> &grid, int rStart, int cStart) {
        int sum = grid[rStart][cStart] + grid[rStart + 1][cStart] + grid[rStart + 2][cStart];
        unordered_set<int> s;
        for (int i = 0; i < 3; ++i) {
            int tmpCol = 0;
            int tmpRow = 0;
            for (int j = 0; j < 3; ++j) {
                s.insert(grid[rStart + i][cStart + j]); // Check duplicate
                if (grid[rStart + i][cStart + j] == 0 || grid[rStart + i][cStart + j] > 9) return false;
                tmpCol += grid[rStart][cStart + j];
                tmpRow += grid[rStart + j][cStart];
            }
            if (tmpCol != sum || tmpRow != sum) return false;
        }
        if (grid[rStart][cStart] + grid[rStart + 1][cStart + 1] + grid[rStart + 2][cStart + 2] != sum) return false;
        if (grid[rStart][cStart + 2] + grid[rStart + 1][cStart + 1] + grid[rStart + 2][cStart] != sum) return false;
        if (s.size() != 9) return false;
        
        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        if (row < 3 || col < 3) return 0;

        int result = 0;
        for (int i = 0; i <= row - 3; ++i) {
            for (int j = 0; j <= col - 3; ++j) {
                if (isMagicSquare(grid, i, j)) result++;
            }
        }
        return result;
    }
};