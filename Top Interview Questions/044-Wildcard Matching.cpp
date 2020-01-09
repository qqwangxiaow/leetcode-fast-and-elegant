//init dp[0][j]=1 until p[j-1]!='*'
//dp[i][j]=dp[i-1][j]||dp[i][j]
class Solution {
public:
    bool isMatch(string s, string p) {
        int m=s.size(),n=p.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        dp[0][0]=1;
        for(int j=1;j<=n;j++)
        {
            if(p[j-1]=='*')
                dp[0][j]=dp[0][j-1];
            else
                break;
        }
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(p[j-1]=='*')
                {
                    dp[i][j]=dp[i-1][j]||dp[i][j-1];
                }
                else
                {
                    dp[i][j]=dp[i-1][j-1]&&(s[i-1]==p[j-1]||p[j-1]=='?');
                }
            }
        }
        return dp[m][n];
    }
};
//dp[i-1][j-1]=pre
//temp=dp[i-1][j],then next iterator pre=dp[i-1][j]
//init pre=cur[0]
class Solution {
public:
    bool isMatch(string s, string p) { 
        int m = s.length(), n = p.length();
        vector<bool> cur(m + 1, false); 
        cur[0] = true;
        for (int j = 1; j <= n; j++) {
            bool pre = cur[0]; // use the value before update
            cur[0] = cur[0] && p[j - 1] == '*'; 
            for (int i = 1; i <= m; i++) {
                bool temp = cur[i]; // record the value before update
                if (p[j - 1] != '*')
                    cur[i] = pre && (s[i - 1] == p[j - 1] || p[j - 1] == '?');
                else cur[i] = cur[i - 1] || cur[i];
                pre = temp;
            }
        }
        return cur[m]; 
    }
};
//greedy
class Solution {
public:
    bool isMatch(string s, string p) { 
        int m=s.size(),n=p.size();
        int i=0,j=0,start_i=-1,start_j=-1;
        while(i<m)
        {
            if(j<n&&p[j]=='*')   //记录i,j的位置,如果之后无法匹配,回到这个位置重新开始,*匹配了0个字符
            {
                start_i=i;
                start_j=j;
                j++;        
            }
            else if(j<n&&(s[i]==p[j]||p[j]=='?')) //匹配了就计算下面的
            {
                i++;
                j++;
            }
            else if(start_j>-1)  // 那么没有匹配,所以如果有start_j那么代表有*号出现过,从之前记录的位置重新开始,i+1代表*每次多匹配一位s[i]
            {
                j=start_j;
                i=start_i+1;
            }
            else
                return false; //没匹配又没星 那么直接false
        }
        while(j<n&&p[j]=='*')  //没考虑p匹配到n的情况,只有后几位都是*才算能匹配
            j++;
        return j==n;
    }
};