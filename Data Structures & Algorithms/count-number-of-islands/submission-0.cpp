class Solution {
    vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        int m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1'){
                    traverse(grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }
    void traverse(vector<vector<char>>& grid, int i, int j){
        
        int m = grid.size(), n = grid[0].size(); 
        grid[i][j] = '0';
        for(auto dir : dirs){
            int nx = dir.first + i;
            int ny = dir.second + j;
            if(nx < 0 || nx >= m || ny < 0 || ny >= n){
                continue;
            }
            if(grid[nx][ny] == '0'){
                continue;
            }
            
            traverse(grid, nx, ny);
        }

    }
};
