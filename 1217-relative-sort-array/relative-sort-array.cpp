class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int> value_map;
        for (int i = 0; i < arr2.size(); i++)
            value_map[arr2[i]] = i;
        auto comp = [&value_map](int a, int b) {
            auto foundA = value_map.find(a);
            auto foundB = value_map.find(b);
            if (foundA != value_map.end() && foundB != value_map.end()) {
                return foundA->second < foundB->second;
            } else if (foundA != value_map.end()) {
                return true;
            } else if (foundB != value_map.end()) {
                return false;
            } else {
                return a < b;
            }
        };
        sort(begin(arr1),end(arr1),comp);
        return arr1;
    }
};