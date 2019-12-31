//dp
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>>dp(text1.size()+1,vector<int>(text2.size()+1,0));
        for(int i=1;i<=text1.size();i++)
        {
            for(int j=1;j<=text2.size();j++)
            {
                if(text1[i-1]==text2[j-1])
                {
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[text1.size()][text2.size()];
        
    }
};
//two vector
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<int>cur(text2.size()+1);
        vector<int>pre(text2.size()+1);
        for(int i=1;i<=text1.size();i++)
        {
            for(int j=1;j<=text2.size();j++)
            {
                if(text1[i-1]==text2[j-1])
                {
                    cur[j]=pre[j-1]+1;
                }
                else
                {
                    cur[j]=max(pre[j],cur[j-1]);
                }
                
            }
            fill(pre.begin(),pre.end(),0);
            swap(cur,pre);
        }
        return pre[text2.size()];
        
    }
};
//pre=dp[i-1][j-1]
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<int>cur(text2.size()+1,0);
        for(int i=1;i<=text1.size();i++)
        {
            int pre=0;
            for(int j=1;j<=text2.size();j++)
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
        return cur[text2.size()];
        
    }
};