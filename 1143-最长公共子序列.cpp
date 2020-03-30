//dp[i][j]==dp[i-1][j-1]+1 if text1[i]==text2[j]
//dp[i][j]==max(dp[i-1][j],dp[i][j-1])
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size(),n=text2.size();
        vector<int>cur(n+1,0);
        int pre=0;
        for(int i=1;i<=m;i++)
        {
            pre=cur[0];
            for(int j=1;j<=n;j++)
            {
                int temp=cur[j];
                if(text1[i-1]==text2[j-1])     
                {
                    cur[j]=pre+1;
                }
                else
                {
                    cur[j]=max(cur[j],cur[j-1]);
                }  
                pre=temp;     
            }
        }
        return cur[n];
    }
};