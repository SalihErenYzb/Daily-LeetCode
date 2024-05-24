class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> counts(26,0);
        for (char c: letters)
            counts[c-'a'] += 1;
        return dfs(words,counts,score,0);
    }
    int dfs(vector<string>& words, vector<int>& counts, vector<int>& score,int i){
        if (i == words.size())
            return 0;
        // dont add the current word
        int maxO = dfs(words,counts,score,i+1);
        // add the current word
        int scoreW = 0;
        bool canSubstract = true;
        for (char c: words[i]){
            counts[c-'a'] -= 1;
            scoreW += score[c-'a'];
            if (counts[c-'a'] < 0)
                canSubstract = false;
        }
        if (canSubstract)
            maxO = max(maxO,dfs(words,counts,score,i+1)+scoreW);
        // substract the changes made to counts
        for (char c: words[i]){
            counts[c-'a'] += 1;
            scoreW += score[c-'a'];
        }
        // return the maximum of two aproaches
        return maxO;
    }
};