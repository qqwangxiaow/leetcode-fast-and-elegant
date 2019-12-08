//pay attention to the last element, if <target row++,else col--;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()<=0)
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