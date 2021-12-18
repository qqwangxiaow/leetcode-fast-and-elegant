class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int ret = 0;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if (board[i][j] == 'X') {
                    ret++;
                    dfs(board, i, j);
                }
            }
        }
        return ret;
    }
    void dfs(vector<vector<char>>& board, int i, int j) {
        if (i >= board.size() || j >= board[i].size()) {
            return;
        }
        if (board[i][j] != 'X') {
            return;
        }
        board[i][j] = '.';
        dfs(board, i + 1, j);
        dfs(board, i, j + 1);
    }
};