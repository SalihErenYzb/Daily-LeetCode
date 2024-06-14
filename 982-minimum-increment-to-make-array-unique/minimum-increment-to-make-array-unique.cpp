class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int ans = 0;
        int last = -1;
        sort(nums.begin(),nums.end());
        for (auto num: nums){
            cout << num << " " << last <<"\n";
            if (last >= num){
                ans += last-num+1;
                last++;
            }else{
                last = num;
            }
        }
        return ans;
    }
};