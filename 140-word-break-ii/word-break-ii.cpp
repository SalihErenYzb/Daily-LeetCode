class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> ans;
        unordered_set<string> wordDic(begin(wordDict),end(wordDict));
        dfs(s,wordDic,0,0,ans);
        return ans;
    }
    void dfs(string& s, unordered_set<string>& wordDict,int i,int j,vector<string>& ans){
        if (j == s.size())
            return;
        // just call j+1
        dfs(s,wordDict,i,j+1,ans);
        // check if the substring is actual word
        bool isW = wordDict.find(s.substr(i,j-i+1)) != wordDict.end();
        // if change s
        string old = s;
        if (isW){
            s = s.substr(0,j+1) + " " + s.substr(j+1,s.size()-j-1);
            //if it was the last j == s.size()-2 add it to ans 
            // else call i = j+2 , j=j+2
            if (j == s.size()-2)
                ans.push_back(s.substr(0,s.size()-1));
            else
                dfs(s,wordDict,j+2,j+2,ans);
            // fix the changes made to s 
            s = old;        
        }
    }
};