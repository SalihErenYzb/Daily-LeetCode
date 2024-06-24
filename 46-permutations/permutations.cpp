class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        dfs(ans,nums,curr);
        return ans;
    }
    void dfs(vector<vector<int>>& ans, vector<int>& nums, vector<int> curr){
        bool end = true;
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] <= 10){
                curr.push_back(nums[i]);
                nums[i] += 50;
                dfs(ans,nums,curr);
                curr.pop_back();
                nums[i] -= 50;
                end = false;
            }
        if (end)
            ans.push_back(curr);
    }
};