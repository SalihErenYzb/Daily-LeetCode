class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<char> q;
        if (k==q.size()) return "0";
        for (char c : num){
            while (k && !q.empty() && q.back() > c ){
                k--;
                q.pop_back();
            }
                q.push_back(c);
        }
        while (k--) q.pop_back();
        int j = 0,m = q.size();
        while (q[j] == '0' && j <m-1) j++;
        string s(q.begin()+j,q.end());
        return s==""? "0" : s;
    }
};