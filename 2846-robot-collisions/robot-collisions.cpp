class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<pair<int,int>> righters;
        vector<int> ans;
        vector<pair<int,int>> tmpForSort;
        for (int i = 0; i < positions.size(); i++)
            tmpForSort.push_back({positions[i],i});
        sort(begin(tmpForSort),end(tmpForSort));
        for (int j = 0; j < positions.size(); j++){
            int i = tmpForSort[j].second;
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