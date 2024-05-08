class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {

        vector<pair<int,int>> e;
        int n = score.size();
        for (int i = 0; i < n; i++){
            e.push_back({score[i],i});
        } 
        sort(rbegin(e),rend(e));
        vector<string> ans(n,"");
        for (int i = 0; i < n; i++){
            string f = to_string(i+1);
            if (i == 0)
                f = "Gold Medal";
            else if (i == 1)
                f = "Silver Medal";
            else if (i == 2)
                f = "Bronze Medal";
            ans[e[i].second] = f;
        }
        return ans;
    }
};