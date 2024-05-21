class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> tmp;
        dfs(nums,ans,0,tmp);
        ans.push_back(vector<int>());
        return ans;
    }
    void dfs(vector<int>& nums, vector<vector<int>>& ans, int i,vector<int>& tmp){
        if (i == nums.size())
            return;
        dfs(nums,ans,i+1,tmp);
        tmp.push_back(nums[i]);
        ans.push_back(tmp);
        dfs(nums,ans,i+1,tmp);
        tmp.pop_back();
    }
};