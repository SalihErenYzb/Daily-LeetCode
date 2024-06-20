class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int ans = 0;
        vector<int> count(k,0);
        count[0] = 1;
        for (int i = 0,sum = 0; i < nums.size(); i++){
            sum += nums[i];
            sum = sum%k + k;
            ans += count[sum%k]++;}
        return ans;    
    }
};