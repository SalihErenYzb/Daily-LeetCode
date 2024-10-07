class Solution {
public:
    int minLength(string s) {
        string a = "^";
        for (char c: s){
            if (a.back() == 'A' && c == 'B' || a.back() == 'C' && c == 'D'){
                a.pop_back();
            }else{
                a += c;
            }
        }
        return a.size()-1;
    }
};