//if(dp[i][j]=='*')
//dp[i][j]=dp[i][j-1]||(dp[i-1][j]);
class Solution {
public:
    bool isMatch(string s, string p) {
        int m=s.size(),n=p.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        for(int i=1;i<=n;i++)
        {
            if(p[i-1]=='*')
                dp[0][i]=1;
            else
                break;
        }
        dp[0][0]=1;
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(p[j-1]=='*')
                    dp[i][j]=dp[i][j-1]||(dp[i-1][j]);
                else
                    dp[i][j]=(s[i-1]==p[j-1]||p[j-1]=='?')?dp[i-1][j-1]:0;
            }
        }
        return dp[m][n];
        
    }
};