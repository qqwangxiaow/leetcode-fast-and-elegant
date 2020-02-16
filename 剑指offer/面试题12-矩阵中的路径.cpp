//1.if(start==word.size()) return 
//2.board[i][j]!=word[start]
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(dfs(board,word,i,j,0))
                    return true;
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>&board,string &word,int i,int j,int start)
    {
        if(start==word.size())
            return true;
        if(i<0||j<0||i>=board.size()||j>=board[0].size()||board[i][j]!=word[start])
            return false;
        board[i][j]='*';
        bool ret=ret=dfs(board,word,i+1,j,start+1)||
            dfs(board,word,i-1,j,start+1)||
            dfs(board,word,i,j+1,start+1)||
            dfs(board,word,i,j-1,start+1);
        board[i][j]=word[start];
        return ret;
        
    }
};