class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> st; 
        vector<int> ans(prices.size(), 0);
        
        for (int i = prices.size() - 1; i >= 0; i--) {
            while (!st.empty() && st.back() > prices[i]) {
                st.pop_back();
            }
            
            ans[i] = prices[i] - (st.empty() ? 0 : st.back());
            st.push_back(prices[i]);
        }
        return ans;
    }
};
