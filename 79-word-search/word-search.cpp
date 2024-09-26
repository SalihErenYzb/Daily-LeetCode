class Solution {
public:
    vector<vector<bool>> vis;
    bool dfs(vector<vector<char>>& board,string& word,pair<int,int> coord,int i){
        int k = coord.first;
        int m = coord.second;
        if (word[i] != board[k][m]) return false;
        if (i == word.size()-1) return true;
        vis[k][m] = true;
        if (k > 0 && !vis[k-1][m] && dfs(board,word,{k-1,m},i+1)) {
            vis[k][m] = false;
            return true;
        }
        if (m > 0 && !vis[k][m-1] && dfs(board,word,{k,m-1},i+1)) {
            vis[k][m] = false;
            return true;
        }
        if (k < board.size()-1 && !vis[k+1][m] && dfs(board,word,{k+1,m},i+1)) {
            vis[k][m] = false;
            return true;
        }
        if (m < board[0].size()-1 && !vis[k][m+1] && dfs(board,word,{k,m+1},i+1)){
            vis[k][m] = false;
            return true;
        }
        vis[k][m] = false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        vis = vector<vector<bool>>(board.size()+4,vector<bool>(board[0].size()+4,0));
        for (int i = 0; i < board.size(); i++){
            for (int j = 0; j < board[0].size(); j++){
                if (dfs(board,word,{i,j},0)) {
                    cout << i << j ;
                    return true;
                }
            }
        }
        return false;
    }

};