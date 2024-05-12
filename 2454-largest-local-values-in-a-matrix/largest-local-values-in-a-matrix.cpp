class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        vector<vector<int>> ans;
        int n = grid.size();
        for (int i = 0; i < n-2; i++){
            vector<int> tmp;
            for (int j = 0; j < n-2; j++){
                int maxn = -1;
                for (int i1 = 0; i1 < 3; i1++)
                    for (int j1 = 0; j1 < 3; j1++)
                        maxn = max(maxn,grid[i1+i][j+j1]); 
                tmp.push_back(maxn);
            }
            ans.push_back(tmp);
        }
        return ans;
        
    }
};