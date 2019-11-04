//straight forward
class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int x,y,ret=0;
        for(int i=0;i<grid.size();i++)
        {
            x=0,y=0;
            for(int j=0;j<grid.size();j++)
            {
                x=max(x,grid[i][j]);
                y=max(y,grid[j][i]);
                if(grid[i][j])
                {
                    ++ret;
                }
            }
            ret+=x+y;
        }
        
        return ret;
    }
};