//dp[i][k][0]=max(dp[i-1][k][0],dp[i-1][k][1]+prices[i]);
//dp[i][k][1]=max(dp[i-1][k][1],dp[i-2][k-1][0]-prices[i]);   i-2表示买对时候有冷冻期,dp_pre表示i-2
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int dp_0=0,dp_1=INT_MIN,dp_pre=0;
        for(int i=0;i<prices.size();i++)
        {
            int temp=dp_0;
            dp_0=max(dp_0,dp_1+prices[i]);
            dp_1=max(dp_1,dp_pre-prices[i]);
            dp_pre=temp;
        }
        return dp_0;
    }
};