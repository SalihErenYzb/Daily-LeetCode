class Solution {
public:
    string makeGood(string s) {
        string ans = "";
        int n = s.size();
        for(int i=0;i<n;i++){
            if(ans.size() > 0){
                char ch = ans.back();
                if(ch != s[i] and (toupper(ch) == s[i] || toupper(s[i]) == ch)){
                    ans.pop_back();
                }
                else{
                    ans += s[i];
                }
            }
            else{
                ans += s[i];
            }
        }
        return ans;
    }
};