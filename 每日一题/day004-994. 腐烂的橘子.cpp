//exchange(old_value,new_value) return old_value and old_value=value;
//rot orange shoud be d+2 ,we set d+3
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
                for(int j=0;j<grid[0].size();j++)
                {
                    if(grid[i][j]==d+2)
                    {
                        fresh-=rot(grid,i+1,j,d)+rot(grid,i,j+1,d)+rot(grid,i-1,j,d)+rot(grid,i,j-1,d);
                    }
                }
            }
            if(fresh==exchange(old_fresh,fresh))
        }
        return d;
    }
    int rot(vector<vector<int>>&grid,int i,int j,int d)
    {
        if(i<0||j<0||i>=grid.size()||j>=grid[0].size()||grid[i][j]!=1)
            return 0;
        grid[i][j]=d+3;
        return 1;
    }
};