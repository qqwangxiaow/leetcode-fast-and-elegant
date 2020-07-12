//dp[i][j]表示i,j到终点最小所需 从末尾到头
//初始化 max
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        if(dungeon.empty())
            return 0;
        int m=dungeon.size(),n=dungeon[0].size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,INT_MAX));
        dp[m][n-1]=dp[m-1][n]=1;
        for(int i=m-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                dp[i][j]=max(min(dp[i][j+1],dp[i+1][j])-dungeon[i][j],1);
            }
        }
        return dp[0][0];
    }
};