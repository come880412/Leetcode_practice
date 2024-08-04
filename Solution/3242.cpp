class neighborSum {
public:
    vector<vector<int>> grid;
    unordered_map<int, pair<int, int>> map;
    
    neighborSum(vector<vector<int>>& grid) {
        this->grid = grid;
        
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                this->map[grid[i][j]] = {i, j};
            }
        }
    }
    
    int adjacentSum(int value) {
        auto idx = map[value];
        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        int sum = 0;
        for (auto const dir : dirs) {
            int i = idx.first - dir.first;
            int j = idx.second - dir.second;
            if (i < 0 || i >= this->grid.size() || j < 0 || j >= this->grid[0].size())
                continue;
            sum += this->grid[i][j];
        }
        return sum;
    }
    
    int diagonalSum(int value) {
        auto idx = map[value];
        vector<pair<int, int>> dirs = {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
        
        int sum = 0;
        for (auto const dir : dirs) {
            int i = idx.first - dir.first;
            int j = idx.second - dir.second;
            if (i < 0 || i >= this->grid.size() || j < 0 || j >= this->grid[0].size())
                continue;
            sum += this->grid[i][j];
        }
        return sum;
    }
};

/**
 * Your neighborSum object will be instantiated and called as such:
 * neighborSum* obj = new neighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */