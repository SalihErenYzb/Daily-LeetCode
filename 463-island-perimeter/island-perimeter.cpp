class Solution {
public:
    int returnLeng(vector<vector<int>>& grid, int i , int j){
        int ans = 4;
        if (i-1 >= 0 && grid[i-1][j])  
            ans--;
        if (i+1 < grid.size() && grid[i+1][j])
            ans--;
        if (j-1 >= 0 && grid[i][j-1])
            ans--;
        if (j+1 < grid[0].size() && grid[i][j+1])
            ans--;
        //cout << i << " " << j << " " << ans << "\n";
        return ans;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans = 0;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); j++)
                if (grid[i][j])
                    ans += returnLeng(grid,i,j);
        return ans;
        
    }
};