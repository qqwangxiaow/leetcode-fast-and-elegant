//dfs
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ret=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]=='1')
                {
                    ret++;
                    dfs(grid,i,j);
                }
            }
        }
        return ret;
        
    }
    void dfs(vector<vector<char>>&grid,int i,int j)
    {
        if(grid[i][j]=='1')
        {
            grid[i][j]='0';
        }
        else return;
        if(i>0)
            dfs(grid,i-1,j);
        if(j>0)
            dfs(grid,i,j-1);
        if(i<grid.size()-1)
            dfs(grid,i+1,j);
        if(j<grid[i].size()-1)
            dfs(grid,i,j+1);
    }
};