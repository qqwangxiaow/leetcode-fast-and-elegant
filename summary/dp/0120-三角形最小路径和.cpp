//从下到上
//triangle.back()是复制最后一行
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<int>dp(triangle.back());
        for(int i=n-2;i>=0;i--)
        {
            for(int j=0;j<triangle[i].size();j++)
            {
                dp[j]=min(dp[j+1],dp[j])+triangle[i][j];
            }
        }
        return dp[0];
    }
};