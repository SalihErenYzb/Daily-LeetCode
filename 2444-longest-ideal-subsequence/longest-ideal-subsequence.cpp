class Solution {
public:
    int longestIdealString(string s, int k) {
        int n = s.size();
        vector<vector<int>> dp(n+1,vector<int>(27,0));
        for (int i = 1; i <= n; i++){
            int c = s.at(i-1) - 'a' + 1;
            //7cout << s.at(i-1) << " " << c << "\n";
            for (int j = 1; j < 27; j++){
                int d = abs(c-j);
                dp[i][j] = max(dp[i-1][j],dp[i][j]);
                if (k >= d)
                    dp[i][c] = max(dp[i][c],dp[i-1][j] + 1);
            }
            //for (int j =1 ; j < 27; j++){
            //    cout << dp[i][j] << "\n";
            //}
        }
        int maxi = 0;
        for (int i = 1; i < 27; i++)
            maxi = max(dp[n][i],maxi);
        return maxi;
        
    }
};