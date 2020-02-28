//str[i-2]==‘0’的时候只能算一种
class Solution {
public:
    int translateNum(int num) {
        string str=to_string(num);
        vector<int>dp(str.size()+1,1);
        for(int i=2;i<=str.size();i++)
        {
            if((str[i-2]=='1')||(str[i-1]<'6'&&str[i-2]=='2'))
                dp[i]=dp[i-1]+dp[i-2];
            else
                dp[i]=dp[i-1];
        }
        return dp[str.size()];

    }
};