//其实很简单 累加每一段涨的曲线 因为没限制交易次数
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ret=0;
        if(prices.size()<2)
            return ret;
        for(int i=0;i<prices.size()-1;i++)
        {
            if(prices[i+1]>prices[i])
                ret+=prices[i+1]-prices[i];
        }
        return ret;
    }
};