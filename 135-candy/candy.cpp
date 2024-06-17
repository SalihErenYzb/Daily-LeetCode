class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> fl(n,0);
        int last = INT_MAX;
        for (int i = 0; i < n; i++){
            int el = ratings[i];
            if (el <= last){
                fl[i] = 1;
            }else if (el > last){
                fl[i] = fl[i-1] + 1;
            }
            last = el;
        }
        int sum = 0;
        last = INT_MAX;
        for (int i = n-1; i >= 0; i--){
            int el = ratings[i];
            if (el <= last){
                fl[i] = max(1,fl[i]);
            }else if (el > last){
                fl[i] = max(fl[i],fl[i+1] + 1);
            }
            last = el;
            sum += fl[i];
        }
        return sum;
    }
};