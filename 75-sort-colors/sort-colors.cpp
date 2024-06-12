class Solution {
public:
    void sortColors(vector<int>& nums) {
        int j = 0;
        int k = nums.size()-1;
        int i = 0;
        while (i <= k){
            if (!nums[i]) {
                nums[i++] = 1;
                nums[j++] = 0;
            }
            else if (nums[i] == 1) i++;
            else {
                nums[i] = nums[k];
                nums[k--] = 2;
            }
        }
    }
};