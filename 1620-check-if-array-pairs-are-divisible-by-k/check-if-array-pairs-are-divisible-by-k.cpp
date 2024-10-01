class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> kc(k,0);
        for (int num: arr){
            if (num < 0){

            }
            kc[(num%k + k)%k]++;
        }
        // k = 5
        // 0 1 2 3 4
        // k = 10
        // 0 1 2 3 4 5 6 7 8 9
        // 0 0 1 1 0 0 0 1 1 0
        for (int i = 1; i <= k/2; i++){
            if (kc[i] != kc[k-i]){
                return false;
            }
        }
        if (kc[0]%2 || (k%2 == 0 && kc[k/2]%2)){
            return false;
        }
        return true;
    }
};