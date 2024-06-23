class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        
        int minR = INT_MAX, minC = INT_MAX;
        int maxR = INT_MIN, maxC = INT_MIN;
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (grid[i][j]) {
                    if (j < minC) minC = j;
                    if (j > maxC) maxC = j;
                    if (i < minR) minR = i;
                    if (i > maxR) maxR = i;
                }
            }
        }
        return (maxR - minR + 1) * (maxC - minC + 1);
    }
};