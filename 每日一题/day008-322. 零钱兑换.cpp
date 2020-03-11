//贪心+dfs 有点厉害 每次都用最大的填充满 然后回退
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0)
            return 0;
        sort(coins.rbegin(),coins.rend());
        int ret=INT_MAX;
        coinChange(coins,amount,0,0,ret);
        return ret==INT_MAX?-1:ret;
    }
    void coinChange(vector<int>&coins,int amount,int index,int count,int &ret)
    {
        if(amount==0)
        {
            ret=min(count,ret);
            return;
        }
        if(index==coins.size())
            return ;
        for(int k=amount/coins[index];k>=0&&k+count<ret;k--)
        {
            coinChange(coins,amount-k*coins[index],index+1,count+k,ret);
        }  
    }
};

