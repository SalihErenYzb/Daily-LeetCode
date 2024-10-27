class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        vector<vector<int>> dp(matrix.size(),vector<int>(matrix[0].size(),0));
        int ans = 0;
        for (int i = 0; i < matrix.size(); i++){
            int continous = 0;
            for (int j = 0; j < matrix[0].size(); j++){
                if (matrix[i][j]){
                    continous++;
                    dp[i][j] = 1;
                    if (i > 0 && j > 0){
                        dp[i][j] = min(min(continous,dp[i-1][j-1]+1),dp[i-1][j]+1);
                    }
                }else{
                    continous = 0;
                }
                ans += dp[i][j];
            }
        }

        return ans;
    }
};