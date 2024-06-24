class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int i = 0;
        int j = k-1;
        int flag = false;
        int ans = 0;
        while (j < nums.size()){
            nums[j++] ^= flag;
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