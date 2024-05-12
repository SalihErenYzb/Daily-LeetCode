class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        priority_queue<int> pq(begin(happiness),end(happiness));
        long long ans = 0;
        int i = 0;
        while (k--){
            int num = pq.top();
            pq.pop();
            ans += max(0,num-i++);
        } 
        return ans;
    }
};