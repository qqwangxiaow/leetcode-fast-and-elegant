//row[i][num] save row valid,col,sub
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9][9]={0},col[9][9]={0},sub[9][9]={0};
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]!='.')
                {
                    int num=board[i][j]-'0'-1;
                    int k=i/3*3+j/3;
                    if(row[i][num]||col[j][num]||sub[k][num])
                        return false;
                    row[i][num]=col[j][num]=sub[k][num]=1;
                    
                }
            }
        }
        return true;
        
    }
};