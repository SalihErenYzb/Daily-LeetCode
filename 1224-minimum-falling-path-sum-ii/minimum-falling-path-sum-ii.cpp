class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int smallestEl = 0;
        int ssmallest = 0;
        int n = grid.size();
        vector<int> dp(n,0);
        for (auto row: grid){
            for (int i = 0; i < n; i++){
                dp[i] = dp[i] != smallestEl ? row[i] + smallestEl : row[i] + ssmallest;
            }
            ssmallest = 999999;
            smallestEl = 999999;
            for (int i = 0; i < n; i++){
                if (ssmallest > dp[i])
                    ssmallest = dp[i];
                if (smallestEl > dp[i])
                    swap(smallestEl,ssmallest);
            }
        }
        return smallestEl;
    }
};