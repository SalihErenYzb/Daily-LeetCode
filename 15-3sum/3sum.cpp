//Optimized Approach - O(n^2 logn + nlogn) - o(n^2 logn) time and O(n) space
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int target = 0;
        sort(nums.begin(), nums.end());
        vector<vector<int>> output;
        int last = INT_MAX;
        int last2;
        for (int i = 0; i < nums.size(); i++){
            if (last == nums[i]) continue;
            last = nums[i];
            int j = i + 1;
            int k = nums.size() - 1;
            last2 = INT_MAX;
            while (j < k) {
                if (nums[j] == last2){
                    j++;
                    continue;
                }
                last2 = nums[j];
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == target) {
                    output.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                } else if (sum < target) {
                    j++;
                } else {
                    k--;
                    last2 = INT_MAX;
                }
            }
        }
        return output;
    }
};