class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_set<long long> s;
        int tmp = 0;
        bool flag = false;
        long long sum = 0;
        s.insert(0ll);
        for (int i = 0; i < nums.size(); i++){
            sum = (sum + nums[i])%k;
            s.insert(sum);
            //cout << sum << "\n";
            flag = nums[i]%k == 0 && !flag;
            if (flag)
                tmp++;
            if (s.size() < i+2-tmp)
                return true;
        }
        return false;
    }
};