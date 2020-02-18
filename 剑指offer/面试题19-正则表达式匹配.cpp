//1.i应该从0开始 因为空与a*是匹配的
//2.i&&dp[i-1][j]代表有重复 要求s[i-1]==p[j-2]||p[j-2]=='.'
class Solution {
public:
    bool isMatch(string s, string p) {
        int m=s.size(),n=p.size();
        vector<vector<bool>>dp(m+1,vector<bool>(n+1,false));
        dp[0][0]=true;
        for(int i=0;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(p[j-1]=='*')
                {
                    dp[i][j]=dp[i][j-2]||(i&&dp[i-1][j]&&(s[i-1]==p[j-2]||p[j-2]=='.'));
                }
                else
                {
                    dp[i][j]=i&&dp[i-1][j-1]&&(s[i-1]==p[j-1]||p[j-1]=='.');
                }
            }
        }
        return dp[m][n];
    }
};
//pre=cur[0];
//cur=!i;
class Solution {
public:
    bool isMatch(string s, string p) {
        int m=s.size(),n=p.size();
        vector<bool>cur(n+1,0);
        int pre;
        for(int i=0;i<=m;i++)
        {
            if(i==1)
                pre=1;
            else
                pre=0;
            pre=cur[0];
            cur[0]=!i;
            for(int j=1;j<=n;j++)
            {
                int temp=cur[j];
                if(p[j-1]=='*')
                {
                    cur[j]=cur[j-2]||(i&&cur[j]&&(s[i-1]==p[j-2]||p[j-2]=='.'));
                }
                else
                {
                    cur[j]=i&&pre&&(s[i-1]==p[j-1]||p[j-1]=='.');
                }
                pre=temp;
            }
        }
        return cur[n];
    }
};