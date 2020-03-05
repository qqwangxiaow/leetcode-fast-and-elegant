//dp[i][j] 代表第i轮 sum为j的分子
//i从第1轮到第n轮
//j从和为2到和为6*i
//dp[i][j]=dp[i-1][j-1]+dp[i-1][j-2]...dp[i-1][j-6] 如果j<1那么break
class Solution {
public:
    vector<double> twoSum(int n) {
        vector<vector<int>>dp(15,vector<int>(70,0));
        for(int j=1;j<=6;j++)
        {
            dp[1][j]=1;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=2;j<=6*i;j++)
            {
                for(int cur=1;cur<=6;cur++)
                {
                    if(j-cur<1)
                        break;
                    dp[i][j]+=dp[i-1][j-cur];
                }
            }
        }
        int all=pow(6,n);
        vector<double>ret;
        for(int i=n;i<=6*n;++i)
        {
            ret.push_back(dp[n][i]*1.0/all);
        }
        return ret;

    }
};