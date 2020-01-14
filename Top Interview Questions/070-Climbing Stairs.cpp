//opt dp
class Solution {
public:
    int climbStairs(int n) {
        if(n<=2)
            return n;
        int pre1=1,pre2=2,ret=0;
        for(int i=3;i<=n;i++)
        {
            ret=pre1+pre2;
            pre1=pre2;
            pre2=ret;
        }
        return ret;
    }
};