//store min value
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<=1)
            return 0;
        int maxprofit=0;
        int minstock=prices[0];
        for(int i=1;i<prices.size();i++)
        {
            maxprofit=max(maxprofit,prices[i]-minstock);
            minstock=min(prices[i],minstock);
        }
        return maxprofit;
    }
};