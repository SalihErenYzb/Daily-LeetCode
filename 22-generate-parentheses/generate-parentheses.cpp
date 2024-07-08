class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string a = "";
        int na = n;
        dfs(n,na,ans,a);
        return ans;
    }
    void dfs(int n,int na,vector<string>& ans,string a){
        if (2*n == a.length()){
            ans.push_back(a);
            return;
        }
        if (na){
            string tmpa = a+ "(";
            dfs(n,na-1,ans,tmpa);
        }
        if ((n-na)*2 > a.length() ){
            a += ")";
            dfs(n,na,ans,a);        
        }
    }
};