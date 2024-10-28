class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int n = nums.size(), mx = 0;

        int dp[100001];
        memset(dp, 0, sizeof(dp));

        for(int i = 0; i < n; i++){
            dp[nums[i]] = 1;
            mx = max(mx, nums[i]);
        }

        int ans = -1;

        for(int i = 2; i <= mx; i++){
            if(dp[i] && i <= 46340 && i*i <= mx && dp[i*i]){
                dp[i*i] = dp[i]+1;
                ans = max(ans, dp[i*i]);
            }
        }
        return ans;
    }
};