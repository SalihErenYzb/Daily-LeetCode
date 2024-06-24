class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        sort(begin(nums),end(nums));
        dfs(ans,nums,curr);
        return ans;
    }
    void dfs(vector<vector<int>>& ans, vector<int>& nums, vector<int> curr){
        if (curr.size() == nums.size()){
            ans.push_back(curr);
            return;
        }
        int last = -15;
        for (int& i: nums){
            if (i <= 10 && last != i){
                last = i;
                curr.push_back(i);
                i += 50;
                dfs(ans,nums,curr);
                curr.pop_back();
                i -= 50;
            }
        }
    }
};