class Solution {
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        ios_base::sync_with_stdio(false);
        int n = chargeTimes.size();
        deque<int> maxes;
        int l = 0;
        long long sum = 0;
        for(int r = 0; r < n; r++) {
            while(!maxes.empty() && maxes.back() < chargeTimes[r]) {
                maxes.pop_back();
            }
            maxes.push_back(chargeTimes[r]);
            sum += runningCosts[r];
            if(maxes.front() + (r - l + 1) * sum > budget) {
                if(chargeTimes[l] == maxes.front())
                    maxes.pop_front();
                sum -= runningCosts[l++];
            }
        }
        return n-l;
    }
};