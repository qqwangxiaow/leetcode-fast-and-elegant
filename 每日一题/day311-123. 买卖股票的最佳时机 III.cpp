class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int dp_0_0 = 0,dp_0_1 = INT_MIN, dp_1_0 = 0, dp_1_1 = INT_MIN;
        for(int i = 0; i < prices.size(); ++i){
            dp_0_0 = max(dp_0_0, dp_0_1 + prices[i]);
            dp_0_1 = max(dp_0_1, dp_1_0 - prices[i]);
            dp_1_0 = max(dp_1_0, dp_1_1 + prices[i]);
            dp_1_1 = max(dp_1_1, -prices[i]);
        }
        return dp_0_0;
    }
};