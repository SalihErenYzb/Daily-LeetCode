class Solution {
public:
    int longestIdealString(string s, int k) {
        int n = s.size();
        vector<int> dp(27,0);
        for (int i = 1; i <= n; i++){
            int c = s.at(i-1) - 'a' + 1;
            //7cout << s.at(i-1) << " " << c << "\n";
            int maxi = 0;
            for (int j = 1; j < 27; j++){
                int d = abs(c-j);
                if (k >= d)
                    maxi = max(maxi,dp[j] + 1);
            }
            dp[c] = maxi;
            //for (int j =1 ; j < 27; j++){
            //    cout << dp[i][j] << "\n";
            //}
        }
        int maxi = 0;
        for (int i = 1; i < 27; i++)
            maxi = max(dp[i],maxi);
        return maxi;
        
    }
};