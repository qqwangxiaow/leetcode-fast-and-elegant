class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        if(prices.size()<2)
            return 0;
        int dp0=0,dp1=INT_MIN;
        for(int i=0;i<prices.size();i++)
        {
            dp0=max(dp0,dp1+prices[i]);
            dp1=max(dp1,dp0-prices[i]-fee);
        }
        return dp0;
    }
};