class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(begin(nums),end(nums));
        long long ans = 0;
        int num;
        for (int i = 0; i < nums.size(); i++){
            num = nums[i];
            auto en = upper_bound(begin(nums)+i+1,end(nums),upper-num);
            auto st = lower_bound(begin(nums)+i+1,end(nums),lower-num);
            ans += en-st;
        }
        return ans;
    }
};