//dp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int dp_0=0,dp_1=INT_MIN;
        for(int i=0;i<prices.size();i++)
        {
            dp_0=max(dp_0,dp_1+prices[i]);
            dp_1=max(dp_1,dp_0-prices[i]);
        }
        return dp_0;
        
    }
};