class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<tuple<float,int,int>> ans;
        int n = arr.size();
        for (int i = 0; i < n; i++)
            for (int j = i+1; j < n; j++)
                ans.push_back({(float)arr[i]/arr[j],arr[i],arr[j]});
        sort(begin(ans),end(ans));
        k--;
        return vector<int>({get<1>(ans[k]),get<2>(ans[k])});
    }
};