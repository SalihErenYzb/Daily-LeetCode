class Solution {
public:
    int backtrack(string& s, vector<string>& vs, int i, int j){
        if (s.size() == j){
            if (i == j) return vs.size();
            return 0;
        }
        string tmp = s.substr(i,j-i+1);
        bool flag  = true;
        for (auto ss: vs){
            if (ss == tmp){
                flag = false;
                break;
            }
        }
        int ans = 0;
        if (flag){
            vs.push_back(tmp);
            ans = backtrack(s,vs,j+1,j+1);
            vs.pop_back();
        }
        ans = max(backtrack(s,vs,i,j+1),ans);
        return ans;
    }
    int maxUniqueSplit(string s) {
        vector<string> vs;
        return backtrack(s, vs, 0, 0);
    }
};