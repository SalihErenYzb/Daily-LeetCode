class Solution {
public:
    int longestIdealString(string s, int k) {
        int n = s.size();
        vector<int> dp(26,0);
        for (char ch: s){
            int c = ch - 'a';
            int maxi = 0;
            for (int j = max(0,c-k); j <= min(25,c+k); j++)
                maxi = max(maxi,dp[j]);
            dp[c] = maxi + 1; 
        }
        return *max_element(begin(dp),end(dp));
    }
};