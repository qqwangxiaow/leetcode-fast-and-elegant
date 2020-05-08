//coin在外面 表示必须要选这个coin
//那么每次多一个面值的硬币就是在原来几个之前硬币基础上在加上使用了这个硬币的情况
//为什么amount不在外面是要重复 2 2 1 和 2 1 2 是一种情况
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int>dp(amount+1,0);
        dp[0]=1;
        for(auto coin:coins)
        {
            for(int x=coin;x<=amount;x++)
            {
                dp[x]+=dp[x-coin];
            }
        }
        return dp[amount];
    }
};