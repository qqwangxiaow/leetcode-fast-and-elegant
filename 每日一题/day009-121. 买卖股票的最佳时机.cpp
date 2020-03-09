class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<2)
            return  0;
        int minvalue=prices[0];
        int maxProfit=0;
        for(int i=1;i<prices.size();i++)
        {
            maxProfit=max(maxProfit,prices[i]-minvalue);
            minvalue=min(minvalue,prices[i]);
        }
        return maxProfit;
    }
};