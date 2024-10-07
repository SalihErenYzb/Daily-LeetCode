class Solution {
public:
    int minLength(string s) {
        string a = "";
        for (int i = 0; i < s.size(); i++){
            if (!a.empty() && a.back() == 'A' && s[i] == 'B'){
                a.pop_back();
            }else if (!a.empty() && a.back() == 'C' && s[i] == 'D'){
                a.pop_back();
            }else{
                a += s[i];
            }
        }
        return a.size();
    }
};