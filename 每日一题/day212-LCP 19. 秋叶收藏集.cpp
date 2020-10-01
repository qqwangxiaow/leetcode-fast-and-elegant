//dp[i][j] 表示将0..i的leaves转换为正常所需的最小转换次数
//j=0 表示r 1 表示 y 2 表示r
//i必须>=j 所以dp[0][1] dp[0][2] dp[1][2] 不可能
//每个状态都与前面两个状态相关
class Solution {
public:
    int minimumOperations(string leaves) {
        int len=leaves.size();
        vector<vector<int>>dp(len,vector<int>(3));
        dp[0][0]=(leaves[0]=='y');
        dp[0][1]=dp[0][2]=dp[1][2]=INT_MAX;
        for(int i=1;i<len;i++)
        {
            int turntored=(leaves[i]=='y');
            int turntoyellow=(leaves[i]=='r');
            dp[i][0]=dp[i-1][0]+turntored;
            dp[i][1]=min(dp[i-1][0],dp[i-1][1])+turntoyellow;
            if(i>=2)
            {
                dp[i][2]=min(dp[i-1][1],dp[i-1][2])+turntored;
            }
        }
        return dp[len-1][2];
    }
};