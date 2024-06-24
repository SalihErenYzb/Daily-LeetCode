class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        dfs(ans,nums,curr);
        return ans;
    }
    void dfs(vector<vector<int>>& ans, vector<int>& nums, vector<int> curr){
        if (curr.size() == nums.size()){
            ans.push_back(curr);
            return;
        }
        for (int& i: nums){
            if (i <= 10){
                curr.push_back(i);
                i += 50;
                dfs(ans,nums,curr);
                curr.pop_back();
                i -= 50;
            }
        }
    }
};