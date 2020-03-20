class Solution {
    public:
        int maxAreaOfIsland(vector<vector<int>>& grid) {
            int ret=0,count=0;
            for(int i=0;i<grid.size();i++)
            {
                for(int j=0;j<grid[0].size();j++)
                {
                    if(grid[i][j]==1)
                    {
                        count=0;
                        dfs(grid,i,j,count);
                        ret=max(count,ret);
                    }
                }
            }
            return ret;

        }
        void dfs(vector<vector<int>>&grid,int i,int j,int &count)
        {
            if(i<0||j<0||i>=grid.size()||j>=grid[0].size()||grid[i][j]!=1)
                return;
            grid[i][j]=2;
            count++;
            dfs(grid,i-1,j,count);
            dfs(grid,i+1,j,count);
            dfs(grid,i,j-1,count);
            dfs(grid,i,j+1,count);
        }
    };