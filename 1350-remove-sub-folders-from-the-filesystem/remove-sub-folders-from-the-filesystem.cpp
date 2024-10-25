class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(begin(folder),end(folder));
        vector<string> ans;
        string last = "-1";
        for (string& s: folder){
            if (s.starts_with(last) && s.size() > last.size() && s[last.size()] == '/')             continue;
            last = s;
            ans.push_back(s);
        }
        return ans;
    }
};