class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        unordered_set<string>myset(wordDict.begin(),wordDict.end());
        vector<int>dp(s.size()+1,0);
        dp[0]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(dp[j]&&myset.count(s.substr(j,i-j)))
                {
                    dp[i]=1;
                    break;
                }
            }
        }
        return dp[n];

    }
};