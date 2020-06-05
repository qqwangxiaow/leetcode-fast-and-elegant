//dp[i]表示为i时刻概率,等于sumpro/w
//sumpro表示i+1,...,i+w的概率
class Solution {
public:
    double new21Game(int N, int K, int W) {
        if(K-1+W<=N)
            return 1.0;
        vector<double>dp(K+W,0);
        for(int i=K;i<=N;i++)
        {
            dp[i]=1.0;
        }
        double sumpro=N-K+1;
        for(int i=K-1;i>=0;i--)
        {
            dp[i]=sumpro/W;
            sumpro-=dp[i+W];
            sumpro+=dp[i];
        }
        return dp[0];
    }
};