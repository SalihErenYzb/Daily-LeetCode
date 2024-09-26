class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int k = click[0];
        int m = click[1];
        if (board[k][m] == 'M'){
            board[k][m] = 'X';
            return board;
        }
        vector<pair<int,int>> st;
        st.push_back({k,m});
        while (!st.empty()){
            k = st.back().first;
            m = st.back().second;
            st.pop_back();
            if (board[k][m] != 'E') continue;
            // change the char based on num of mines;
            int numOfMines = 0;
            for (int i =  max(0,k-1); i < min((int)board.size(),k+2); i++){
                for (int j = max(0,m-1); j < min((int)board[0].size(),m+2); j++){
                    if (board[i][j] == 'M'){
                        numOfMines++;
                    }
                }
            }
            if (!numOfMines){
                board[k][m] = 'B';
                for (int i =  max(0,k-1); i < min((int)board.size(),k+2); i++){
                    for (int j = max(0,m-1); j < min((int)board[0].size(),m+2); j++){
                        if (board[i][j] == 'E'){
                                st.push_back({i,j});
                        }
                    }
                }
            }else{
                board[k][m] = '0'+numOfMines;
            }
        }

        return board;
    }
};