class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> dp(prices.size(),0);
        int minn = prices[0];
        for (int i = 1; i < prices.size(); i++){
            minn = min(minn,prices[i]);
            dp[i] = max(dp[i-1],prices[i]-minn);
        }
        int maxx = prices[prices.size()-1];
        int ans = 0;
        for (int i = prices.size()-2; i >= 0; i--){
            maxx = max(maxx,prices[i]);
            ans = max(ans,dp[i]+maxx-prices[i]);
        }
        return ans;
    }
};