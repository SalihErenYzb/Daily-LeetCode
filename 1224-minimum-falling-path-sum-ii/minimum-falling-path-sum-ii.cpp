class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int smallestEl = 0;
        int ssmallest = 0;
        int smallI = -1;
        int n = grid.size();
        vector<int> dp(n,0);
        for (auto row: grid){
            for (int i = 0; i < n; i++){
                dp[i] = smallI != i ? row[i] + smallestEl : row[i] + ssmallest;
            }
            ssmallest = 999999;
            smallestEl = 999999;
            for (int i = 0; i < n; i++){
                if (smallestEl > dp[i]){
                    ssmallest = smallestEl;
                    smallestEl = dp[i];
                    smallI = i;
                }else if (ssmallest > dp[i]){
                    ssmallest = dp[i];
                }
            }
        }
        return smallestEl;

        
    }
};