//区间dp dp[i][j]表示i,j区间组成的最低
class Solution {
public:
    int minScoreTriangulation(vector<int>& A) {
        if(A.size()<=2)
            return 0;
        int n=A.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int len=3;len<=n;len++)
        {
            for(int left=0;left<=n-len;left++)
            {
                int right=left+len-1;
                dp[left][right]=INT_MAX;
                for(int i=left+1;i<right;i++)
                {
                    dp[left][right]=min(dp[left][right],dp[left][i]+dp[i][right]+A[i]*A[left]*A[right]);
                }
            }
        }
        return dp[0][n-1];
    }
};