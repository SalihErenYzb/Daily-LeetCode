class Solution {
public:
    vector<int> adj[20005];
    vector<int> vis;
    int dfs(int node, int depth){
        //cout << node << " " << depth << "\n";
        vis[node] = -1;
        int max = -1;
        int maxD = depth;
        for (auto edge: adj[node]){
            //cout << "from node: " << node << " to: " << edge << "\n";
            if (vis[edge] == -2){
                int d = dfs(edge,depth+1);
                if (d > maxD){
                    max = edge;
                    maxD = d;
                    vis[node] = max;
                }
            }
        }
        return maxD;
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        for (auto edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vis.resize(n,-2);
        int maxDepth = dfs(0, 0);
        int start = 0;
        while (vis[start] != -1){
            start = vis[start];
            //cout << "start: " << start << "\n"; 
        }
        for (int i = 0; i < vis.size(); i++){
            vis[i] = -2;
        }
        maxDepth = dfs(start,0);
        vector<int> ans;
        int i = 0;
        while (vis[start] != -1){
            //cout << "start: " << start << "\n";
            if (maxDepth/2 == i || (maxDepth+1)/2 == i){
                ans.push_back(start);
            }
            start = vis[start];
            i++;
        }
        if (maxDepth/2 == i || (maxDepth+1)/2 == i){
            ans.push_back(start);
        }
        return ans;
    }
};