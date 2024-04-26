class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int smallestEl = 0;
        int ssmallest = 0;
        int n = grid.size();
        vector<int> dp(n,0);
        for (auto row: grid){
            int ssm = 999999;
            int sm = 999999;
            for (int i = 0; i < n; i++){
                dp[i] = dp[i] != smallestEl ? row[i] + smallestEl : row[i] + ssmallest;
                if (ssm > dp[i])
                    ssm = dp[i];
                if (sm > dp[i])
                    swap(sm,ssm);
            }
            smallestEl = sm;
            ssmallest = ssm;
        }
        return smallestEl;
    }
};