class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ret;
        if(matrix.empty())
            return ret;
        int m=matrix.size(),n=matrix[0].size();
        vector<vector<int>>dirc{{0,1},{1,0},{0,-1},{-1,0}};
        vector<vector<int>>visited(m,vector<int>(n,0));
        int start=0;
        int row=0,col=-1;
        int d=0;
        while(start<m*n)
        {
            int newrow=row+dirc[d][0];
            int newcol=col+dirc[d][1];
            if(newrow>=0&&newrow<m&&newcol>=0&&newcol<n&&!visited[newrow][newcol])
            {
                ret.push_back(matrix[newrow][newcol]);
                visited[newrow][newcol]=1;
                row=newrow;
                col=newcol;
                start++;
            }
            else
            {
                d=(d+1)%4;
            }
        }
        return ret;

    }
};