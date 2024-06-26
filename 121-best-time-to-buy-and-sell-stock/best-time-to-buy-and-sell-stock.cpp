class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minn = prices[0];
        int ans = 0;
        for (int& i: prices)
            ans = max(ans,i-(minn = min(minn,i)));
        return ans;
    }
};