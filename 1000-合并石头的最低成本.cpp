//
class Solution {
public:
    int dp[31][31][31]; //dp[i][j][k] 把 i 到 j 合并成k堆的最小代价  初始化为无穷大
    int sum[31];  //前缀和数组 便于求代价
    int mergeStones(vector<int>& stones, int K) 
    {
        // 特判
        int n = stones.size();
        if ((n - 1) % (K - 1)) return -1;
        if(n < 2) return 0 ;
        // dp初始化 求前缀和
        memset(dp, 0x3f, sizeof(dp));
        for(int i = 1; i <= n; i ++)
        {
            sum[i] = sum[i - 1] + stones[i - 1];
            dp[i][i][1] = 0;  // 代价为0
            
        }
        // 枚举区间 惯用手法: 枚举区间长度 + 区间起点
        for (int len = 2; len <= n; len++)           
        {
            for (int i = 1; i <= n - len + 1; i++)  
            {
                int j = i + len - 1;                 
                
                for (int k = 2; k <= K; k++)      // 枚举连续堆数
                { 
                    for (int p = i; p < j; p ++ )   // 枚举分界点
                    {
                        dp[i][j][k] = min(dp[i][j][k], dp[i][p][k - 1] + dp[p + 1][j][1]);
                    }
                }
                
                dp[i][j][1] = min(dp[i][j][1], dp[i][j][K] + sum[j] - sum[i - 1]);//把K堆合并成一堆
            }
        }
        return dp[1][n][1]; //把1到n堆合并成1堆的最小代价
    }
};

