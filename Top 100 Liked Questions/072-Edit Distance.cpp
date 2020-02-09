/*dp[i][j]=min(dp[i-1][j],dp[i][j-1]) min dp[i-1][j-1]
dp[i-1][j-1]:replace word[i] to word[j]
dp[i-1][j]:delete word1[i-1]
dp[i][j-1]:insert word2[j-1]
If word1[i - 1] != word2[j - 1], we need to consider three cases.

Replace word1[i - 1] by word2[j - 1] (dp[i][j] = dp[i - 1][j - 1] + 1);
If word1[0..i - 1) = word2[0..j) then delete word1[i - 1] (dp[i][j] = dp[i - 1][j] + 1);
If word1[0..i) + word2[j - 1] = word2[0..j) then insert word2[j - 1] to word1[0..i) (dp[i][j] = dp[i][j - 1] + 1).
*/
//basic
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            dp[i][0] = i;
        }
        for (int j = 1; j <= n; j++) {
            dp[0][j] = j;
        }
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(word1[i-1]==word2[j-1])
                {
                    dp[i][j]=dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]))+1;
                }
            }
        }
        return dp[m][n];
        
    }
};
//two vector
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<int>cur(n+1,0),pre(n+1,0);
        for (int i = 1; i <= n; i++) {
            pre[i]=i;
        }
        for(int i=1;i<=m;i++)
        {
            cur[0]=i;
            for(int j=1;j<=n;j++)
            {
                if(word1[i-1]==word2[j-1])
                {
                    cur[j]=pre[j-1];
                }
                else
                {
                    cur[j]=min(pre[j-1],min(cur[j-1],pre[j]))+1;
                }
            }
            fill(pre.begin(),pre.end(),0);
            swap(pre,cur);
        }
        return pre[n];
        
    }
};

//one vector
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size(),pre;
        vector<int>cur(n+1,0);
        for (int i = 1; i <= n; i++) {
            cur[i]=i;
        }
        for(int i=1;i<=m;i++)
        {
            pre=cur[0];
            cur[0]=i;
            for(int j=1;j<=n;j++)
            {
                int temp=cur[j];
                if(word1[i-1]==word2[j-1])
                {
                    cur[j]=pre;
                }
                else
                {
                    cur[j]=min(pre,min(cur[j-1],cur[j]))+1;
                }
                pre=temp;
            }
        }
        return cur[n];
    }
};