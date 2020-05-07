//区间dp 如果s[k]==s[end] 那么少一次
class Solution {
public:
    int strangePrinter(string s) {
        int n=s.size();
        if(n<2)
            return n;
        vector<vector<int>>dp(n,vector<int>(n,n+1));
        for(int i=0;i<n;i++)
        {
            dp[i][i]=1;
            if(i<n-1)
                dp[i][i+1]=s[i]==s[i+1]?1:2;
        }
            
        for(int len=2;len<=n;len++)
        {
            for(int left=0;left<=n-len;left++)
            {
                int right=left+len-1;
                dp[left][right]=len+1;
                for(int i=left;i<right;i++)
                {
                    int total = dp[left][i] + dp[i+1][right];
                    if(s[i]==s[right])
                        total--;
                    dp[left][right]=min(total,dp[left][right]);
                }
            }
        }
        return dp[0][n-1];
    }
};
//简化版
class Solution {
public:
    int strangePrinter(string s) {
        int n=s.size();
        if(n<2)
            return n;
        vector<vector<int>>dp(n,vector<int>(n,n));
        for(int i=0;i<n;i++)
            dp[i][i]=1;
        for(int end=0;end<n;end++)
        {
            for(int start=end;start>=0;start--)
            {
                for(int mid=start;mid<end;mid++)
                {
                    if(s[mid]==s[end])
                        dp[start][end]=min(dp[start][end],dp[start][mid]+dp[mid+1][end]-1);
                    else
                        dp[start][end]=min(dp[start][end],dp[start][mid]+dp[mid+1][end]);
                }
            }
        }
        return dp[0][n-1];


    }
};