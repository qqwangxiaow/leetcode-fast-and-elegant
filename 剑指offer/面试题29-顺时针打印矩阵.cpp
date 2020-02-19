//count++ when push_back
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<vector<int>>dirs{{0,1},{1,0},{0,-1},{-1,0}};
        if(matrix.empty())
            return {};
        int row=matrix.size(),col=matrix[0].size();
        vector<vector<int>>visited(row,vector<int>(col,0));
        vector<int>ret;
        int x=0,y=0,count=0,d=0;
        while(count<row*col)
        {
            visited[x][y]=1;
            ret.push_back(matrix[x][y]);
            count++;
            int newx=x+dirs[d][0];
            int newy=y+dirs[d][1];
            if(newx<0||newy<0||newx>=row||newy>=col||visited[newx][newy])
            {
                d=(d+1)%4;
                x=x+dirs[d][0];
                y=y+dirs[d][1];
            }
            else
            {
                x=newx;
                y=newy;
            }   
        }
        return ret;
    }
};