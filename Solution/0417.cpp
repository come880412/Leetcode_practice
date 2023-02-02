class Solution {
public:
    void BFS(const string mode, const vector<vector<int>> matrix, vector<vector<bool>>& mapping){
        int m = matrix.size(), n = matrix[0].size();
        int dirX[4] = {0, 0, 1, -1};
        int dirY[4] = {1, -1, 0, 0};
        
        vector<vector<int>> queue;
        
        // Initialization
        if(mode == "pac"){
            for(int i=0 ; i<n ; ++i){
                mapping[0][i] = true;
                queue.push_back({0, i});
            }
            for(int i=0 ; i<m ; ++i){
                mapping[i][0] = true;
                queue.push_back({i, 0});
            }
        }
        else if(mode == "atl"){
            for(int i=0 ; i<n ; ++i){
                mapping[m-1][i] = true;
                queue.push_back({m-1, i});
            }
            for(int i=0 ; i<m ; ++i){
                mapping[i][n-1] = true;
                queue.push_back({i, n-1});
            }
        }
        
        // BFS algorithm
        
        int tmp_r, tmp_c, adj_r, adj_c;
        while(!queue.empty()){
            tmp_r = queue[0][0]; tmp_c = queue[0][1];
            queue.erase(queue.begin()); // Pop_front
            
            for(int k=0 ; k<4 ; ++k){
                adj_r = tmp_r + dirY[k];
                adj_c = tmp_c + dirX[k];
                if(adj_r < 0 || adj_c < 0 || adj_r >= m || adj_c >= n || mapping[adj_r][adj_c])
                    continue;
                if(matrix[adj_r][adj_c] >= matrix[tmp_r][tmp_c]){
                    mapping[adj_r][adj_c] = true;
                    queue.push_back({adj_r, adj_c});
                }
                    
            }
            
        }
        
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<bool>>Pac(m,vector<bool>(n,false)), Atl(m,vector<bool>(n,false));
        
        BFS("pac", heights, Pac);
        BFS("atl", heights, Atl);
        
        vector<vector<int>> result;
        for(int i=0 ; i<m ; ++i){
            for(int j=0 ; j<n ; ++j){
                if(Pac[i][j] && Atl[i][j])
                    result.push_back({i, j});
            }
        }
        
        return result;
    }
};
