class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int> s(begin(nums),end(nums));
        int max1 = -1;
        for (int num: nums)
            if (s.find(-num) != s.end() && abs(num) > max1)
                max1 = abs(num);
        return max1;
    }
};