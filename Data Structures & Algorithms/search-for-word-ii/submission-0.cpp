class Solution {
    struct TrieNode {
        TrieNode* children[26] = {nullptr};
        string s = "";
    };
    TrieNode* head;
    vector<string> res;
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        head = new TrieNode();
        for(auto word : words){
            add(head, word);
        }
        int m = board.size(), n = board[0].size();

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int idx = board[i][j] - 'a';
                if(head->children[idx] != nullptr){
                    dfs(board, i, j, head);
                }
                
            }
        }
        return res;
        
        
    }
    void dfs(vector<vector<char>>& board, int x, int y, TrieNode* node){
        int m = board.size(), n = board[0].size();
        if(x < 0 || x >= m || y < 0 || y >= n){
            return;
        }
        char c = board[x][y];

        if(c == '#'){
            return;
        }

        int idx = c - 'a';
        
        if(node->children[idx] == nullptr){
            return;
        }
        node = node->children[idx];

        if(node->s != ""){
            res.push_back(node->s);
            node->s = "";
        }

        board[x][y] = '#';

        dfs(board, x + 1, y, node);
        dfs(board, x - 1, y, node);
        dfs(board, x, y + 1, node);
        dfs(board, x, y - 1, node);

        board[x][y] = c;
    }
    void add(TrieNode* head, string word){
        TrieNode* cur = head;
        for(char c : word){
            int idx = c - 'a';
            if(cur->children[idx] == nullptr){
                cur->children[idx] = new TrieNode();
            }
            cur = cur->children[idx];
        }
        cur->s = word;
    }
};
