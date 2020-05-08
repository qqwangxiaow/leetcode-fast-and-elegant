//dp[i][j]表示能i个0,j个1能组成的最大字符个数
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int ones=0,zeros=0;
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        for(auto str:strs)
        {
            ones=count(str,'1');
            zeros=count(str,'0');
            for(int i=m;i>=zeros;i--)
            {
                for(int j=n;j>=ones;j--)
                {
                    dp[i][j]=max(dp[i][j],dp[i-zeros][j-ones]+1);
                }
            }
        }
        return dp[m][n];
    }
    int count(string &str, char c){
        int res = 0;
        for(auto s: str){
            if(s==c) ++res;
        }
        return res;
    }
};