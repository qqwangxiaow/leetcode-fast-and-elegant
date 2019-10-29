//basic dp
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size()<1) return 0;
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,0));
        dp[0][0]=grid[0][0];
        for(int i=1;i<m;i++)
        {
            dp[i][0]=dp[i-1][0]+grid[i][0];
        }
        for(int i=1;i<grid[0].size();i++)
        {
            dp[0][i]+=dp[0][i-1]+grid[0][i];
        }
        for(int i=1;i<grid.size();i++)
        {
            for(int j=1;j<grid[0].size();j++)
            {
               
                dp[i][j]=min(dp[i-1][j],dp[i][j-1])+grid[i][j];
               
                
            }
        }
        return dp[(int)grid.size()-1][(int)grid[0].size()-1];
        
    }
};

//use two vector instead of two demention vector
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size()<1) return 0;
        int m=grid.size(),n=grid[0].size();
        vector<int>pre(m,0);
        vector<int>cur(m,0);
        pre[0]=grid[0][0];
        for(int i=1;i<m;i++)
        {
            pre[i]=pre[i-1]+grid[i][0];
        }
        for(int j=1;j<n;j++)
        {
            cur[0]=pre[0]+grid[0][j];
            for(int i=1;i<m;i++)
            {
                cur[i]=min(cur[i-1],pre[i])+grid[i][j];
                
            }
            swap(pre,cur);
        }
        return pre[m-1];
        
    }
};
//one vector
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size()<1) return 0;
        int m=grid.size(),n=grid[0].size();
        vector<int>cur(m,0);
        cur[0]=grid[0][0];
        for(int i=1;i<m;i++)
        {
            cur[i]=cur[i-1]+grid[i][0];
        }
        for(int j=1;j<n;j++)
        {
            cur[0]+=grid[0][j];
            for(int i=1;i<m;i++)
            {
                cur[i]=min(cur[i-1],cur[i])+grid[i][j];
                
            }
        }
        return cur[m-1];
        
    }
};