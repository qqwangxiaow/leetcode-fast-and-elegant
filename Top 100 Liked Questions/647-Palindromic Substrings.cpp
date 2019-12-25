//dp   for len=1 to maxsize, for start =end-1 to 0
class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<bool>>dp(s.size(),vector<bool>(s.size(),true));
        int count=s.size();
        for(int start=s.size()-1;start>=0;start--) // for state[i][j], state[i+1][j-1] is its subproblem. So we need to calculate state[i+1][j-1] before state[i][j]. That's why i has to be decreasing.
        {
            for(int len=1;start+len<s.size();len++)
            {
                int end=start+len;
                if(s[start]==s[end]&&(len==1||dp[start+1][end-1]))
                {
                    count++;
                }
                else
                {
                    dp[start][end]=false;
                }
            }
        }
        return count;
    }
};