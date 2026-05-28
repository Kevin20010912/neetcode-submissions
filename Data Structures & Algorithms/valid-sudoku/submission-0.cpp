class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> row(m, vector<bool>(n, false));
        vector<vector<bool>> col(m, vector<bool>(n, false));
        vector<vector<bool>> box(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == '.'){
                    continue;
                }
                int num = board[i][j] - '1';
                int box_index = i / 3 * 3 + j / 3;
                if(row[i][num] || col[j][num] || box[box_index][num]){
                    return false;
                }
                row[i][num] = true; 
                col[j][num] = true; 
                box[box_index][num] = true; 

            }
        }
        return true;
    }
};
