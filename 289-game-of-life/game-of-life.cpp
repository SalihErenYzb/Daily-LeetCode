class Solution {
public:
    int returnForOne(vector<vector<int>>& board, int i, int j){
        int live = 0;
        for (int i2 = max(0,i-1); i2 < min((int) board.size(),i+2); i2++){
             for (int j2 = max(0,j-1); j2 < min((int) board[0].size(),j+2); j2++){
                if (i2 != i || j2 != j){
                    live += board[i2][j2];
                }
             }
        }
        if (board[i][j] && (live == 2 || live == 3)) return 1;
        if (!board[i][j] && live == 3) return 1;
        return 0;
    }
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> board2(begin(board),end(board));
        for (int i = 0; i < board.size(); i++){
            for (int j = 0; j < board[0].size(); j++){
                board[i][j] = returnForOne(board2,i,j);
            }
        }
    }
};