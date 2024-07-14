class Solution {
public:
    string countOfAtoms(string formula) {
        formula += "()555";
        vector<int> counts(formula.size(),0);
        string tmpNum = "";
        vector<int> stc;
        int a = 0;
        int ds = 0;
        for (int i = 0; i < formula.size(); i++){
            if (formula.at(i) == '(') {
                stc.push_back(a++);
            }
            if (formula.at(i) == ')') {
                ds = stc[stc.size()-1];
                stc.pop_back();
            }
            if (formula.at(i) == ')' || tmpNum != ""){
                char tmp = formula.at(i+1)-'0';
                if (i == formula.size()-2 || tmp < 0 || tmp > 9){
                    if (i == formula.size()-2 && (tmp >= 0 || tmp <= 9)) tmpNum += tmp+'0';
                    if (tmpNum == "") tmpNum = "1";
                    counts[ds] = stoi(tmpNum);
                    tmpNum = "";
                }else{
                    tmpNum += tmp+'0';
                }
            }
        }
         tmpNum = "";
        vector<int> counts2;

        for (int i = 0; i < formula.size(); i++){
            if (formula.at(i) == ')' || tmpNum != ""){
                char tmp = formula.at(i+1)-'0';
                if (i == formula.size()-2 || tmp < 0 || tmp > 9){
                    if (i == formula.size()-2 && (tmp >= 0 || tmp <= 9)) tmpNum += tmp+'0';
                    if (tmpNum == "") tmpNum = "1";

                    counts2.push_back(stoi(tmpNum));
                    tmpNum = "";
                }else{
                    tmpNum += tmp+'0';
                }
            }
        }
        int j = 0;
        map<string,int> m;
        int multiplier = 1;
        int k = 0;
        int z = 0;
        while (j < formula.size()){
            char c = formula.at(j);
            if (c == '(') multiplier *= counts[k++];
            else if (c == ')') multiplier /= counts2[z++];
            j++;
            c -= 'A';
            if (c >= 0 && c <= 26){
                string s = "";
                s = c+'A';
                int count = 0;
                string cs = "0";
                while (j < formula.size() && (c = formula.at(j)-'a') >= 0 && c <= 26){
                    s += c+'a';
                    j++;
                }
                while (j < formula.size() && (c = formula.at(j)-'0') >= 0 && c <= 9){
                    cs += c+'0';
                    j++;
                }
                count = stoi(cs);
                if (count == 0) count++;
                count *= multiplier;

                //cout << multiplier << " ss\n";
                if (m.find(s) != m.end()) m[s] += count;
                else m[s] = count;
            }
        }
        string ans = "";
        for (auto [str,num]: m){
            //cout << num << "\n";
            ans += str;
            if (num != 1)
                ans += to_string(num);
        }
        return ans;
    }
};