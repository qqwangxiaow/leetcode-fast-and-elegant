class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int dp_0=0,dp_1=INT_MIN;
        int pre=dp_0;
        for(int i=0;i<prices.size();i++)
        {
            int temp=dp_0;
            dp_0=max(dp_0,dp_1+prices[i]);
            dp_1=max(dp_1,pre-prices[i]);
            pre=temp;
        }
        return dp_0;

    }
};