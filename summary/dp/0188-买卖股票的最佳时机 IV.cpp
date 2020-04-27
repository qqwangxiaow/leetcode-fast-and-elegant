//dp1[j]=max(dp1[j],dp0[j+1]-prices[i]) not dp0[j-1]
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(prices.size()<2||k<1)
            return 0;
        int ret=0;
        if(k>=prices.size()/2)
        {
            for(int i=1;i<prices.size();i++)
            {
                if(prices[i]>prices[i-1])
                    ret+=prices[i]-prices[i-1];
            }
            return ret;
        }
        vector<int>dp0(k+1,0);
        vector<int>dp1(k+1,INT_MIN);
        for(int i=0;i<prices.size();i++)
        {
            for(int j=0;j<k;j++)
            {
                dp0[j]=max(dp0[j],dp1[j]+prices[i]);
                dp1[j]=max(dp1[j],dp0[j+1]-prices[i]);
            }
        }
        return dp0[0];

    }
};