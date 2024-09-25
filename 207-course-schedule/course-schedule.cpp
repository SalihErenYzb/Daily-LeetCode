class Solution {
public:
    vector<int> adj[2005];
    vector<int> vis;
    bool dfs(int node){
        vis[node] = 2;
        // visit every adjacent
        for(int neighbour: adj[node]){
            if (vis[neighbour] == 2){
                return true;
            }
            else if (!vis[neighbour] && dfs(neighbour)){
                return true;
            }
        }
        vis[node] = 1;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vis = vector<int>(numCourses+5,0);
        for (auto preq: prerequisites){
            adj[preq[0]].push_back(preq[1]);
        }
        for (int i = 0; i < numCourses; i++){
            if (!vis[i] && dfs(i)){
                return false;
            }
        }
        return true;
    }
};