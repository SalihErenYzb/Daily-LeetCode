class Solution {
public:
    int longestIdealString(string s, int k) {
        int n = s.size();
        int dp[26] = {0};
        for (int i = 1; i <= n; i++){
            int c = s.at(i-1) - 'a';
            int maxi = *max_element(begin(dp)+max(0,c-k), begin(dp)+min(25,c+k)+1);
            dp[c] = ++maxi;
        }
        return *max_element(begin(dp),end(dp));
    }
};