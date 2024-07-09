class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double ans = 0;
        int n = customers.size();
        int time = 0;
        for (int i = 0; i < n; i++){
            time = max(time,customers[i][0]);
            time += customers[i][1];
            ans += time - customers[i][0];
        }
        return ans / n;
    }
};