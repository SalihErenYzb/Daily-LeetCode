class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int ans = 0;
        dfs(nums,0,ans,0);
        return ans;
    }
    void dfs(vector<int>& nums, int i, int& ans, int tmp){
        if (i == nums.size()) return;
        dfs(nums,i+1,ans,tmp);
        tmp = tmp ^ nums[i];
        ans += tmp;
        dfs(nums,i+1,ans,tmp);
    
    }
};