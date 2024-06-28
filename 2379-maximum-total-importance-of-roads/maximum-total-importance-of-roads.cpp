class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> v(n,0);
        for (auto r: roads){
            v[r[0]]--;
            v[r[1]]--;
        }
        sort(begin(v),end(v));
        long long ans = 0;
        for (long long ve: v)
            ans -= ve*n--;
        return ans;
    }
};