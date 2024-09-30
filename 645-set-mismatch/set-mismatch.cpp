class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        int xorr = 0; // a^b
        for (int i = 0; i < n; i++){
            xorr ^= (i+1)^nums[i];
        }
        int firstD = 0;
        while ((xorr & 1<<firstD) == 0){
            firstD++;
        }
        int xor1 = 0;
        int xor2 = 0;
        for (int i = 0; i < n; i++){
            if ((i+1) & 1<<firstD){
                xor1 ^= i+1;
            }else{
                xor2 ^= i+1;
            }
            if (nums[i] & 1<<firstD){
                xor1 ^= nums[i];
            }else{
                xor2 ^= nums[i];
            }
        }
        for (int num: nums){
            if (num == xor2){
                return {xor2,xor1};
            }
        }
        return {xor1,xor2};
    }
};