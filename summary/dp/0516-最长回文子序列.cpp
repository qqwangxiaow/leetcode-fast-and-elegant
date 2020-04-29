//dp[j][i]=max(dp[j+1][i],dp[j][i-1]);
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        if(s.empty())
            return 0;
        vector<vector<int>>dp(s.size(),vector<int>(s.size(),0));
        for(int i=0;i<s.size();i++)
        {
            dp[i][i]=1;
            for(int j=i-1;j>=0;j--)
            {
                if(s[j]==s[i])
                    dp[j][i]=dp[j+1][i-1]+2;
                else
                    dp[j][i]=max(dp[j+1][i],dp[j][i-1]);
            }
        }
        return dp[0][s.size()-1];  
    }
};