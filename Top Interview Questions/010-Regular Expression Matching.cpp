//dp[i][j]=dp[i-1][j](i&&dp[i-1][j]&&(s[i-1]==p[j-2]||p[j-2]=='.'));
class Solution {
public:
    bool isMatch(string s, string p) {
        int m=s.size(),n=p.size();
        vector<vector<int>>dp(s.size()+1,vector<int>(p.size()+1,0));
        dp[0][0]=1;
        for(int i=0;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(p[j-1]=='*')
                    dp[i][j]=dp[i][j-2]||(i&&dp[i-1][j]&&(s[i-1]==p[j-2]||p[j-2]=='.'));
                else
                {
                    dp[i][j]=i&&dp[i-1][j-1]&&(s[i-1]==p[j-1]||p[j-1]=='.');
                }
            }
        }
        return dp[m][n];
        
    }
};