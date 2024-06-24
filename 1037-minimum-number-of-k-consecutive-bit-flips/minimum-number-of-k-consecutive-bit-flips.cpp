class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int ans = 0;
        for (int i = 0,flag=0; i < nums.size();i++) { 
            (i + k <= nums.size()) && ((nums[i + k - 1] ^= flag) ^ (!(nums[i] ^ flag) && ++ans && (flag ^= 1)));
            if (!(nums[i] ^ flag)) return -1;
        }
        return ans;
    }
};
