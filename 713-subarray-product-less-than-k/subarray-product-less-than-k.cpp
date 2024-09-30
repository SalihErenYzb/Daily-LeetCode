class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int product = 1;
        int ans = 0;
        int i = 0;
        for (int j = 0; j < nums.size(); j++){
            product *= nums[j];
            while (product >= k && j+1 > i){
                product = product / nums[i++];
            }
            ans += j-i+1;
        }
        return ans;
    }
};