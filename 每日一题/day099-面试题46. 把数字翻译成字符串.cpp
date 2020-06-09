class Solution {
public:
    int translateNum(int num) {
        string s=to_string(num);
        int n=s.size();
        vector<int>dp(n+1,1);
        for(int i=2;i<=n;i++)
        {   
            if(s[i-2]=='1'||(s[i-2]=='2'&&s[i-1]<'6'))
                dp[i]=dp[i-1]+dp[i-2];
            else
                dp[i]=dp[i-1];
        }
        return dp[n];
    }
};