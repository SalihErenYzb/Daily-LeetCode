class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> curr(30,0);
        vector<int> maxes(30,0);
        for (string str: words2){
            vector<int> curr(30,0);
            for (char c: str){
                curr[c-'a']++;
                if (maxes[c-'a'] < curr[c-'a']){
                    maxes[c-'a'] = curr[c-'a'];
                }
            }
        }
        vector<string> ans;
        for (auto word: words1){
            vector<int> curr(30,0);
            for (char c: word){
                curr[c-'a']++;
            }
            ans.push_back(word);
            for (int i = 0; i < 30; i++){
                if (maxes[i] > curr[i]){
                    ans.pop_back();
                    break;
                }
            }
        }
        return ans;
    }
};