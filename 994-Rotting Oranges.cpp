//BFS using d+2 as the rot orange
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh=0,d=0;
        for(int i=0;i<grid.size();i++)
        {
            fresh+=count_if(grid[i].begin(),grid[i].end(),[](int j){return j==1;});
        }
        for(auto old_fresh=fresh;fresh>0;d++)
        {
            for(int i=0;i<grid.size();i++)
            {
                for(int j=0;j<grid[i].size();j++)
                {
                    if(grid[i][j]==d+2)
                    {
                        fresh-=rot(grid,i-1,j,d)+rot(grid,i,j-1,d)+rot(grid,i+1,j,d)+rot(grid,i,j+1,d);
                    }
                }
            }
            if(fresh==exchange(old_fresh,fresh))
                return -1;
        }
        return d;
    }
    int rot(vector<vector<int>>&grid,int i,int j,int d)
    {
        if(i<0||j<0||i>=grid.size()||j>=grid[i].size()||grid[i][j]!=1)
            return 0;
        grid[i][j]=d+3;
        return 1;
    }
};