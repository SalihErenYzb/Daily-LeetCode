class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> kc(k,0);
        for (int num: arr){
            kc[(num%k + k)%k]++;
        }
        for (int i = 1; i <= k/2; i++){
            if (kc[i] != kc[k-i]){
                return false;
            }
        }
        if (kc[0]%2){
            return false;
        }
        return true;
    }
};