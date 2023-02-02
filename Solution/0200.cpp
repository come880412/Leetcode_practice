class Solution {
public:
    void dfs_alg(vector<vector<char>>& grid, int i, int j, int m, int n){
        
        if(i >= m || j >= n || j < 0 || i < 0 ||grid[i][j] == '0')
            return;
        
        else{
            grid[i][j] = '0';
            dfs_alg(grid, i-1, j, m, n);
            dfs_alg(grid, i+1, j, m, n);
            dfs_alg(grid, i, j-1, m, n);
            dfs_alg(grid, i, j+1, m ,n);
        }
        
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        int numIsland = 0;
        for(int i=0 ; i < m ; ++i){
            for(int j=0 ; j < n ; ++j){
                if(grid[i][j] == '1'){
                    numIsland += 1;
                    dfs_alg(grid, i, j, m, n);
                }
                
            }
        }
        
        return numIsland;
    }
};