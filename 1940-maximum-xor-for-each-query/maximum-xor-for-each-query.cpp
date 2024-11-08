class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int xor2 = 0;
        for (int num: nums) xor2 ^= num;
        vector<int> ans;
        int num = (1<<maximumBit) - 1;
        int r = nums.size()-1;
        while (r >= 0){
            ans.push_back((xor2^num)%(num+1));
            xor2 ^= nums[r--];
        } 
        return ans;
    }
};