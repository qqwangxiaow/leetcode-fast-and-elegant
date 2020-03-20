//add pre part
//if(i-dp[i-1]-2>=0) dp[i]=dp[i-1]+2+dp[i-dp[i-1]-2];

class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.empty())
            return 0;
        int len=s.size();
        vector<int>dp(len,0);
        for(int i=1;i<s.size();i++)
        {
            if(s[i]==')')
            {
                if(s[i-1]=='(')
                    dp[i]=i-2>0?dp[i-2]+2:2;
                else if((i-dp[i-1]-1)>=0&&s[i-dp[i-1]-1]=='(')
                {
                    if(i-dp[i-1]-2>=0)
                    {
                        dp[i]=dp[i-1]+2+dp[i-dp[i-1]-2];
                    }
                    else
                        dp[i]=dp[i-1]+2;
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};