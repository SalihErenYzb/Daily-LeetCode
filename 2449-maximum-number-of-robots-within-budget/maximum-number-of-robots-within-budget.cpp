class Solution {
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        vector<int> maxest; // hold maxes
        long long size = 0;
        long long sum = 0;
        int ans = 0;
        for (int i = 0; i < chargeTimes.size(); i++){
            size++;
            sum += runningCosts[i];
            // update maxesst
            while (!maxest.empty() && maxest.back() < chargeTimes[i]){
                maxest.pop_back();
            }
            maxest.push_back(chargeTimes[i]);

            // delete size if necessery
            while (sum*size + maxest[0] > budget && size > 0){
                size--;
                sum -= runningCosts[i-size];
                if (chargeTimes[i-size] == maxest[0]){
                    maxest.erase(maxest.begin());
                }
            }
            //for (int i: maxest){
            //    cout << i << " ";
            //}
            //cout << " sum: " << sum << "\n";
            // update ans
            if (maxest[0] + size*sum <= budget)
                ans = max(ans,(int)size);
        }
        return ans;
    }
};