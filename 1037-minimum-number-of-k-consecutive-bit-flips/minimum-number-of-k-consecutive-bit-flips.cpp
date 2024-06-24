class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int i = 0;
        int flag = false;
        int ans = 0;
        while (i+k <= nums.size()){
            nums[i+k-1] ^= flag;
            if (!(nums[i++]^flag)){
                flag = flag^1;
                ans++;
            }
        }
        while (i < nums.size())
            if (!(nums[i++]^flag)) return -1;
        return ans;
    }
};