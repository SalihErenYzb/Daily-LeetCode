class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        for (char c: s){
            if (!st.empty() && (c != st.top()) && (tolower(c) == tolower(st.top()))){
                st.pop();
                continue;
            }
            st.push(c);

        }
        string ans;
        while (!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};