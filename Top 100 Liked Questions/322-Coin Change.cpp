//dp[i]=min(dp[i],dp[i]-coins[j]+1) for each j
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1,amount+1);
        dp[0]=0;
        for(int len=1;len<=amount;len++)
        {
            for(int start=0;start<coins.size();start++)
            {
                if(coins[start]<=len)
                    dp[len]=min(dp[len],dp[len-coins[start]]+1);
            }
            
        }
        return dp[amount]>amount?-1:dp[amount];
    }
};