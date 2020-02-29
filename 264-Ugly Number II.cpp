//like merge 3 array
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>dp(n,1);
        int indexof2=0,indexof3=0,indexof5=0;
        for(int i=1;i<n;i++)
        {
            dp[i]=min(dp[indexof2]*2,min(dp[indexof3]*3,dp[indexof5]*5));
            if(dp[i]==dp[indexof2]*2)
                indexof2++;
            if(dp[i]==dp[indexof3]*3)
                indexof3++;
            if(dp[i]==dp[indexof5]*5)
                indexof5++;
        }
        return dp[n-1];
    }
};
