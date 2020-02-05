//dp[0]=0 is key >=0
//foreach coins
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1,amount+1);
        dp[0]=0;
        for(int i=1;i<=amount;i++)
        {
            for(int start=0;start<coins.size();start++)
            {
                if(i-coins[start]>=0)
                    dp[i]=min(dp[i-coins[start]]+1,dp[i]);
            }
        }
        return dp[amount]>amount?-1:dp[amount];
    }
};