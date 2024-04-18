class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans ;
        retAll(ans, vector<int>(), n,  k);
        return ans;
    }
    void retAll(vector<vector<int>>& ans, vector<int> subAns, int n, int k){
        if (k == 0){
            ans.push_back(subAns);
            return;
        }
        subAns.push_back(n);
        retAll(ans,subAns,--n,--k);
        subAns.pop_back();
        if (n != k)
            retAll(ans,subAns,n,++k);
    }
};