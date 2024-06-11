class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int> value_map;
        int n = arr2.size();
        for (int i = 0; i < arr2.size(); i++)
            value_map[arr2[i]] = i;
        sort(begin(arr1),end(arr1),[&value_map,n](int a, int b) {
            int rankA = value_map.count(a) ? value_map[a] : 1e5*n + a;
            int rankB = value_map.count(b) ? value_map[b] : 1e5*n + b;
            return rankA < rankB;
        });
        return arr1;
    }
};