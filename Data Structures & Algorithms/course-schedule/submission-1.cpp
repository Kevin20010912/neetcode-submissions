class Solution {
    vector<bool> onPath;
    vector<bool> visited;
    bool hasCycle = false;
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        onPath = vector<bool>(numCourses);
        visited = vector<bool>(numCourses);
        for(auto prerequisite : prerequisites){
            int from = prerequisite[1];
            int to = prerequisite[0];

            graph[from].push_back(to);
        }
        for(int i = 0; i < numCourses; i++){
            dfs(graph, i);
        }
        return !hasCycle;
    }
    void dfs(vector<vector<int>>& graph, int i){
        if(hasCycle){
            return ;
        }
        if(onPath[i]){
            hasCycle = true;
        }
        if(visited[i]){
            return ;
        }

        onPath[i] = true;
        visited[i] = true;

        for(auto next : graph[i]){
            dfs(graph, next);
        }
        onPath[i] = false;
    }
};
