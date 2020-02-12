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
//more clear dp[i][j] means s[i..j]
class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<int>>dp(s.size(),vector<int>(s.size(),0));
        int count=0;
        for(int j=0;j<s.size();j++)
        {
            for(int i=j;i>=0;i--)
            {
                if(s[i]==s[j]&&(j-i<2||dp[i+1][j-1]))
                {
                    dp[i][j]=1;
                    count++;
                }
            }
        }
        return count;
    }
};

//extend
class Solution {
public:
    int countSubstrings(string s) {
       for(int i=0;i<s.size();i++)
       {
           extendFromCenter(s,i,i);
           extendFromCenter(s,i,i+1);
       }
        return count;
    }
    void extendFromCenter(string s,int start,int end)
    {
        int len=s.size();
        while(start>=0&&end<len&&s[start]==s[end])
        {
            start--;
            end++;
            count++;
        }
    }
private:
    int count=0;
};