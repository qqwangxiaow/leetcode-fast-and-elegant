//dp_pre!!!!!
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int dp0=0,dp1=INT_MIN;
        int dp_pre=0;
        for(int i=0;i<prices.size();i++)
        {
            int temp=dp0;
            dp0=max(dp0,dp1+prices[i]);
            dp1=max(dp1,dp_pre-prices[i]);
            dp_pre=temp;
        }
        return dp0;
    }
};