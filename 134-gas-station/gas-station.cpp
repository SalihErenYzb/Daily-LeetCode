class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = cost.size();
        for (int i = 0; i < n ; i++){
            if (gas[i] < cost[i]) continue;
            int k = 0, sum = 0;
            int j;
            for ( j = 0; j < n; ++j){
                k = (i+j)%n;
                sum +=  gas[k]-cost[k];
                if (sum<0){
                    if(k<i)
                        return -1;
                    else
                        i = k;
                    break;                }
            }
            if (j==n){
                return i;
            }
        }
        return -1;
    }
};