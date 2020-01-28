//真dp i表示天数 k表示交易次数 0表示没有持有股票 1表示持有股票
//dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i])
//dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i])
//k不用管,i用迭代的方法
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int dp_0=0,dp_1=INT_MIN;
        for(int i=0;i<prices.size();i++)
        {
            int temp=dp_0;
            dp_0=max(dp_0,dp_1+prices[i]);
            dp_1=max(dp_1,temp-prices[i]);
        }
        return dp_0;
    }
};
//其实很简单 累加每一段涨的曲线 因为没限制交易次数
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ret=0;
        if(prices.size()<2)
            return ret;
        for(int i=0;i<prices.size()-1;i++)
        {
            if(prices[i+1]>prices[i])
                ret+=prices[i+1]-prices[i];
        }
        return ret;
    }
};