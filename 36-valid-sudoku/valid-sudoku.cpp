class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> s1;
        unordered_set<char> s2;
        for (int i = 0; i < 9; i++){
            s1.clear();
            s2.clear();
            int dotCount1 = 0;
            int dotCount2 = 0;
            for (int j = 0; j < 9; j++){
                if (board[i][j] == '.') dotCount1++;
                else s1.insert(board[i][j]);

                if (board[j][i] == '.') dotCount2++;
                else s2.insert(board[j][i]);
            }
            if (s1.size()+dotCount1 != 9){
                return false;
            }
            if (s2.size() + dotCount2 != 9){
                return false;
            }
        }
        for (int i = 0; i < 9; i += 3){
            for (int j = 0; j < 9; j += 3){
                s1.clear();
                int dotCount = 0;
                for (int i2 = 0; i2 < 3; i2++){
                    for (int j2 = 0; j2 < 3; j2++){
                        if (board[i+i2][j+j2] == '.') dotCount++;
                        else s1.insert(board[i+i2][j+j2]);
                    }
                }
                if (dotCount + s1.size() != 9) return false;
            }
        }
        return true;
    }
};