//dp[i][j]表示有i次操作,n个鸡蛋能测多少楼层
//鸡蛋碎了 dp[i][j]+=dp[i-1][j-1];
//鸡蛋没碎 dp[i][j]+=dp[i-1][j];
//加上当前楼层 表示能测的总楼层 大于N那就OK
class Solution {
public:
    int superEggDrop(int K, int N) {
        vector<int>dp(K+1,0);
        int m=0;
        while(dp[K]<N)
        {
            ++m;
            for(int j=K;j>0;--j)
            {
                dp[j]=dp[j]+dp[j-1]+1;
            }
        }
        return m;

    }
};