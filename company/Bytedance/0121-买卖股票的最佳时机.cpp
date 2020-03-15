class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<2)
            return 0;
        int ret=0,minvalue=prices[0];
        for(int i=1;i<prices.size();i++)
        {
            minvalue=min(minvalue,prices[i]);
            ret=max(ret,prices[i]-minvalue);
        }
        return ret;
    }
};
//dp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<2)
            return 0;
        int dp_0=0,dp_1=INT_MIN;
        for(int i=0;i<prices.size();i++)
        {
            dp_0=max(dp_0,dp_1+prices[i]);
            dp_1=max(dp_1,-prices[i]);
        }
        return dp_0;
    }
};