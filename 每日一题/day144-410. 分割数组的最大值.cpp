//dp[i][j] 表示前i个数分成j个子序列的最大值
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n=nums.size();
        vector<vector<long long>>dp(n+1,vector<long long>(m+1,LLONG_MAX));
        vector<long long>sub(n+1,0);
        for(int i=0;i<n;i++)
        {
            sub[i+1]=sub[i]+nums[i];
        }
        dp[0][0]=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=min(i,m);j++)
            {
                for(int k=0;k<i;k++)
                {
                    dp[i][j]=min(dp[i][j],max(dp[k][j-1],sub[i]-sub[k]));
                }

            }
        }
        return (int)dp[n][m];
    }
};