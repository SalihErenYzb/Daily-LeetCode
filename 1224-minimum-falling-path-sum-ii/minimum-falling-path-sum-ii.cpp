class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int maxel = 0;
        int smaxel = 0;
        int maxI = -1;
        int smaxI = -1;
        int n = grid.size();
        vector<int> dp(n,0);
        for (auto row: grid){
            for (int i = 0; i < n; i++){
                dp[i] = row[i];
                if (maxI != i){
                    dp[i] += maxel;
                }else{
                    dp[i] += smaxel;
                }
            }
            maxel = 999999;
            smaxel = 999999;
            for (int i = 0; i < n; i++){
                if (maxel > dp[i]){
                    smaxel = maxel;
                    smaxI = maxI;
                    maxel = dp[i];
                    maxI = i;
                }else if (smaxel > dp[i]){
                    smaxel = dp[i];
                    smaxI = i;
                }
            }
        }
        return maxel;

        
    }
};