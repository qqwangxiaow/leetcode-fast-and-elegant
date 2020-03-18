//start from (0,-1)
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ret;
        vector<vector<int>>direc{{0,1},{1,0},{0,-1},{-1,0}};
        if(matrix.empty())
            return ret;
        int m=matrix.size(),n=matrix[0].size();
        vector<vector<int>>visited(m,vector<int>(n,0));
        int start=0,end=m*n,d=0;
        int old_row=0,old_col=-1;
        while(start<end)
        {
            int row=old_row+direc[d][0];
            int col=old_col+direc[d][1];
            if(row>=0&&row<m&&col>=0&&col<n&&!visited[row][col])
            {
                ret.push_back(matrix[row][col]);
                visited[row][col]=1;
                start++;
                old_row=row;
                old_col=col;
            }
            else
            {
                d=(d+1)%4; 
            }
            
        }
        return ret;

    }
};