class Solution {
public:
    void solve(vector<vector<char>>& board) {
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]=='O')
                {
                    if(dfs(board,i,j))
                        fill(board,i,j);
                }
            }
        }
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[i].size();j++)
            {
                if(board[i][j]=='#')
                    board[i][j]='O';
            }
        }
    }
    bool dfs(vector<vector<char>>&board,int i,int j)
    {
        if(i<0||j<0||i>=board.size()||j>=board[0].size())
            return false;
        if(board[i][j]=='X'||board[i][j]=='#')
            return true;
        if(board[i][j]=='O')
        {
            board[i][j]='#';
            int left=dfs(board,i,j-1);
            int up=dfs(board,i-1,j);
            int down=dfs(board,i+1,j);
            int right=dfs(board,i,j+1);
            return left&&up&&down&&right;
            
        }
        return false; 

    }
    void fill(vector<vector<char>>&board,int i,int j)
    {
        if(i<0||j<0||i>=board.size()||j>=board[0].size())
            return ;
        if(board[i][j]=='X')
            return;
        if(board[i][j]=='#')
        {
            board[i][j]='X';
            fill(board,i+1,j);
            fill(board,i-1,j);
            fill(board,i,j-1);
            fill(board,i,j+1);
        } 
    }
};