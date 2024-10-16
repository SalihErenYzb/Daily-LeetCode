class Solution {
public:
    int maximumRobots(vector<int>& a, vector<int>& b, long long c) {
        ios_base::sync_with_stdio(false); deque<int> d; int e = 0; long long f = 0; 
        for (int g = 0; g < a.size(); g++) {
            f += b[g]; while (!d.empty() && d.back() < a[g]) d.pop_back(); 
            d.push_back(a[g]); if (f * ++e + d.front() > c && e > 0) {
                f -= b[g - --e]; if (a[g - e] == d.front()) d.pop_front();
            }
        }
        return e;
    }
};
