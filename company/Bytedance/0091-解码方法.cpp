//s[i]=='0'  dp[i]=dp[i-2]
//s[i-1]=='1'||'2 <7' dp[i]=dp[i-1]+dp[i-2]
//s[i]==other dp[i]=dp[i-1]
class Solution {
public:
    int numDecodings(string s) {
        if(s.empty())
            return 0;
        vector<int>dp(s.size(),0);
        if(s[0]=='0')
            return 0;
        dp[0]=1;
        for(int i=1;i<s.size();i++)
        {
            if(s[i]=='0')
            {
                if(s[i-1]=='1'||s[i-1]=='2')
                {
                    if(i>1)
                        dp[i]=dp[i-2];
                    else
                        dp[i]=1;
                }  
                else   
                    return 0;
            }
            else if(s[i-1]=='1'||(s[i-1]=='2'&&s[i]<'7'))
            {
                if(i>1)
                    dp[i]=dp[i-1]+dp[i-2];
                else    
                    dp[i]=dp[i-1]+1;
            }
            else
            {
                dp[i]=dp[i-1];
            }
        }
        return dp[s.size()-1];

    }
};