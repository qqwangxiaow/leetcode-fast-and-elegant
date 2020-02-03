//why l<=r? it should be l<=r for binary search
//r=m*n-1 not m*n
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty())
            return false;
        int m=matrix.size(),n=matrix[0].size();
        int l=0,r=m*n-1;
        while(l<=r)
        {
            int m=l+(r-l)/2;
            int row=m/n;
            int col=m%n;
            if(matrix[row][col]==target)
                return true;
            else if(matrix[row][col]<target)
            {
                l=m+1;
            }
            else
                r=m-1;   
        }
        return false;
    }
};

//分割法
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty())
            return false;
        int m=matrix.size(),n=matrix[0].size();
        int row=0,col=n-1;
        while(row<m&&col>=0)
        {
            if(matrix[row][col]==target)
                return true;
            else if(matrix[row][col]<target)
                row++;
            else
                col--;
        }
        return false;
    }
};