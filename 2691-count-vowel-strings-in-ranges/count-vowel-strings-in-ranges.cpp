class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<bool> wovels(30);
        vector<int> prefix(words.size()+1,0);
        vector<int> ans;
        wovels['a'-'a'] = 1;
        wovels['e'-'a'] = 1;
        wovels['i'-'a'] = 1;
        wovels['o'-'a'] = 1;
        wovels['u'-'a'] = 1;
        for (int i = 0; i < words.size(); i++){
            prefix[i+1] = prefix[i];
            if (!words[i].empty() && wovels[words[i][0] - 'a'] && wovels[words[i].back() - 'a']) {
                prefix[i + 1]++;
            }
        }
        for (auto q: queries){
            ans.push_back(prefix[q[1]+1] - prefix[q[0]]);
        }
        return ans;
    }
};