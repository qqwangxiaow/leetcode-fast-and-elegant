//start from matrix[0][n]
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if(matrix.empty())
            return false;
        int row=0,col=matrix[0].size()-1;
        while(row<matrix.size()&&col>=0)
        {
            int temp=matrix[row][col];
            if(temp==target)
                return true;
            else if(temp>target)
                col--;
            else
                row++;
        }
        return false;
    }
};