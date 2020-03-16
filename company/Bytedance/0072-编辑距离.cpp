//不难
//dp[i][j]=min(dp[i-1][j-1],dp[i-1][j],dp[i][j-1])+1
class Solution {
public:
    int minDistance(string word1, string word2) {
        int pre=0;
        vector<int>cur(word2.size()+1,0);
        for (int i = 1; i <=word2.size(); i++) {
            cur[i]=i;
        }
        for(int i=1;i<=word1.size();i++)
        {
            pre=cur[0];
            cur[0]=i;
            for(int j=1;j<=word2.size();j++)
            {
                int temp=cur[j];
                if(word1[i-1]==word2[j-1])
                {
                    cur[j]=pre;
                }
                else
                {
                    cur[j]=min(pre,min(cur[j],cur[j-1]))+1;
                }
                pre=temp;
            }
        }
        return cur[word2.size()];
    }
};