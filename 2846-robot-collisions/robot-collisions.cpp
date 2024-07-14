class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<pair<int,int>> righters;
        vector<int> ans;
        vector<int> indexes;
        for (int i = 0; i < positions.size(); i++) indexes.push_back(i);
        sort(begin(indexes),end(indexes),[&positions](int i,int j) -> int {
            return positions[i] < positions[j];
        });
        for (int i: indexes){
            if (directions.at(i) == 'R'){
                righters.push_back({i,healths[i]});
                continue;
            }
            while (healths[i]){
                if (!righters.size()){
                    ans.push_back(i);
                    break;
                }
                auto& fighter = righters[righters.size()-1];
                if (healths[i] > fighter.second){
                    righters.pop_back();
                    healths[i]--;
                }else if (healths[i] == fighter.second){
                    healths[i] = 0;
                    righters.pop_back();
                }else{
                    fighter.second--;
                    healths[i] = 0;
                }
            }
        }
        for (auto& num: righters){
            ans.push_back(num.first);
            healths[num.first] = num.second;
        }
        sort(begin(ans),end(ans));
        for (int& a: ans)
            a = healths[a];
        return ans;
    }
};