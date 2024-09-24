class Solution {
public:
    bool isValid(string s) {
        vector<char> v;
        for (char c: s){
            if (c == '(' || c == '{' || c == '['){
                v.push_back(c);
            }else{
                if (!v.size()) return false;
                else if (v[v.size()-1] == '(' && c != ')'){
                    return false;
                }else if (v[v.size()-1] == '[' && c != ']'){
                    return false;
                }else if (v[v.size()-1] == '{' && c != '}'){
                    return false;
                }
                v.pop_back();
            }
        }
        return v.size() == 0;
    }
};