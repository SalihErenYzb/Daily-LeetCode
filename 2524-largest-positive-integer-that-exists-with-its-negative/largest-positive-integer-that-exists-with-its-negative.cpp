class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int max1 = -1;
        vector<int> nums2(1005,0);
        for (int num: nums){
            if (nums2[abs(num)]){
                if (nums2[abs(num)] != num && abs(num) > max1)
                    max1 = abs(num);
                continue;
            }

            nums2[abs(num)] = num;
        }
        return max1;
    }
};