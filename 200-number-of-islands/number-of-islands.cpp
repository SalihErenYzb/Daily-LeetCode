class Solution {
public:
    int answer = 0;
    void dfs(vector<vector<char>>& grid,int i, int j){
        vector<pair<int,int>> st;
        st.push_back({i,j});
        while (!st.empty()){
            auto curr = st.back();st.pop_back();
            int k = curr.first;
            int m = curr.second;
            if (grid[k][m] == '0') continue;
            grid[k][m] = 0;
            if (k > 0 && grid[k-1][m] == '1'){
                st.push_back({k-1,m});
            }
            if (m > 0 && grid[k][m-1] == '1'){
                st.push_back({k,m-1});
            }
            if (m < grid[0].size()-1 && grid[k][m+1] == '1'){
                st.push_back({k,m+1});
            }
            if (k < grid.size()-1 && grid[k+1][m] == '1'){
                st.push_back({k+1,m});
            }
        }
        answer++;
    }
    int numIslands(vector<vector<char>>& grid) {
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[0].size(); j++){
                if (grid[i][j] == '1'){
                    dfs(grid,i,j);
                }
            }
        }
        return answer;
    }
};