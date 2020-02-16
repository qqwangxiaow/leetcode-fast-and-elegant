//ret should be long and mod
class Solution {
public:
    int cuttingRope(int n) {
        if(n==2)
            return 1;
        if(n==3)
            return 2;
        int count3=0;
        while(n>4)
        {
            count3++;
            n-=3;
        }
        long ret=n;
        while(count3--)
        {
            ret=(3*ret)%1000000007;
        }
        return ret;
    }
};