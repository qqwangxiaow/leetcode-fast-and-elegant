//dp[i]=dp[i-1]+dp[i-2] iteritive version
class Solution {
public:
    int climbStairs(int n) {
        int cnt=1,cnt0=1,cnt1=1;
        for(int i=2;i<=n;i++)
        {
            cnt=cnt0+cnt1;
            cnt0=cnt1;
            cnt1=cnt;
        }
        return cnt;        
    }
};