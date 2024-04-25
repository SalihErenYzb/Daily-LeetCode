class Solution {
public:
    int longestIdealString(string s, int k) {
        int n = s.size();
        vector<int> dp(26,0);
        int maxAll = 0;
        for (int i = 1; i <= n; i++){
            int c = s.at(i-1) - 'a';
            int maxi = 0;
            for (int j = max(0,c-k); j <= min(25,c+k); j++)
                maxi = max(maxi,dp[j]);
            dp[c] = ++maxi;
            maxAll = max(maxAll,maxi); 
        }
        return maxAll;
    }
};