class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int ans = 0;
        long long sum = 0;
        for (int i = 0; i < nums.size(); i++){
            //cout << nums[i] << " " << sum << " " << i <<"\n";
            if (nums[i] > sum+1 && sum < n){
                ans++;
                sum += sum+1;
                i--;
            }else{
                sum += nums[i];
            }
        }
        while (sum < n){
            ans++;
            sum += sum+1;
        }
        return ans;
    }
};