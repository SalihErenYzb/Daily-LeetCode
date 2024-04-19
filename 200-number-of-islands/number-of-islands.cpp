class Solution {
public:
    bool isG(vector<vector<char>>& grid, int i, int j){
        if (i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() && grid[i][j] == '1')
            return true;
        return false;
    }
    void dfs(vector<vector<bool>>& vis, vector<vector<char>>& grid, int i, int j){
        vis[i][j] = true;
        vector<tuple<int,int>> tmp = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        for (auto [_i,_j]: tmp){
            int newI = i+_i;
            int newJ = j+_j;
            if (isG(grid,newI,newJ) && !vis[newI][newJ]){
                dfs(vis,grid,newI,newJ);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        
        int ans = 0;
        vector<vector<bool>> vis(grid.size(),vector<bool>(grid[0].size(),0));
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); j++){
                //cout << i << " " << j << " " << vis[i][j] << "\n";
                if(!vis[i][j] && grid[i][j] == '1'){
                    dfs(vis,grid,i,j);
                    ans++;
                }
                    
            }
        return ans;
    }
};