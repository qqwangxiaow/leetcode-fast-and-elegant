//pre2 decode ways of s[i-2] , pre1: decode ways of s[i-1] 
class Solution {
public:
    int numDecodings(string s) {
        if(s.empty()||s[0]=='0')
            return 0;
        int pre1=1,pre2=1;
        for(int i=1;i<s.size();i++)
        {
            if(s[i]=='0')
                pre1=0;
            if (s[i-1]=='1'||s[i-1]=='2'&&s[i]<='6')
            {
                pre1=pre1+pre2;
                pre2=pre1-pre2;  //pre2=pre1 old
            }
            else
                pre2=pre1;
        }
        return pre1;
    }
};
//pay attention to 0
class Solution {
public:
    int numDecodings(string s) {
        if(s.empty()||s[0]=='0')
            return 0;
        vector<int>dp(s.size(),1);
        for(int i=1;i<s.size();i++)
        {
            if(s[i]=='0')
                dp[i]=0;
            else
                dp[i]=dp[i-1];
            if(s[i-1]=='1'||(s[i-1]=='2'&&s[i]<='6'))
                dp[i]+=i-2>=0?dp[i-2]:1;
        }
        return dp[s.size()-1];
    }
};

