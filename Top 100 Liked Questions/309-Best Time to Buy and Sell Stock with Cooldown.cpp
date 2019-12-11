/*
buyorcool[i]=max(buyorcool[i-1],cool[i-1]-prices[i]);
cool[i]=max(cool[i-1],sellorcool[i-1]);
sellorcool[i]=max(sellorcool[i-1],buyorcool[i-1]+prices[i]);
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<=1)
            return 0;
        vector<int>buyorcool(prices.size(),0);
        vector<int>sellorcool(prices.size(),0);
        vector<int>cool(prices.size(),0);
        buyorcool[0]=-prices[0];
        for(int i=1;i<prices.size();i++)
        {
            buyorcool[i]=max(buyorcool[i-1],cool[i-1]-prices[i]);
            cool[i]=max(cool[i-1],sellorcool[i-1]);
            sellorcool[i]=max(sellorcool[i-1],buyorcool[i-1]+prices[i]);
            
        }
        return max(sellorcool[prices.size()-1],cool[prices.size()-1]);
    }
};
class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int buy=INT_MIN,cool=0,sell=0;
        for(int i=0;i<prices.size();i++)
        {
            buy=max(buy,cool-prices[i]);
            cool=max(cool,sell);
            sell=max(sell,buy+prices[i]);
            
        }
        return max(sell,cool);
    }
};