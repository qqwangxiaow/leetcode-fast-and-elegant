//using cache to store temp result
//using vector dirs to dfs easily
class Solution {
public:
    int dirs[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.size()==0||matrix[0].size()==0)
            return 0;
        int ret=0;
        int row=matrix.size(),col=matrix[0].size();
        vector<vector<int>>cache(row,vector<int>(col,0));
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                ret=max(ret,dfs(matrix,cache,i,j,row,col));
            }
        }
        return ret;
    }
    int dfs(vector<vector<int>>&matrix,vector<vector<int>>&cache,int i,int j,int row,int col)
    {
        if(cache[i][j]!=0)
            return cache[i][j];
        int t=0;
        for(int k=0;k<4;k++)
        {
            int newrow=i+dirs[k][0];
            int newcol=j+dirs[k][1];
            if(newrow>=0&&newrow<row&&newcol>=0&&newcol<col&&matrix[newrow][newcol]>matrix[i][j])
            {
                t=max(t,dfs(matrix,cache,newrow,newcol,row,col));
            }
        }
        cache[i][j]=1+t;
        return cache[i][j];
    }
};