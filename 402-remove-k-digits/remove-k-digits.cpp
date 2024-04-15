class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<int> q;
        for (char c : num){
            while (k && q.size() && q.back() > c ){
                k--;
                q.pop_back();

            }

            if (q.size() || c!= '0'){
                q.push_back(c);
            }

        }
        while (k && q.size()){
            k--;
            q.pop_back();
        }
        string s(q.begin(),q.end());
        if (s == ""){
            s = "0";
        }
        return s;
    }
};