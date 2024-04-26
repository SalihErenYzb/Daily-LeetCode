class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int smallest = 0,ssmallest = 0;
        int n = grid.size();
        for (auto& row: grid){
            int ssm = 1e9,sm = 1e9;
            for (int i = 0; i < n; i++){
                grid[0][i] = grid[0][i] != smallest ? row[i] + smallest : row[i] + ssmallest;
                if (ssm > grid[0][i])
                    ssm = grid[0][i];
                if (sm > grid[0][i])
                    swap(sm,ssm);
            }
            smallest = sm,ssmallest = ssm;
        }
        return smallest;
    }
};