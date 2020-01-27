//keep min price from left
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<2)
            return 0;
        int minleft=prices[0];
        int ret=0;
        for(int i=1;i<prices.size();i++)
        {
            ret=max(prices[i]-minleft,ret);
            minleft=min(prices[i],minleft);
        }
        return ret;
    }
};