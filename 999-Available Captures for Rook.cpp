//serch and capture
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[i].size();j++)
            {
                if(board[i][j]=='R')
                {
                    return dfs(board,i,j);
                }
            }
        }
        return 0;
        
    }
    int dfs(vector<vector<char>>&board,int i,int j)
    {
        int ret=0;
        int l=j-1;
        int r=j+1;
        int up=i-1;
        int down=i+1;
        while(l>=0)
        {
            if(board[i][l]=='B')
                break;
            if(board[i][l]=='p')
            {
                ret++;
                break;
            }
            l--;
        }
        while(r<board[0].size())
        {
            if(board[i][r]=='B')
                break;
            if(board[i][r]=='p')
            {
                ret++;
                break;
            }
            r++;
        }
        while(up>=0)
        {
            if(board[up][j]=='B')
                break;
            if(board[up][j]=='p')
            {
                ret++;
                break;
            }
            up--;
        }
        while(down<board.size())
        {
            if(board[down][j]=='B')
                break;
            if(board[down][j]=='p')
            {
                ret++;
                break;
            }
            down++;
        }
        return ret;

    }
};