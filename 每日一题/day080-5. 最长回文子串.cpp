class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        int left=0,maxlen=1;
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int i=0;i<s.size();i++)
        {
            dp[i][i]=1;
            for(int j=0;j<i;j++)
            {
                if(s[i]==s[j]&&((i-j)<=2||dp[j+1][i-1]))
                {
                    dp[j][i]=1;
                    if(i-j+1>maxlen)
                    {
                        left=j;
                        maxlen=i-j+1;
                    }
                }
            }
        }
        return s.substr(left,maxlen);
    }
};