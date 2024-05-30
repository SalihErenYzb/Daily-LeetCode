class Solution {
public:
    int countTriplets(vector<int>& arr) {
        unordered_map<int,pair<int,int>> prefix;
        int xor2 = 0;
        int ans = 0;
        prefix[0] = {1,0};
        for (int i = 0; i < arr.size(); i++){
            xor2 = xor2 ^ arr[i];
            if (prefix.find(xor2) != prefix.end()){
                ans += (i)*prefix[xor2].first - prefix[xor2].second;
                prefix[xor2] = {prefix[xor2].first+1,prefix[xor2].second+i+1};
            }else{
                prefix[xor2] = {1,i+1};
            }
        }
        return ans;
    }
};