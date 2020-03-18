//i start from 0
//dp[i-1][j] means duplicate 
class Solution {
public:
    bool isMatch(string s, string p) {
        int m=s.size(),n=p.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        dp[0][0]=1;
        for(int i=0;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(p[j-1]=='*')
                {
                    dp[i][j]=dp[i][j-2]||(i&&dp[i-1][j]&&(s[i-1]==p[j-2]||(p[j-2]=='.')));
                }
                else
                {
                    dp[i][j]=i&&(s[i-1]==p[j-1]||p[j-1]=='.')&&dp[i-1][j-1];
                }
            }
        }
        return dp[m][n];
    }
};
// one vector
class Solution {
public:
    bool isMatch(string s, string p) {
        int m=s.size(),n=p.size();
        vector<int>cur(n+1,0);
        int pre;
        for(int i=0;i<=m;i++)
        {
            pre=cur[0];
            cur[0]=!i;
            for(int j=1;j<=n;j++)
            {
                int temp=cur[j];
                if(p[j-1]=='*')
                {
                    cur[j]=cur[j-2]||(i&&cur[j]&&(s[i-1]==p[j-2]||(p[j-2]=='.')));
                }
                else
                {
                    cur[j]=i&&(s[i-1]==p[j-1]||p[j-1]=='.')&&pre;
                }
                pre=temp;
            }
        }
        return cur[n];
    }
};