class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(begin(nums),end(nums));
        unordered_map<int,int> m;
        int ans = -1;
        for (int& num: nums){
            if (num <= 46340){
                if (m.find(num) == m.end()){
                    m[num*num] = 1;
                }else{
                    m[num*num] = m[num]+1;
                    if (ans < m[num*num])
                        ans = m[num*num];
                }
            }else if (m.find(num) != m.end()){
                if (ans < m[num]+1)
                    ans = m[num]+1;
            }
        }
        return ans;
    }
};