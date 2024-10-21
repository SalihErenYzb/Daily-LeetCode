class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int,int> m;
        sort(begin(nums),end(nums));
        for (auto num: nums){
            m[num]++;
        }
        vector<vector<int>> ans;
        int last = INT_MAX;
        for (int i = 0; i < nums.size(); i++){
            m[nums[i]]--;
            if (nums[i] == last){
                continue;
            }
            last = nums[i];
            int last2 = INT_MAX;
            for (int j = i+1; j < nums.size(); j++){
                m[nums[j]]--;
                if (nums[j] == last2){
                    continue;
                }
                last2 = nums[j];
                if (m[-nums[i]-nums[j]] > 0){
                    ans.push_back({nums[i],nums[j],-nums[i]-nums[j]});
                }
            }
            for (int j = i+1; j < nums.size(); j++){
                m[nums[j]]++;
            }
        }
        return ans;
    }
};