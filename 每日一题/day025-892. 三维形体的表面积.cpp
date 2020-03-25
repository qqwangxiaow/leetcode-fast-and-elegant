class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int sum=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j])
                    sum+=grid[i][j]*4+2;
                if(i)
                    sum-=min(grid[i][j],grid[i-1][j])*2;
                if(j)
                    sum-=min(grid[i][j-1],grid[i][j])*2;
            }
        }
        return sum;
    }
};