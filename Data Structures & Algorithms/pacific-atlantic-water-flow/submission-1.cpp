class Solution {
    vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        for(int i = 0; i < m; i++){
            dfs(heights, pacific, i, 0);
        }
        for(int j = 0; j < n; j++){
            dfs(heights, pacific, 0, j);
        }
        for(int i = 0; i < m; i++){
            dfs(heights, atlantic, i, n - 1);
        }
        for(int j = 0; j < n; j++){
            dfs(heights, atlantic, m - 1, j);
        }

        vector<vector<int>> res;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(pacific[i][j] && atlantic[i][j]){
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, int x, int y){
        if(visited[x][y] == true){
            return ;
        }
        int m = heights.size();
        int n = heights[0].size();
        visited[x][y] = true;

        for(auto dir : dirs){
            int nx = dir.first + x;
            int ny = dir.second + y;

            if(nx < 0 || nx >= m || ny < 0 || ny >= n){
                continue;
            }
            if(heights[nx][ny] >= heights[x][y]){
                dfs(heights, visited, nx, ny);
            } 
                
        }
    }
};
