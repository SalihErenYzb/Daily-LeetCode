class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int max1 = 0;
        int ans = 0;
        int num;
        for (int i = 0; i < arr.size(); i++){
            num = arr[i];
            max1 = max(max1,num);
            if (max1 == i) ans++;
        }
        return ans;
    }
};