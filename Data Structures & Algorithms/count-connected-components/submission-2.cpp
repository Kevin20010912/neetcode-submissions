class Solution {
private:
    int res = 0;
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<bool> visited(n, false);
        vector<vector<int>> adj(n);
        
        for(auto& edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                dfs(i, adj, visited);
                res++;
            }
        }
        return res;
    }
    void dfs(int i, vector<vector<int>>& adj, vector<bool>& visited){

        visited[i] = true;
        
        for(int candidate : adj[i]){
            if(visited[candidate]){
                continue;
            }
            
            dfs(candidate, adj, visited);
        }
        return;
    }
};
