class Solution {
public:
    string clearDigits(string s) {
        vector<char> tmpAns;
        vector<int> avail;
        string ans = "";
        char c;
        for (int i = 0; i < s.size(); i++){
            c = s[i];
            if (c >= 'a' && c <= 'z'){
                tmpAns.push_back(c);
                avail.push_back(tmpAns.size()-1);
            }else{
                tmpAns[avail.back()] = 'X';
                avail.pop_back();
            }
        }
        for (char c: tmpAns){
            if (c != 'X'){
                ans += c;
            }
        }
        return ans;
    }
};