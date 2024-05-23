class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        bool arr[2005] = {0};
        int ans = dfs(nums,k,0,arr);
        return ans;
    }
    int dfs(vector<int>& nums,int& k,int i,bool (&arr)[2005]){
        if (i == nums.size()){
            return 0;
        }
        int tmp = dfs(nums,k,i+1,arr);
        if (!arr[nums[i]]){
            bool oldVal = arr[nums[i]+k];
            bool oldVal2;
            arr[nums[i]+k] = true;
            if (nums[i]-k >= 0){
                oldVal2 = arr[nums[i]-k];
                arr[nums[i]-k] = true;
            }
            tmp += dfs(nums,k,i+1,arr) + 1;
            arr[nums[i]+k] = oldVal;
            if (nums[i]-k >= 0)
                arr[nums[i]-k] = oldVal2;        
        }
        return tmp;
    }
};