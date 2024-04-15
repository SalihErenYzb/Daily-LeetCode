class Solution {
public:
    string makeGood(string s) {
        string st = "";
        for (char c: s){
            if (st != "" && (c != st.back()) && (tolower(c) == tolower(st.back()))){
                st.pop_back();
                continue;
            }
            st += c;
        }
        return st;
    }
};