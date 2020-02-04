//dp[i] means number of i
//dp[i]=min(dp[i-j*j]+1,dp[i]);
class Solution {
public:
    int numSquares(int n) {
        if(n<=0)
            return 0;
        vector<int>dp(n+1,INT_MAX);
        dp[0]=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j*j<=i;j++)
            {
                dp[i]=min(dp[i-j*j]+1,dp[i]);
            }
        }
        return dp.back();
    }
};

//using static vector is better
class Solution {
public:
    int numSquares(int n) 
    {
        if (n <= 0)
            return 0;
        static vector<int> cntPerfectSquares({0});
        while (cntPerfectSquares.size() <= n)
        {
            int m = cntPerfectSquares.size();
            int cntSquares = INT_MAX;
            for (int i = 1; i*i <= m; i++)
            {
                cntSquares = min(cntSquares, cntPerfectSquares[m - i*i] + 1);
            }
            cntPerfectSquares.push_back(cntSquares);
        }
        return cntPerfectSquares[n];
    }
};