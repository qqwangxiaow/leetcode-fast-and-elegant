//A：{1*2，2*2，3*2，4*2，5*2，6*2，8*2，10*2......}
//B：{1*3，2*3，3*3，4*3，5*3，6*3，8*3，10*3......}
//C：{1*5，2*5，3*5，4*5，5*5，6*5，8*5，10*5......}
//相当于3个数组合并去重复
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
]