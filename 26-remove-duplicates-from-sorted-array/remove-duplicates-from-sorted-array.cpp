class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int old = -1e6;
        int j = 0;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] != old)
                nums[j++] = nums[i];
            old = nums[i];
        } 
        return j;
    }
};