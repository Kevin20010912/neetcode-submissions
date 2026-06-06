class Solution {
    bool flag = false;
    vector<vector<bool>> visited;
    vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        int count = 0;
        visited = vector<vector<bool>>(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(word[count] == board[i][j])
                    backtrack(board, word, count, i, j);
            }       
        }
        if(flag){
            return true;
        }
        return false;
    }
    void backtrack(vector<vector<char>>& board, string& word, int& count, int x, int y){
        int m = board.size(), n = board[0].size();
        if(flag){
            return;
        }
        if(visited[x][y]){
            return;
        }
        if(word[count] == board[x][y]){
            if(count == word.size() - 1){
                flag = true;
                return;
            }
            visited[x][y] = true;
            for(auto dir : dirs){
                int nx = x + dir.first;
                int ny = y + dir.second;
                if(nx < 0 || nx >= m || ny < 0 || ny >= n){
                    continue;
                }
                count++;
                backtrack(board, word, count, nx, ny);
                count--;
            }
            visited[x][y] = false;
        }
    }
    
};
