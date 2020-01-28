//dp[i][k][0] 表示第i天剩余k次交易并没有持有股票第状态，dp[i][k][1]表示持有股票
//dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i]) +prices[i]表示售卖手中股票，那必须在持有状态dp[i-1][k][1]
//dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i]) 注意后面有个k-1，表示我们在买的时候记录交易次数
//详细记录每一个k，之前的公式没有对k做要求
/* dp[i][2][0]=max(dp[i-1][2][0],dp[i-1][2][1]+prices[i]);
        dp[i][2][1]=max(dp[i-1][2][1],dp[i-1][1][0]-prices[i]);

        dp[i][1][0]=max(dp[i-1][1][0],dp[i-1][1][1]+prices[i]);
        dp[i][1][1]=max(dp[i-1][1][1],-prices[i]);*/
//出始情况下,dp[-1][k][0]=0,dp[-1][k][1]=INT_MIN,INT_MIN表示根本不存在，因为没有买怎么会持有股票
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int dp_2_0=0,dp_2_1=INT_MIN,dp_1_0=0,dp_1_1=INT_MIN;
        for(int i=0;i<prices.size();i++)
        {
            dp_2_0=max(dp_2_0,dp_2_1+prices[i]);
            dp_2_1=max(dp_2_1,dp_1_0-prices[i]);
            dp_1_0=max(dp_1_0,dp_1_1+prices[i]);
            dp_1_1=max(dp_1_1,-prices[i]);
        }
        return dp_2_0;
    }
};