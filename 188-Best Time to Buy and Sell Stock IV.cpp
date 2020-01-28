//k>prices.size()/2时代表k无限制，那么跟Best Time to Buy and Sell Stock II是一样的，直接调用贪心迭代解决
//不使用三维数组，在二维数组上迭代，最初dp为以下形式
//dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i]);
//dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i]); 一定要记得k-1这里,因为在买的时候标记,交易次数减少一次
//还有j从k到1，从大到小，否则会更新不及时
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        if(k<1||n<2)
            return 0;
        if(k>n/2)
        {
            int ret=0;
            for(int i=0;i<n-1;i++)
            {
                if(prices[i+1]>prices[i])
                    ret+=prices[i+1]-prices[i];
            }
            return ret;
        }
        vector<vector<int>>dp(k+1,vector<int>(2,0));
        for(int i=0;i<k+1;i++)
        {
            dp[i][1]=INT_MIN;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=k;j>=1;j--)
            {
                dp[j][0]=max(dp[j][0],dp[j][1]+prices[i]);
                dp[j][1]=max(dp[j][1],dp[j-1][0]-prices[i]);
            }
        }
        return dp[k][0];
    }
};