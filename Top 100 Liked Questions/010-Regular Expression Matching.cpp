/*dp[i][j]代表s[i-1]与p[j-1]匹配*/
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
/*精简版本 2 vector*/
class Solution {
public:
    bool isMatch(string s, string p) {
        int m=s.size(),n=p.size();
        vector<int>pre(n+1,0);
        vector<int>cur(n+1,0);
        cur[0]=1;
        for(int i=0;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(p[j-1]=='*')
                {
                    cur[j]=cur[j-2]||(i&&pre[j]&&(s[i-1]==p[j-2]||p[j-2]=='.'));
                }
                else 
                {
                    cur[j]=i&&pre[j-1]&&(s[i-1]==p[j-1]||p[j-1]=='.');
                }
            }
            fill(pre.begin(),pre.end(),0);
            swap(pre,cur);
        }
        return pre[n];
    }
};
/*最牛逼版本*/
class Solution {
public:
    bool isMatch(string s, string p) {
        int m=s.size(),n=p.size();
        vector<int>cur(n+1,0);
    
        for(int i=0;i<=m;i++)
        {
            int pre=cur[0];
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