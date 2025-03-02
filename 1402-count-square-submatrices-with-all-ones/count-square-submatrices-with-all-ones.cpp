class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        vector<int> dp(matrix[0].size()+1,0);
        vector<int> dp2(matrix[0].size()+1,0);
        int ans = 0;
        for (int i = 1; i <= matrix.size(); i++){
            for (int j = 1; j <= matrix[0].size(); j++){
                dp2[j] = matrix[i-1][j-1]*(dp2[j-1]+1);
                if (dp2[j] > dp[j-1] + 1)
                    dp2[j] = dp[j-1] + 1;
                if (dp2[j] > dp[j] + 1)
                    dp2[j] = dp[j] + 1;
                ans += dp2[j];
            }
            swap(dp,dp2);
        }
        return ans;
    }
};