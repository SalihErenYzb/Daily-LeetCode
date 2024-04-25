class Solution {
public:
    int longestIdealString(string s, int k) {
        int n = s.size();
        vector<int> dp(26,0);
        for (int i = 1; i <= n; i++){
            int c = s.at(i-1) - 'a';
            dp[c]++;
            for (int j = max(0,c-k); j <= min(25,c+k); j++){
                if (j != c)
                    dp[c] = max(dp[c],dp[j] + 1);
            }
        }
        int maxi = 0;
        for (int i = 0; i < 26; i++)
            maxi = max(dp[i],maxi);
        return maxi;
        
    }
};