//pay attention to  dp[i][j] must behind dp[i+1][j-1] is know 
class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<bool>>dp(s.size(),vector<bool>(s.size(),false));
        int maxlen=1,l=0,r=0;
        for(int i=0;i<s.size();i++)
        {
            dp[i][i]=true;
        }
        for(int end=0;end<s.size();end++)
        {
            for(int start=0;start<end;start++)
            {
                int len=end-start+1;
                dp[start][end]=(s[start]==s[end])&&(len<=2||dp[start+1][end-1]);
                if(dp[start][end]&&(end-start+1)>maxlen)
                {
                    maxlen=end-start+1;
                    l=start;
                    r=end;
                }
            }
        }
        return s.substr(l,maxlen);  
    }
};