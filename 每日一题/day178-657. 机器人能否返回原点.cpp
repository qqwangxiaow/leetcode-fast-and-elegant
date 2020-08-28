class Solution {
public:
    bool judgeCircle(string moves) {
        int row=0,col=0;
        for(int i=0;i<moves.size();i++)
        {
            if(moves[i]=='U')
            {
                col++;
            }
            else if(moves[i]=='D')
            {
                col--;
            }
            else if(moves[i]=='L')
            {
                row--;
            }
            else
            {
                row++;
            }
        }
        if(row==0&&col==0)
            return true;
        return false;
    }
};