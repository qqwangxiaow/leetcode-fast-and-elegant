/*dp[j][i]表示j~i可以,关键1 dp[i][i]初值1,关键2 i-j<2 */
class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        int l=0,maxlen=1;
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int i=0;i<n;i++)
        {
            dp[i][i]=1;
            for(int j=0;j<i;j++)
            {
                dp[j][i]=(s[i]==s[j])&&(dp[j+1][i-1]||i-j<2);
                if(dp[j][i]&&i-j+1>maxlen)
                {
                    maxlen=i-j+1;
                    l=j;
                }
            }
        }
        return s.substr(l,maxlen);
    }
};

/*运用extend的思想,分奇数偶数,选一个位置进行extend成最长回文串,记录maxlen和起始left */

class Solution {
public:
    string longestPalindrome(string s) {
        int len=s.size();
        if(len<2)
            return s;
        for(int i=0;i<s.size();i++)
        {
            extendstring(s,i,i);
            extendstring(s,i,i+1);
        }
        return s.substr(l,maxlen);        
        
    }a
    void extendstring(string s,int j,int k)
    {
        if(s[j]!=s[k])
            return;
        while(j>0&&k<s.size()-1&&s[j-1]==s[k+1])
        {
            j--;a
            k++;
        }
         if(k-j+1>maxlen)
        {
            maxlen=k-j+1;
            l=j;
        }
    }
private:
    int l=0,maxlen=0;
};
/*神仙做法 */
class Solution {
public:
    string longestPalindrome(string s) 
    {
        string T;// Transform S to T
        for(int i=0;i<s.size();i++)
            T+="#"+s.substr(i,1);
        T.push_back('#');

        vector<int> P(T.size(),0); // Array to record longest palindrome
        int center=0,boundary=0,maxLen=0,resCenter=0;
        for(int i=1;i<T.size()-1;i++) {
            int iMirror=2*center-i; // calc mirror i = center-(i-center)
            P[i]=(boundary>i)?min(boundary-i,P[iMirror]):0; // shortcut
            while(i-1-P[i]>=0&&i+1+P[i]<=T.size()-1&&T[i+1+P[i]] == T[i-1-P[i]]) // Attempt to expand palindrome centered at i
                P[i]++;
            if(i+P[i]>boundary) { // update center and boundary
                center = i;
                boundary = i+P[i];
            }
            if(P[i]>maxLen) { // update result
                maxLen = P[i];
                resCenter = i;
            }    
        }
        return s.substr((resCenter - maxLen)/2, maxLen);
    }
};