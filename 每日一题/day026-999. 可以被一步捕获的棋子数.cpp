class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int ret=0;
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]=='R')
                {
                    ret=dfs(board,i,j);
                }
            }
        }
        return ret;
    }
    int dfs(vector<vector<char>>&board,int i,int j)
    {
        int left=j-1,right=j+1,up=i-1,down=i+1;
        int ret=0;
        while(left>=0)
        {
            if(board[i][left]=='B')
                break;
            else if(board[i][left]=='p')
            {
                ret++;
                break;
            }
            left--;
        }
        while(right<board[0].size())
        {
            if(board[i][right]=='B')
                break;
            else if(board[i][right]=='p')
            {
                ret++;
                break;
            }
            right++;
        }
        while(up>=0)
        {
            if(board[up][j]=='B')
                break;
            else if(board[up][j]=='p')
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
            else if(board[down][j]=='p')
            {
                ret++;
                break;
            }
            down++;
        }
        return ret;

    }
    
};