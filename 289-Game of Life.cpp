//count 
//using bit to represent state
/*
状态: 前一位表示下一代的状态,后一位表示当前的状态
00: 死->死
10: 死->活
01: 活->死
11: 活->活
*/
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m=board.size(),n=board[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int count=0;
                for(int I=max(i-1,0);I<min(i+2,m);++I)
                {
                    for(int J=max(j-1,0);J<min(j+2,n);++J)
                    {
                        count+=board[I][J]&1;
                    }
                }
                if(count==3||count-board[i][j]==3) ////包括两种情况：1.本位为1，周围有2个；2.本位为0，周围有三个；3.本位为1，周围有三个；
                {
                    board[i][j]|=2;
                }
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                board[i][j]>>=1;
            }
        }
    }
};