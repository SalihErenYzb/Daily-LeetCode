class Solution {
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        ios_base::sync_with_stdio(false);
        deque<int> maxest;
        int size = 0;
        long long sum = 0;
        for (int i = 0; i < chargeTimes.size(); i++){
            size++;
            sum += runningCosts[i];
            while (!maxest.empty() && maxest.back() < chargeTimes[i]) maxest.pop_back();
            maxest.push_back(chargeTimes[i]);
            if (sum*size + maxest.front() > budget && size > 0){
                sum -= runningCosts[i- --size];
                if (chargeTimes[i-size] == maxest.front()) maxest.pop_front();
            }
        }
        return size;
    }
};