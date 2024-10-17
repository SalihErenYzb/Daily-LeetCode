class Solution {
public:
    int jump(vector<int>& nums) {
        int canGo = 0;
        int ans = 0;
        int tmp;
        for (int i = 0; i < nums.size(); i++){
            if (canGo < i){
                ans++;
                canGo = tmp;
                tmp = 0;
            }
            tmp = max(tmp,i+nums[i]);
        }
        return ans;
    }
};