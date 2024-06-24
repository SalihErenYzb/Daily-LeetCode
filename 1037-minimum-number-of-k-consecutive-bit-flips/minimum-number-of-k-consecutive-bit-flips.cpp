class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int ans = 0;
        for (int i = 0,flag=0; i < nums.size();i++)
            ((i + k <= nums.size()) && ((nums[i + k - 1] ^= flag) ^ (!(nums[i] ^ flag) && ++ans && (flag ^= 1)))) ^ ((!(nums[i] ^ flag)) && (ans = -1e6));
        return max(-1,ans);
    }
};
