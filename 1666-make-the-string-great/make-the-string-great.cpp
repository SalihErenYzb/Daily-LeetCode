class Solution {
public:
    string makeGood(string s) {
        string st(s.size(),' ');
        int i = 0;
        for (char c: s){
            if (i && (c != st[i-1]) && (tolower(c) == tolower(st[i-1]))){
                i--;
                continue;
            }
            st[i] = c;
            i++;
        }
        st.resize(i);
        return st;
    }
};