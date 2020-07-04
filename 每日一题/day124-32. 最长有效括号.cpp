//conside dp[i-dp[i-1]-1]
//add dp[i-dp[i-1]-2]
class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.empty())
            return 0;
        vector<int>dp(s.size(),0);
        for(int i=1;i<s.size();i++)
        {
            if(s[i]=='(')
                continue;
            else
            {
                if(s[i-1]=='(')
                    dp[i]=i-2>0?dp[i-2]+2:2;
                else if(i-dp[i-1]-1>=0&&s[i-dp[i-1]-1]=='(')
                {
                    if(i-dp[i-1]-2>=0)
                    {
                        dp[i]=dp[i-1]+2+dp[i-dp[i-1]-2];
                    }
                    else
                    {
                        dp[i]=dp[i-1]+2;
                    }
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};