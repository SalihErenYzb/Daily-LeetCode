class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        nums.push_back(nums.size()+10);
        int ans = 0;
        int sum = 0;
        for (int i = 0; i < nums.size()-1; i++){
            sum += abs(nums[i]);
            nums[abs(nums[i])] *= -1;
            if (nums[abs(nums[i])] > 0){
                ans = abs(nums[i]);
            }
        }
        int n = nums.size()-1;
        sum -= (n*(n+1))/2;
        for (int& num: nums)
            num = abs(num);
        return {ans,ans-sum};
    }
};