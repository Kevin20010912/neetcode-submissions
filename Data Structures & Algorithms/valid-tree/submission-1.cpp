class Solution {
private:
    int count = 0;
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n - 1){
            return false;
        }

        vector<vector<int>> adj(n);
        vector<bool> visited(n, false);

        for(auto& edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        traverse(0, adj, visited);

        for(int i = 0 ; i < n; i++){
            if(!visited[i]){
                return false;
            }
        }
        return true;
    }
    void traverse(int i, vector<vector<int>>& adj, vector<bool>& visited){
        if(visited[i]){
            return;
        }
        visited[i] = true;

        for(auto& node : adj[i]){
            traverse(node, adj, visited);
        }
    }
};
