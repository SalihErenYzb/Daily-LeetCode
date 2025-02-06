class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int ans = 0;
        unordered_map<int,int> m;
        for (int i = 0; i < nums.size(); i++){
            for (int j = i+1; j < nums.size(); j++){
                m[nums[i]*nums[j]]++;
            }
        }
        int num;
        for (pair<int,int> p: m){
            num = p.second;
            if (num >= 2){
                ans += 4*num*(num-1);
            }
        }
        return ans;
    }
};