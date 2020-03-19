//string should be &
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.empty())
            return false;
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(helper(board,word,i,j,0))
                    return true;
            }
        }
        return false;
        
    }
    bool helper(vector<vector<char>>&board,string &word,int i,int j,int start)
    {
        if(start==word.size())
            return true;
        if(i<0||j<0||i>=board.size()||j>=board[0].size()||word[start]!=board[i][j])
            return false;
        board[i][j]='#';
        bool ret=helper(board,word,i+1,j,start+1)||helper(board,word,i-1,j,start+1)||helper(board,word,i,j-1,start+1)||helper(board,word,i,j+1,start+1);
        board[i][j]=word[start];
        return ret;
    }
};
