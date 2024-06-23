class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int i = 0,j = 0;
        multiset<int> s;
        int ans = 0;
        while (j < nums.size()){
            if (s.empty() || *s.rbegin()-*s.begin() <= limit){
                ans = max(ans,j-i);
                s.insert(nums[j++]);
            }else
                s.erase(s.find(nums[i++]));

        }
        if (s.empty() || *s.rbegin()-*s.begin() <= limit)
            ans = max(ans,j-i);
        return ans;    
    }
};