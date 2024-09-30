class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        // sum = (n*(n+1))/2
        // actualSum= sum-missing+dupli - (1)
        // sumSq=(n(n+1)2n+1))/6
        // actualSumSq=sumSq - missingSq + dupliSq = k + (dupli-miss)(dupli+miss)
        // use 1 in above eqn
        // we get both a+b and a-b

        // xor method
        int xorr=0;
        for(int i=1;i<=n;i++){
            xorr^=(i^nums[i-1]);
        }
        // final result= a^b
        // sepearte the array in two parts
        int firstDiffBit=0;
        for(int i=0;i<32;i++){
            if((xorr&(1<<i))!=0){
                firstDiffBit=i;
                break;
            }
        }
        int xorr1=0,xorr2=0;
        for(int i=1;i<=n;i++){
            if((nums[i-1]&(1<<firstDiffBit))!=0){
                xorr1^=nums[i-1];
            }
            else{
                xorr2^=nums[i-1];
            }
            if((i&(1<<firstDiffBit))!=0){
                xorr1^=i;
            }
            else{
                xorr2^=i;
            }
        }
        for(auto num:nums){
            if(num==xorr1)return {xorr1,xorr2};
        }
        return {xorr2,xorr1};
    }
};