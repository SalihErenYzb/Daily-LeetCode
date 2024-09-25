class Solution {
public:
    vector<string> answer;
    void dfs(string s, vector<int>& curr, int i){
        if (i == s.size()){
            if (curr.size() == 4){
                string tmp = to_string(curr[0]);
                for (int j = 1; j < 4; j++){
                    tmp += "." + to_string(curr[j]);
                }
                answer.push_back(tmp);
            }
            return;
        }
        // either add the current char to last byte or creater another byte
        if (curr.size() && curr.back() != 0){
            int tmp  = curr.back()*10 + (s[i]-'0');
            if (tmp <= 255){
                int last = curr.back();
                curr[curr.size()-1] = tmp;
                dfs(s,curr,i+1);
                curr[curr.size()-1] = last;
            }
        }
        // create another byte
        if (curr.size() != 4){
            curr.push_back(s[i]-'0');
            dfs(s,curr,i+1);
            curr.pop_back();
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<int> curr;
        dfs(s,curr,0);
        return answer;
    }
};