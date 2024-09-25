class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0; // represents the coord next 0 will get placed in
        int k = nums.size()-1;// represents the coord next 2 will get placed
        for (int j = 0; j <= k; j++){
            if (!nums[j]) {
                swap(nums[i++],nums[j]);
            }else if (nums[j] == 2){
                swap(nums[j--],nums[k--]);
            }
        }
    }
};