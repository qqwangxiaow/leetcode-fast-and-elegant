//dp[6]=dp[5]+dp[1] dp[1]+dp[5] 会重复
//所以从小到大就不会重复
class Solution {
public:
    int waysToChange(int n) {
        vector<int>dp(n+1,0);
        dp[0]=1;
        vector<int>coins{1,5,10,25};
        for(auto coin:coins)
        {
            for(int i=coin;i<=n;i++)
            {
                dp[i]=(dp[i]+dp[i-coin])%1000000007;
            }
        }
        return dp[n];
    }
};